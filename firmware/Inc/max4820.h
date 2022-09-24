/*
 *******************************************************************************
 * File:			max4820.h
 * Date:			2022-04-17
 * Author:			Phillip Durdaut
 * Summary:			Functions for controlling a MAX4820 relay driver
 * Notes:			-
 *******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAX4820_H
#define __MAX4820_H

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Public defines ------------------------------------------------------------*/
/* Public macros -------------------------------------------------------------*/
/* Public typedefs -----------------------------------------------------------*/
typedef enum
{
	MAX4820_DEVICE_ACNV
} MAX4820_DEVICE_t;

typedef enum
{
	MAX4820_RELAY_0,
	MAX4820_RELAY_1,
	MAX4820_RELAY_2,
	MAX4820_RELAY_3,
	MAX4820_RELAY_4,
	MAX4820_RELAY_5,
	MAX4820_RELAY_6,
	MAX4820_RELAY_7
} MAX4820_RELAY_t;

/* Public variables ----------------------------------------------------------*/

/* Public function prototypes ------------------------------------------------*/
extern void MAX4820_Init(void);
extern void MAX4820_SetRelay(MAX4820_DEVICE_t device, MAX4820_RELAY_t relay);

#endif /* __MAX4820_H */
