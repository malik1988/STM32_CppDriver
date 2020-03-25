/*
 * tim_capture.h
 *
 *  Created on: Mar 20, 2020
 *      Author: Administrator
 */

#ifndef TIM_CAPTURE_H_
#define TIM_CAPTURE_H_
#include "main.h"
class TimCapture
{
public:
	TimCapture(TIM_HandleTypeDef &tim);
	void IrqHandler();
	inline uint32_t GetCaptureTime() const
	{
		return _caputreTime;
	}
private:
	TIM_HandleTypeDef _tim;
	uint32_t _caputreTime;
};







#endif /* TIM_CAPTURE_H_ */
