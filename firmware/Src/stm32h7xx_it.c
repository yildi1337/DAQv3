/*
 *******************************************************************************
 * File:			stm32h7xx_it.c
 * Date:			2020-11-03
 * Author:			Phillip Durdaut
 * Summary:			Interrupt service routines
 * Notes:			-
 *******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32h7xx_it.h"
#include "uart.h"
#include "spi.h"
#include "dma.h"
#include "usb_data.h"
#include "led.h"
#include "debug.h"

/* Private typedefs ----------------------------------------------------------*/
/* Private defines -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

/* Program code --------------------------------------------------------------*/

void NMI_Handler(void)
{

}

void HardFault_Handler(void)
{
	while (1)
	{

	}
}

void MemManage_Handler(void)
{
	while (1)
	{

	}
}

void BusFault_Handler(void)
{
	while (1)
	{

	}
}

void UsageFault_Handler(void)
{
	while (1)
	{

	}
}

void SVC_Handler(void)
{

}

void DebugMon_Handler(void)
{

}

void PendSV_Handler(void)
{

}

void SysTick_Handler(void)
{
	HAL_IncTick();
}

void DMA1_Stream0_IRQHandler(void)
{
	flag_t DMAHalfTransferComplete = 0;
	flag_t DMAFullTransferComplete = 0;

	if ((DMA1->LISR & DMA_FLAG_HTIF0_4) == DMA_FLAG_HTIF0_4)
		DMAHalfTransferComplete = 1;
	else if ((DMA1->LISR & DMA_FLAG_TCIF0_4) == DMA_FLAG_TCIF0_4)
		DMAFullTransferComplete = 1;

	HAL_DMA_IRQHandler(DMA_GetHandle(DMA_SPI2_RX_DMA1_STREAM0));

	DEBUG_On(DEBUG_PIN_1);

	/* Transfer data if requested */
	if (DMAHalfTransferComplete)
	{
		memcpy(DMA_SPI2_RX_DMA1_STREAM0_FinalDataBuffer, DMA_SPI2_RX_DMA1_STREAM0_CircularBuffer[0], DMA_SPI2_RX_DMA1_STREAM0_BUFFER_SIZE_BYTES);

		if (MAIN_MeasurementRunning)
		{
			USB_DATA_TxEndpoint1(DMA_SPI2_RX_DMA1_STREAM0_FinalDataBuffer, DMA_SPI2_RX_DMA1_STREAM0_BUFFER_SIZE_BYTES);
		}
	}
	else if (DMAFullTransferComplete)
	{
		memcpy(DMA_SPI2_RX_DMA1_STREAM0_FinalDataBuffer, DMA_SPI2_RX_DMA1_STREAM0_CircularBuffer[1], DMA_SPI2_RX_DMA1_STREAM0_BUFFER_SIZE_BYTES);

		if (MAIN_MeasurementRunning)
		{
			USB_DATA_TxEndpoint1(DMA_SPI2_RX_DMA1_STREAM0_FinalDataBuffer, DMA_SPI2_RX_DMA1_STREAM0_BUFFER_SIZE_BYTES);
		}
	}

	/* Check for clipping */
	/*uint32_t numberOfBlocks = DMA_SPI2_RX_DMA1_STREAM0_BUFFER_SIZE_BYTES / MAIN_ADC_BYTES_PER_SAMPLE_PER_CHANNEL;

	for (uint32_t i = 0; i < numberOfBlocks; i++) {

		uint8_t byte3 = DMA_SPI2_RX_DMA1_STREAM0_FinalDataBuffer[(i*4) + 0];
		uint8_t byte2 = DMA_SPI2_RX_DMA1_STREAM0_FinalDataBuffer[(i*4) + 1];
		uint8_t ch = byte3 & 0x03;
		int32_t adcValueApprox = ((int32_t)(byte2 << 24)) >> 8;

		if (ch == 0) {

			if (adcValueApprox < -MAIN_ADC_CLIPPING_VALUE || adcValueApprox > MAIN_ADC_CLIPPING_VALUE)
				LED_On(LED_3);
			else
				LED_Off(LED_3);
		}
		else if (ch == 1) {

			if (adcValueApprox < -MAIN_ADC_CLIPPING_VALUE || adcValueApprox > MAIN_ADC_CLIPPING_VALUE)
				LED_On(LED_4);
			else
				LED_Off(LED_4);
		}
	}*/

	DEBUG_Off(DEBUG_PIN_1);

	return;
}

void SPI2_IRQHandler(void)
{
	HAL_SPI_IRQHandler(SPI_GetHandle(SPI_2));
}

void USART1_IRQHandler(void)
{
	/* RX buffer not empty interrupt */
	if (__HAL_UART_GET_FLAG(UART_GetHandle(UART_1), UART_FLAG_RXNE) == SET)
	{
		/* Receive command */
		UART_ReceiveCommand(UART_1);

		/* Clear RX buffer not empty flag */
		__HAL_UART_CLEAR_FLAG(UART_GetHandle(UART_1), UART_FLAG_RXNE);
	}
}

void OTG_HS_EP1_OUT_IRQHandler(void)
{
	HAL_PCD_IRQHandler(USB_DATA_GetHandlePCD());
}

void OTG_HS_EP1_IN_IRQHandler(void)
{
	HAL_PCD_IRQHandler(USB_DATA_GetHandlePCD());
}

void OTG_HS_IRQHandler(void)
{
	if (__HAL_PCD_GET_FLAG(USB_DATA_GetHandlePCD(), USB_OTG_GINTSTS_IEPINT))
	{
		/* Nothing needed here yet */
	}

	HAL_PCD_IRQHandler(USB_DATA_GetHandlePCD());
}
