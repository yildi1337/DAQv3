/*
 *******************************************************************************
 * File:			tca9534a.c
 * Date:			2022-04-11
 * Author:			Phillip Durdaut
 * Summary:			Functions for controlling a TCA9534A I/O expander via I2C
 * Notes:			-
 *******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tca9534a.h"
#include "i2c.h"

/* Private typedefs ----------------------------------------------------------*/
struct TCA9534A_DeviceConfig {
	TCA9534A_PINTYPE_t pintype[TCA9534A_NUMBER_OF_PINS];
	GPIO_PinState outputLevel[TCA9534A_NUMBER_OF_PINS];
};

/* Private defines -----------------------------------------------------------*/
#define TCA9534A_I2C_SLAVE_ADDRESS				(0x38 << 1)
#define TCA9534A_CONTROL_INPUT_PORT				0x00
#define TCA9534A_CONTROL_OUTPUT_PORT			0x01
#define TCA9534A_CONTROL_POLYRITY_INVERSION		0x02
#define TCA9534A_CONTROL_CONFIGURATION			0x03

/* Private macros ------------------------------------------------------------*/
#define TCA9534A_I2C_WRITE(x)			(0xFE & x)
#define TCA9534A_I2C_READ(x)			(0x01 | x)

/* Private variables ---------------------------------------------------------*/
struct TCA9534A_DeviceConfig TCA9534A_DeviceConfig_ACNV;

/* Private function prototypes -----------------------------------------------*/
void MAX4820_Reset(void);
void MAX4820_I2CWrite(uint8_t data);

/* Program code --------------------------------------------------------------*/

extern void TCA9534A_Init(void)
{
	/* Initialization in individual modules */
}

extern void TCA9534A_SetPinType(TCA9534A_DEVICE_t device, TCA9534A_PIN_t pin, TCA9534A_PINTYPE_t pintype)
{
	uint8_t data_tx[2];

	if (device == TCA9534A_DEVICE_ACNV) {

		TCA9534A_DeviceConfig_ACNV.pintype[pin] = pintype;

		data_tx[0] = TCA9534A_CONTROL_CONFIGURATION;
		data_tx[1] = 0x00;

		if (TCA9534A_DeviceConfig_ACNV.pintype[TCA9534A_PIN_0] == TCA9534A_PINTYPE_INPUT)
			data_tx[1] |= (0x01 << 0);
		if (TCA9534A_DeviceConfig_ACNV.pintype[TCA9534A_PIN_1] == TCA9534A_PINTYPE_INPUT)
			data_tx[1] |= (0x01 << 1);
		if (TCA9534A_DeviceConfig_ACNV.pintype[TCA9534A_PIN_2] == TCA9534A_PINTYPE_INPUT)
			data_tx[1] |= (0x01 << 2);
		if (TCA9534A_DeviceConfig_ACNV.pintype[TCA9534A_PIN_3] == TCA9534A_PINTYPE_INPUT)
			data_tx[1] |= (0x01 << 3);
		if (TCA9534A_DeviceConfig_ACNV.pintype[TCA9534A_PIN_4] == TCA9534A_PINTYPE_INPUT)
			data_tx[1] |= (0x01 << 4);
		if (TCA9534A_DeviceConfig_ACNV.pintype[TCA9534A_PIN_5] == TCA9534A_PINTYPE_INPUT)
			data_tx[1] |= (0x01 << 5);
		if (TCA9534A_DeviceConfig_ACNV.pintype[TCA9534A_PIN_6] == TCA9534A_PINTYPE_INPUT)
			data_tx[1] |= (0x01 << 6);
		if (TCA9534A_DeviceConfig_ACNV.pintype[TCA9534A_PIN_7] == TCA9534A_PINTYPE_INPUT)
			data_tx[1] |= (0x01 << 7);

		HAL_I2C_Master_Transmit(I2C_GetHandle(I2C_4), TCA9534A_I2C_WRITE(TCA9534A_I2C_SLAVE_ADDRESS), (uint8_t *)data_tx, 2, 100);
	}
}

extern void TCA9534A_SetPinState(TCA9534A_DEVICE_t device, TCA9534A_PIN_t pin, GPIO_PinState state)
{
	uint8_t data_tx[2];

	if (device == TCA9534A_DEVICE_ACNV) {

		TCA9534A_DeviceConfig_ACNV.outputLevel[pin] = state;

		data_tx[0] = TCA9534A_CONTROL_OUTPUT_PORT;
		data_tx[1] = 0x00;

		if (TCA9534A_DeviceConfig_ACNV.outputLevel[TCA9534A_PIN_0] == GPIO_PIN_SET)
			data_tx[1] |= (0x01 << 0);
		if (TCA9534A_DeviceConfig_ACNV.outputLevel[TCA9534A_PIN_1] == GPIO_PIN_SET)
			data_tx[1] |= (0x01 << 1);
		if (TCA9534A_DeviceConfig_ACNV.outputLevel[TCA9534A_PIN_2] == GPIO_PIN_SET)
			data_tx[1] |= (0x01 << 2);
		if (TCA9534A_DeviceConfig_ACNV.outputLevel[TCA9534A_PIN_3] == GPIO_PIN_SET)
			data_tx[1] |= (0x01 << 3);
		if (TCA9534A_DeviceConfig_ACNV.outputLevel[TCA9534A_PIN_4] == GPIO_PIN_SET)
			data_tx[1] |= (0x01 << 4);
		if (TCA9534A_DeviceConfig_ACNV.outputLevel[TCA9534A_PIN_5] == GPIO_PIN_SET)
			data_tx[1] |= (0x01 << 5);
		if (TCA9534A_DeviceConfig_ACNV.outputLevel[TCA9534A_PIN_6] == GPIO_PIN_SET)
			data_tx[1] |= (0x01 << 6);
		if (TCA9534A_DeviceConfig_ACNV.outputLevel[TCA9534A_PIN_7] == GPIO_PIN_SET)
			data_tx[1] |= (0x01 << 7);

		HAL_I2C_Master_Transmit(I2C_GetHandle(I2C_4), TCA9534A_I2C_WRITE(TCA9534A_I2C_SLAVE_ADDRESS), (uint8_t *)data_tx, 2, 100);
	}
}
