/*
 * uart_flex_len_recv.cpp
 *
 *  Created on: Mar 19, 2020
 *      Author: Administrator
 */
#include "uart_flex_len_recv.h"

void UartFlexLen::Start()
{
	HAL_UART_Receive_DMA(_uart, _data, sizeof(_data));

}
void UartFlexLen::IrqHandler()
{
	switch (_state)
	{
	case 0:
		_index = 0;
		_getFrame = 0;
		if ((_frame[_index++] = _data[0]) == '$')
		{
			_state = 1;
		}
		break;
	case 1: //接收中间数据
		if ((_frame[_index++] = _data[0]) != '\n')
		{
			if (_index >= DATA_LEN)
			{
				_state = 0;
				_getFrame = 1;
				_state = 0;
			}
		}
		else
		{
			_state = 0;
			_getFrame = 1;
			_state = 0;
		}
		break;
	}
}

void UartFlexLen::Stop()
{
	HAL_UART_DMAStop (_uart);
}
