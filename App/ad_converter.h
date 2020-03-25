/*
 * ad_converter.h
 *
 *  Created on: Mar 20, 2020
 *      Author: Administrator
 */

#ifndef AD_CONVERTER_H_
#define AD_CONVERTER_H_


#include "main.h"
typedef enum
{
	AD_CH_1 = 0, AD_CH_2, AD_CH_3, AD_CH_MAX
} Ad_channel_t;

class AdConverter
{
public:
	AdConverter(ADC_HandleTypeDef &hadc);
	uint16_t GetValue(Ad_channel_t channel);
private:
	uint32_t _ad[100];
	ADC_HandleTypeDef _hadc;
};








#endif /* AD_CONVERTER_H_ */
