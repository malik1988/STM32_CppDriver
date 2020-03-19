/*
 * uart_fixed_len_recv.h
 *
 *  Created on: Mar 19, 2020
 *      Author: Administrator
 */

#ifndef UART_FIXED_LEN_RECV_H_
#define UART_FIXED_LEN_RECV_H_

#include "main.h"
#define UART_FIXED_LEN_LENGTH (20)

typedef struct
{
	uint8_t head;
	uint8_t data[UART_FIXED_LEN_LENGTH - 2];
	uint8_t crc;
} UartFixedFrame_t;
class UartFixedLen
{
public:
	UartFixedLen(UART_HandleTypeDef *huart) :
			_uart(huart), _sendFrame
			{ 0 }, _recvFrame
			{ 0 }, _uartRecvFlag(0)
	{

	}
	inline void IrqHandler()
	{
		_uartRecvFlag = 1;
	}

	bool WriteAndRead(uint16_t timeout = 200);
private:
	void BuildFrame();
	uint8_t GetCrc(void *data);
private:
	UART_HandleTypeDef *_uart;
	UartFixedFrame_t _sendFrame;
	UartFixedFrame_t _recvFrame;
	uint8_t _uartRecvFlag;
	const uint8_t FRAME_HEAD = 0xaa;
};






#endif /* UART_FIXED_LEN_RECV_H_ */
