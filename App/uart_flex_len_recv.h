/*
 * uart_flex_len_recv.h
 *
 *  Created on: Mar 19, 2020
 *      Author: Administrator
 */

#ifndef UART_FLEX_LEN_RECV_H_
#define UART_FLEX_LEN_RECV_H_

#include "main.h"
#define UART_FLEX_LEN_MAX_SIZE (20)

class UartFlexLen
{
public:
	UartFlexLen(UART_HandleTypeDef *huart) :
			_uart(huart), _data
	{	0}, _index(0), _state(0), _frame
	{	0}, _getFrame(0)
	{

	}
	inline void IrqHandler();
	inline int Read(uint8_t *outData)
	{
		int len = 0;
		if (_getFrame)
		{
			while (len < _index)
				*(outData) = _frame[_index];
		}
		return len;
	}
	void Start();
	void Stop();
private:

	UART_HandleTypeDef *_uart;
	const uint8_t DATA_LEN = UART_FLEX_LEN_MAX_SIZE;
	uint8_t _data[1];
	uint8_t _index;
	uint8_t _state;
	uint8_t _frame[UART_FLEX_LEN_MAX_SIZE];
	uint8_t _getFrame;
};






#endif /* UART_FLEX_LEN_RECV_H_ */
