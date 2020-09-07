/*
 * app.cpp
 *
 *  Created on: Mar 19, 2020
 *      Author: Malik
 */
#include "app.h"
#include "uart_fixed_len_recv.h"
#include "uart_flex_len_recv.h"
#include "usart.h"
#include "tim_capture.h"
#include "tim.h"
#include "can.h"
#include "com_can.h"

UartFixedLen *pUartFixed;
UartFlexLen *pUartFlex;
TimCapture *pTimCapture;
ComCan *pComCan;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if (huart == &huart1)
		pUartFixed->IrqHandler();
	else if (huart == &huart2)
		pUartFlex->IrqHandler();
}
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	if (htim == &htim3)
		pTimCapture->IrqHandler();
}
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *can)
{
	pComCan->IrqHandler();
}
void AppInit()
{
	pUartFixed = new UartFixedLen(&huart1);
	pUartFlex = new UartFlexLen(&huart2);
	pTimCapture = new TimCapture(htim3);
	pComCan = new ComCan(hcan);
}

void AppLoop()
{

	pComCan->SendCmd();

	HAL_Delay(100);

	SCB->VTOR=FLASH_BASE|0x200;
}
