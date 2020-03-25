/*
 * tim_capture.cpp
 *
 *  Created on: Mar 20, 2020
 *      Author: Administrator
 */

#include "tim_capture.h"

TimCapture::TimCapture(TIM_HandleTypeDef &tim)
{

	HAL_TIM_IC_Start_IT(&_tim, TIM_CHANNEL_1);
}

void TimCapture::IrqHandler()
{
	static FlagStatus state = SET;
	static uint32_t lastCount = 0;
	if (state == SET)
	{
		lastCount = HAL_TIM_ReadCapturedValue(&_tim, TIM_CHANNEL_1);
		//下降沿
		_tim.Instance->CCER |= TIM_CCER_CC1P;
		state = RESET;
	}
	else
	{
		uint32_t currentCount = HAL_TIM_ReadCapturedValue(&_tim, TIM_CHANNEL_1);
		_caputreTime = (currentCount - lastCount + 0xffff) % 0xffff;
		//上升沿
		_tim.Instance->CCER &= ~TIM_CCER_CC1P;
		state = SET;
	}
}
