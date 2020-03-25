/*
 * com_can.h
 *
 *  Created on: Mar 2, 2020
 *      Author: Administrator
 */

#ifndef APP_COM_CAN_H_
#define APP_COM_CAN_H_

#include "main.h"

typedef struct
{
	uint16_t id;
	uint8_t len;
	uint8_t data[8];
	uint8_t valid;

} ComCan_Msg_t;


class ComCan
{
public:
	ComCan(CAN_HandleTypeDef &hcan);
	ComCan_Msg_t GetValue();
	void IrqHandler();
	void SendCmd();
private:
	inline uint8_t Bit(uint8_t index)
	{
		return (1 << index);
	}
private:
	CAN_HandleTypeDef _hcan;
	ComCan_Msg_t _canMsg;
	const uint16_t CAN_ID_TEST = 0x12;
	



};

#endif /* APP_COM_CAN_H_ */
