/*
 *******************************************************************************
 * File:			acnv.h
 * Date:			2022-04-17
 * Author:			Phillip Durdaut
 * Summary:			Functions for controlling the ACNV board
 * Notes:			-
 *******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __ACNV_H
#define __ACNV_H

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Public defines ------------------------------------------------------------*/
/* Public macros -------------------------------------------------------------*/
/* Public typedefs -----------------------------------------------------------*/
typedef enum
{
	ACNV_CHANNEL_1,
	ACNV_CHANNEL_2
} ACNV_CHANNEL_t;

typedef enum
{
	ACNV_INPUT_TYPE_INT,
	ACNV_INPUT_TYPE_EXT
} ACNV_INPUT_TYPE_t;

typedef enum
{
	ACNV_CHASSIS_CONNECTION_FLOAT,
	ACNV_CHASSIS_CONNECTION_GND
} ACNV_CHASSIS_CONNECTION_t;

/* Public variables ----------------------------------------------------------*/

/* Public function prototypes ------------------------------------------------*/
extern void ACNV_Init(void);
extern ACNV_INPUT_TYPE_t ACNV_GetInputType(ACNV_CHANNEL_t channel);
extern void ACNV_SetInputType(ACNV_CHANNEL_t channel, ACNV_INPUT_TYPE_t input_type);
extern uint8_t * ACNV_GetInputTypeString(ACNV_CHANNEL_t channel);
extern ACNV_CHASSIS_CONNECTION_t ACNV_GetChassisConnection(void);
extern void ACNV_SetChassisConnection(ACNV_CHASSIS_CONNECTION_t chassis_connection);
extern uint8_t * ACNV_GetChassisConnectionString(void);

#endif /* __ACNV_H */
