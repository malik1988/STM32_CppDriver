/*
 * app.h
 *
 *  Created on: Mar 19, 2020
 *      Author: Malik
 */

#ifndef APP_APP_H_
#define APP_APP_H_
#include "main.h"

#ifdef __cplusplus
extern "C"
{
#endif
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim);
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *can);

void AppInit();

void AppLoop();

#ifdef __cplusplus
}
#endif

#endif /* APP_APP_H_ */
