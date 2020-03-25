/*
 * uart_circle_buffer_recv.cpp
 *
 *  Created on: 2020年3月24日
 *      Author: Administrator
 */
#include "uart_circle_buffer_recv.h"

UartCircle::UartCircle(UART_HandleTypeDef &uart) :
		_buf(UART_CIRCLE_BUFFER_SIZE), _uart(uart)
{

}


void UartCircle::IrqHandler()
{
	uint8_t v;
	HAL_UART_Receive(&_uart, &v, 1, 50);
	_buf.Push(v);
}

