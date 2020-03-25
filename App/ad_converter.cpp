/*
 * ad_converter.cpp
 *
 *  Created on: Mar 20, 2020
 *      Author: Administrator
 */
#include "ad_converter.h"
AdConverter::AdConverter(ADC_HandleTypeDef &hadc) :
		_hadc(hadc),
		_ad
		{ 0 }
{
	HAL_ADC_Start_DMA(&_hadc, (uint32_t*) &_ad, sizeof(_ad) / sizeof(_ad[0]));
}
uint16_t AdConverter::GetValue(Ad_channel_t channel)
{
	uint32_t value = 0;
	uint8_t i = (uint8_t) channel;

	for (; i < sizeof(_ad) / sizeof(_ad[0]); i += AD_CH_MAX)
	{
		value += (uint32_t) _ad[i];
	}
	return (uint16_t)(value / (sizeof(_ad) / sizeof(_ad[0]) / AD_CH_MAX));
}
