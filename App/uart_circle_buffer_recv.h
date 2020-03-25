/*
 * uart_circle_buffer_recv.h
 *
 *  Created on: 2020年3月24日
 *      Author: Administrator
 */

#ifndef UART_CIRCLE_BUFFER_RECV_H_
#define UART_CIRCLE_BUFFER_RECV_H_
#include "circle_buffer.h"
#include "main.h"

#define UART_CIRCLE_BUFFER_SIZE (80)
class UartCircle
{

public:
	UartCircle();

private:
	CircleBuffer<uint8_t> _buf;
};




#endif /* UART_CIRCLE_BUFFER_RECV_H_ */
