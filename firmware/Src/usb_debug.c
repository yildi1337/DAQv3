/*
 *******************************************************************************
 * File:			usb_debug.c
 * Date:			2020-11-03
 * Author:			Phillip Durdaut
 * Summary:			Functions for communicating over the USB debug interface
 * Notes:			-
 *******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usb_debug.h"
#include "uart.h"
#include "acnv.h"

/* Private typedefs ----------------------------------------------------------*/
/* Private defines -----------------------------------------------------------*/
#define USB_DEBUG_MAX_COMMAND_LENGTH_BYTES				128

/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
USB_DEBUG_COMMAND_t USB_DEBUG_Command = USB_DEBUG_COMMAND_NONE;
uint8_t USB_DEBUG_ParameterBuffer[USB_DEBUG_MAX_COMMAND_LENGTH_BYTES] = { 0 };

/* Private function prototypes -----------------------------------------------*/
bool USB_DEBUG_CheckCommand(const char * pCommand);
void USB_DEBUG_UpdateParameterBuffer(void);
uint8_t USB_DEBUG_CommandPreSpaceCharToUInt8(void);

/* Program code --------------------------------------------------------------*/

extern void USB_DEBUG_Init(void)
{
	return;
}

extern void USB_DEBUG_TransmitString(uint8_t * pBuffer)
{
	UART_TransmitData(UART_1, pBuffer, strlen((const char *)pBuffer));
}

extern void USB_DEBUG_TransmitFloat(float data)
{
	char str[32];
	sprintf(str, "%.3f\n", data);
	USB_DEBUG_TransmitString((uint8_t *)str);
}

extern void USB_DEBUG_WelcomeScreen(void)
{
	USB_DEBUG_ClearTerminal();
	USB_DEBUG_TransmitString((uint8_t *)"----------------------------------------------------------------------------------\n");
	USB_DEBUG_TransmitString((uint8_t *)"							DAQ v3 USB Debug Interface							\n");
	USB_DEBUG_TransmitString((uint8_t *)"									 pd, 2022									 \n");
	USB_DEBUG_TransmitString((uint8_t *)"----------------------------------------------------------------------------------\n");
	USB_DEBUG_TransmitString((uint8_t *)"  System reset:													SYSTEM_RESET;  \n");
	USB_DEBUG_TransmitString((uint8_t *)"  Get this list of commands:									   GET_COMMANDS;  \n");
	USB_DEBUG_TransmitString((uint8_t *)"																				  \n");
	USB_DEBUG_TransmitString((uint8_t *)"  [ACNV] Get input type CH 1 [INT / EXT]:			   ACNV_GET_INPUT_TYPE_CH1;  \n");
	USB_DEBUG_TransmitString((uint8_t *)"  [ACNV] Get input type CH 2 [INT / EXT]:			   ACNV_GET_INPUT_TYPE_CH2;  \n");
	USB_DEBUG_TransmitString((uint8_t *)"  [ACNV] Set input type CH 1 [INT / EXT]:			 ACNV_SET_INPUT_TYPE_CH1 x;  \n");
	USB_DEBUG_TransmitString((uint8_t *)"  [ACNV] Set input type CH 2 [INT / EXT]:			 ACNV_SET_INPUT_TYPE_CH2 x;  \n");
	USB_DEBUG_TransmitString((uint8_t *)"  [ACNV] Get chassis connection [FLOAT / GND]:	  ACNV_GET_CHASSIS_CONNECTION;  \n");
	USB_DEBUG_TransmitString((uint8_t *)"  [ACNV] Set chassis connection [FLOAT / GND]:	ACNV_SET_CHASSIS_CONNECTION x;  \n");
	USB_DEBUG_TransmitString((uint8_t *)"----------------------------------------------------------------------------------\n");
}

extern void USB_DEBUG_ClearTerminal(void)
{
	USB_DEBUG_TransmitString((uint8_t *)"\n");
	USB_DEBUG_TransmitString((uint8_t *)"\n");
	USB_DEBUG_TransmitString((uint8_t *)"\n");
	USB_DEBUG_TransmitString((uint8_t *)"\n");
	USB_DEBUG_TransmitString((uint8_t *)"\n");
}

extern bool USB_DEBUG_CommandAvailable(void)
{
	UART_UART1_RECEIVED_COMMAND_t * pReceivedCommandStruct = GetReferenceOnReceivedCommandStruct(UART_1);

	if (pReceivedCommandStruct->available == true && pReceivedCommandStruct->acknowledged == false)
		return true;
	else
		return false;
}

