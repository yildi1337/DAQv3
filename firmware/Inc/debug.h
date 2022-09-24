/*
 *******************************************************************************
 * File:			debug.h
 * Date:			2022-07-11
 * Author:			Phillip Durdaut
 * Summary:			Functions for controlling the board's debug pins
 * Notes:			-
 *******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __DEBUG_H
#define __DEBUG_H

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Public typedefs -----------------------------------------------------------*/
typedef enum
{
	DEBUG_PIN_1,
	DEBUG_PIN_2,
	DEBUG_PIN_3,
	DEBUG_PIN_4
} DEBUG_PIN_t;

/* Public defines ------------------------------------------------------------*/
/* Public macros -------------------------------------------------------------*/
/* Public variables ----------------------------------------------------------*/

/* Public function prototypes ------------------------------------------------*/
extern void DEBUG_Init(void);
extern void DEBUG_On(DEBUG_PIN_t pin);
extern void DEBUG_Off(DEBUG_PIN_t pin);
extern void DEBUG_Toggle(DEBUG_PIN_t pin);

#endif /* __DEBUG_H */
