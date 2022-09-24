/*
 *******************************************************************************
 * File:			acnv.c
 * Date:			2022-04-17
 * Author:			Phillip Durdaut
 * Summary:			Functions for controlling the ACNV board
 * Notes:			-
 *******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "acnv.h"
#include "max4820.h"

/* Private typedefs ----------------------------------------------------------*/
/* Private defines -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
ACNV_INPUT_TYPE_t ACNV_InputType[2] = { ACNV_INPUT_TYPE_INT, ACNV_INPUT_TYPE_EXT };
ACNV_INPUT_TYPE_t ACNV_ChassisConnection = ACNV_CHASSIS_CONNECTION_FLOAT;

/* Private function prototypes -----------------------------------------------*/

/* Program code --------------------------------------------------------------*/

extern void ACNV_Init(void)
{
	ACNV_SetInputType(ACNV_CHANNEL_1, ACNV_INPUT_TYPE_EXT);
	ACNV_SetInputType(ACNV_CHANNEL_2, ACNV_INPUT_TYPE_EXT);
	ACNV_SetChassisConnection(ACNV_CHASSIS_CONNECTION_GND);
}

extern ACNV_INPUT_TYPE_t ACNV_GetInputType(ACNV_CHANNEL_t channel)
{
	return ACNV_InputType[channel];
}

extern void ACNV_SetInputType(ACNV_CHANNEL_t channel, ACNV_INPUT_TYPE_t input_type)
{
	if (channel == ACNV_CHANNEL_1) {

		if (input_type == ACNV_INPUT_TYPE_INT)
			MAX4820_SetRelay(MAX4820_DEVICE_ACNV, MAX4820_RELAY_1);
		else if (input_type == ACNV_INPUT_TYPE_EXT)
			MAX4820_SetRelay(MAX4820_DEVICE_ACNV, MAX4820_RELAY_0);
	}
	else if (channel == ACNV_CHANNEL_2) {

		if (input_type == ACNV_INPUT_TYPE_INT)
			MAX4820_SetRelay(MAX4820_DEVICE_ACNV, MAX4820_RELAY_3);
		else if (input_type == ACNV_INPUT_TYPE_EXT)
			MAX4820_SetRelay(MAX4820_DEVICE_ACNV, MAX4820_RELAY_2);
	}

	ACNV_InputType[channel] = input_type;
}

extern uint8_t * ACNV_GetInputTypeString(ACNV_CHANNEL_t channel)
{
	if (ACNV_GetInputType(channel) == ACNV_INPUT_TYPE_INT)
		return ((uint8_t *)"INT\n");
	else if (ACNV_GetInputType(channel) == ACNV_INPUT_TYPE_EXT)
		return ((uint8_t *)"EXT\n");

	return NULL;
}

extern ACNV_CHASSIS_CONNECTION_t ACNV_GetChassisConnection(void)
{
	return ACNV_ChassisConnection;
}

extern void ACNV_SetChassisConnection(ACNV_CHASSIS_CONNECTION_t chassis_connection)
{
	if (chassis_connection == ACNV_CHASSIS_CONNECTION_FLOAT)
		MAX4820_SetRelay(MAX4820_DEVICE_ACNV, MAX4820_RELAY_5);
	else if (chassis_connection == ACNV_CHASSIS_CONNECTION_GND)
		MAX4820_SetRelay(MAX4820_DEVICE_ACNV, MAX4820_RELAY_4);

	ACNV_ChassisConnection = chassis_connection;
}

extern uint8_t * ACNV_GetChassisConnectionString(void)
{
	if (ACNV_GetChassisConnection() == ACNV_CHASSIS_CONNECTION_FLOAT)
		return ((uint8_t *)"FLOAT\n");
	else if (ACNV_GetChassisConnection() == ACNV_CHASSIS_CONNECTION_GND)
		return ((uint8_t *)"GND\n");

	return NULL;
}
