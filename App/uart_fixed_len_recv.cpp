/*
 * uart_fixed_len_recv.cpp
 *
 *  Created on: Mar 19, 2020
 *      Author: Administrator
 */

#include "uart_fixed_len_recv.h"



bool UartFixedLen::WriteAndRead(uint16_t timeout)
{
	bool ret = false;
	HAL_StatusTypeDef status = HAL_OK;

	BuildFrame();
	status = HAL_UART_Transmit(_uart, (uint8_t*) &_sendFrame,
			sizeof(_sendFrame), 50);

	uint32_t sendTime = HAL_GetTick();
	HAL_UART_Receive_DMA(_uart, (uint8_t*) &_recvFrame, sizeof(_recvFrame));

	while (!_uartRecvFlag && (HAL_GetTick() - sendTime < timeout))
		;
	if (_uartRecvFlag)
	{
		_uartRecvFlag = 0;
		if (_recvFrame.head == FRAME_HEAD)
		{
			if (_recvFrame.crc == GetCrc(&_recvFrame))
				ret = true;
		}
	}
	return ret;
}

void UartFixedLen::BuildFrame()
{
	_sendFrame.head = 0xaa;
	for (int i = 0; i < sizeof(_sendFrame.data); i++)
		_sendFrame.data[i] = i;
	_sendFrame.crc = GetCrc(&_sendFrame);
}

uint8_t UartFixedLen::GetCrc(void *data)
{
	uint8_t *buf = (uint8_t*) data;
	uint8_t sum = 0;
	for (int i = 0; i < sizeof(UartFixedFrame_t) - 1; i++)
		sum += buf[i];
	return sum;
}