extern USB_DEBUG_COMMAND_t USB_DEBUG_GetCommand(void)
{
	USB_DEBUG_Command = USB_DEBUG_COMMAND_NONE;

	if (USB_DEBUG_CommandAvailable())
	{
		if (USB_DEBUG_CheckCommand("GET_COMMANDS;"))
			USB_DEBUG_Command = USB_DEBUG_COMMAND_GET_COMMANDS;

		else if (USB_DEBUG_CheckCommand("SYSTEM_RESET;"))
			USB_DEBUG_Command = USB_DEBUG_COMMAND_SYSTEM_RESET;

		else if (USB_DEBUG_CheckCommand("ACNV_GET_INPUT_TYPE_CH1;"))
			USB_DEBUG_Command = USB_DEBUG_COMMAND_ACNV_GET_INPUT_TYPE_CH1;
		else if (USB_DEBUG_CheckCommand("ACNV_GET_INPUT_TYPE_CH2;"))
			USB_DEBUG_Command = USB_DEBUG_COMMAND_ACNV_GET_INPUT_TYPE_CH2;

		else if (USB_DEBUG_CheckCommand("ACNV_SET_INPUT_TYPE_CH"))
		{
			if (USB_DEBUG_CommandPreSpaceCharToUInt8() == 1)
				USB_DEBUG_Command = USB_DEBUG_COMMAND_ACNV_SET_INPUT_TYPE_CH1;
			else if (USB_DEBUG_CommandPreSpaceCharToUInt8() == 2)
				USB_DEBUG_Command = USB_DEBUG_COMMAND_ACNV_SET_INPUT_TYPE_CH2;
			else
				USB_DEBUG_Command = USB_DEBUG_COMMAND_NONE;
		}

		else if (USB_DEBUG_CheckCommand("ACNV_GET_CHASSIS_CONNECTION;"))
			USB_DEBUG_Command = USB_DEBUG_COMMAND_ACNV_GET_CHASSIS_CONNECTION;
		else if (USB_DEBUG_CheckCommand("ACNV_SET_CHASSIS_CONNECTION"))
			USB_DEBUG_Command = USB_DEBUG_COMMAND_ACNV_SET_CHASSIS_CONNECTION;

		else
		{
			/* Acknowledge not supported command to reactivate the receiver */
			USB_DEBUG_AcknowledgeCommand();
		}
	}

	return USB_DEBUG_Command;
}

extern void USB_DEBUG_AcknowledgeCommand(void)
{
	UART_UART1_RECEIVED_COMMAND_t * pReceivedCommandStruct = GetReferenceOnReceivedCommandStruct(UART_1);

	pReceivedCommandStruct->available = false;
	pReceivedCommandStruct->acknowledged = true;

	USB_DEBUG_Command = USB_DEBUG_COMMAND_NONE;
}

extern ACNV_INPUT_TYPE_t USB_DEBUG_GetParameterAsAcnvInputType(void)
{
	USB_DEBUG_UpdateParameterBuffer();

	if (strcmp((const char *)USB_DEBUG_ParameterBuffer, "INT") == 0)
		return ACNV_INPUT_TYPE_INT;
	else
		return ACNV_INPUT_TYPE_EXT;
}

extern ACNV_CHASSIS_CONNECTION_t USB_DEBUG_GetParameterAsAcnvChassisConnection(void)
{
	USB_DEBUG_UpdateParameterBuffer();

	if (strcmp((const char *)USB_DEBUG_ParameterBuffer, "FLOAT") == 0)
		return ACNV_CHASSIS_CONNECTION_FLOAT;
	else
		return ACNV_CHASSIS_CONNECTION_GND;
}

bool USB_DEBUG_CheckCommand(const char * pCommand)
{
	UART_UART1_RECEIVED_COMMAND_t * pReceivedCommandStruct = GetReferenceOnReceivedCommandStruct(UART_1);

	/* Compare received string with given command string */
	if (strncmp((const char *)pReceivedCommandStruct->command, pCommand, strlen(pCommand)) == 0)
		return true;
	else
		return false;
}

void USB_DEBUG_UpdateParameterBuffer(void)
{
	UART_UART1_RECEIVED_COMMAND_t * pReceivedCommandStruct = GetReferenceOnReceivedCommandStruct(UART_1);
	char * pCommand = (char *)pReceivedCommandStruct->command;
	char * pSpace = NULL;
	char * pSemicolon = NULL;

	for (uint8_t i = 0; i < USB_DEBUG_MAX_COMMAND_LENGTH_BYTES; i++)
	{
		if (pCommand[i] == ' ')
			pSpace = &(pCommand[i]);

		if (pCommand[i] == ';')
		{
			pSemicolon = &(pCommand[i]);
			break;
		}
	}
	uint8_t length = pSemicolon - pSpace - 1;


	for (uint8_t i = 0; i < USB_DEBUG_MAX_COMMAND_LENGTH_BYTES; i++)
	{
		if (i < length)
			USB_DEBUG_ParameterBuffer[i] = pSpace[i+1];
		else
			USB_DEBUG_ParameterBuffer[i] = 0;
	}
}

uint8_t USB_DEBUG_CommandPreSpaceCharToUInt8(void)
{
	UART_UART1_RECEIVED_COMMAND_t * pReceivedCommandStruct = GetReferenceOnReceivedCommandStruct(UART_1);
	char * pCommand = (char *)pReceivedCommandStruct->command;
	char * pPreSpace = NULL;

	for (uint8_t i = 0; i < USB_DEBUG_MAX_COMMAND_LENGTH_BYTES; i++)
	{
		if (pCommand[i] == ' ')
		{
			pPreSpace = &(pCommand[i-1]);
			break;
		}
	}

	return (uint8_t)atoi((const char*)pPreSpace);
}

