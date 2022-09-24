/*
 *******************************************************************************
 * File:			max4820.c
 * Date:			2022-04-17
 * Author:			Phillip Durdaut
 * Summary:			Functions for controlling a MAX4820 relay driver
 * Notes:			-
 *******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "max4820.h"
#include "spi.h"

/* Private typedefs ----------------------------------------------------------*/
/* Private defines -----------------------------------------------------------*/
#define MAX4820_RESET_PULSE_LENGTH_MS							1
#define MAX4820_STARTUP_TIME_AFTER_RESET_MS						10
#define MAX4820_RELAY_PULSE_TIME_MS								100

/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void MAX4820_Reset(void);
void MAX4820_ChipSelect(void);
void MAX4820_ChipUnselect(void);
void MAX4820_SPIWrite(uint8_t data);

/* Program code --------------------------------------------------------------*/

extern void MAX4820_Init(void)
{
	/* Configure pins */
	TCA9534A_SetPinType(RD_NRESET_DEVICE, RD_NRESET_PIN, TCA9534A_PINTYPE_OUTPUT);
	TCA9534A_SetPinType(RD_NCS_DEVICE, RD_NCS_PIN, TCA9534A_PINTYPE_OUTPUT);

	/* Set standard voltage levels of output pins */
	TCA9534A_SetPinState(RD_NRESET_DEVICE, RD_NRESET_PIN, GPIO_PIN_SET);
	TCA9534A_SetPinState(RD_NCS_DEVICE, RD_NCS_PIN, GPIO_PIN_SET);

	/* Reset */
	MAX4820_Reset();
}

extern void MAX4820_SetRelay(MAX4820_DEVICE_t device, MAX4820_RELAY_t relay)
{
	if (device == MAX4820_DEVICE_ACNV) {

		switch (relay) {
			case MAX4820_RELAY_0: MAX4820_SPIWrite(0b00000001); break;
			case MAX4820_RELAY_1: MAX4820_SPIWrite(0b00000010);	break;
			case MAX4820_RELAY_2: MAX4820_SPIWrite(0b00000100);	break;
			case MAX4820_RELAY_3: MAX4820_SPIWrite(0b00001000);	break;
			case MAX4820_RELAY_4: MAX4820_SPIWrite(0b00010000);	break;
			case MAX4820_RELAY_5: MAX4820_SPIWrite(0b00100000);	break;
			case MAX4820_RELAY_6: MAX4820_SPIWrite(0b01000000);	break;
			case MAX4820_RELAY_7: MAX4820_SPIWrite(0b10000000);	break;

			default: MAX4820_SPIWrite(0b00000000);
		}
	}

	HAL_Delay(MAX4820_RELAY_PULSE_TIME_MS);
	MAX4820_SPIWrite(0b00000000);
}

extern void MAX4820_Reset(void)
{
	TCA9534A_SetPinState(RD_NRESET_DEVICE, RD_NRESET_PIN, GPIO_PIN_RESET);
	HAL_Delay(MAX4820_RESET_PULSE_LENGTH_MS);
	TCA9534A_SetPinState(RD_NRESET_DEVICE, RD_NRESET_PIN, GPIO_PIN_SET);
	HAL_Delay(MAX4820_STARTUP_TIME_AFTER_RESET_MS);
}

void MAX4820_ChipSelect(void)
{
	/* Initialize SPI3 */
	SPI_Init(SPI_3, SPI_DATA_SIZE_8BIT);

	TCA9534A_SetPinState(RD_NCS_DEVICE, RD_NCS_PIN, GPIO_PIN_RESET);
}

void MAX4820_ChipUnselect(void)
{
	TCA9534A_SetPinState(RD_NCS_DEVICE, RD_NCS_PIN, GPIO_PIN_SET);
}

void MAX4820_SPIWrite(uint8_t data)
{
	MAX4820_ChipSelect();
	SPI_Write_8bit(SPI_3, data);
	MAX4820_ChipUnselect();
}
