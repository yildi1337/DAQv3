/*
 *******************************************************************************
 * File:			tca9534a.h
 * Date:			2022-04-11
 * Author:			Phillip Durdaut
 * Summary:			Functions for controlling a TCA9534A I/O expander via I2C
 * Notes:			-
 *******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TCA9534A_H
#define __TCA9534A_H

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Public defines ------------------------------------------------------------*/
#define TCA9534A_NUMBER_OF_PINS		8

/* Public macros -------------------------------------------------------------*/
/* Public typedefs -----------------------------------------------------------*/
typedef enum
{
	TCA9534A_DEVICE_ACNV
} TCA9534A_DEVICE_t;

typedef enum
{
	TCA9534A_PIN_0,
	TCA9534A_PIN_1,
	TCA9534A_PIN_2,
	TCA9534A_PIN_3,
	TCA9534A_PIN_4,
	TCA9534A_PIN_5,
	TCA9534A_PIN_6,
	TCA9534A_PIN_7
} TCA9534A_PIN_t;

typedef enum
{
	TCA9534A_PINTYPE_OUTPUT,
	TCA9534A_PINTYPE_INPUT,
	TCA9534A_PINTYPE_UNCONNECTED
} TCA9534A_PINTYPE_t;

/* Public variables ----------------------------------------------------------*/

/* Public function prototypes ------------------------------------------------*/
extern void TCA9534A_Init(void);
extern void TCA9534A_SetPinType(TCA9534A_DEVICE_t device, TCA9534A_PIN_t pin, TCA9534A_PINTYPE_t pintype);
extern void TCA9534A_SetPinState(TCA9534A_DEVICE_t device, TCA9534A_PIN_t pin, GPIO_PinState state);

#endif /* __TCA9534A_H */
