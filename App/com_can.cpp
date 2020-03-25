/*
 * com_can.cpp
 *
 *  Created on: Mar 2, 2020
 *      Author: Administrator
 */
#include "com_can.h"
#include <string.h>

ComCan::ComCan(CAN_HandleTypeDef &hcan) :
		_hcan(hcan),
		_canMsg
		{ 0 }
{
	//配置过滤器
	//配置FIFO0
	CAN_FilterTypeDef canFilter;

	canFilter.FilterActivation = ENABLE; // 使能滤波
	canFilter.FilterBank = 0; // 滤波器序号，0-13
	canFilter.FilterFIFOAssignment = CAN_FILTER_FIFO0; // 滤波器绑定FIFO 0
	canFilter.FilterIdHigh = 0; // 掩码后ID的高16bit
	canFilter.FilterIdLow = 0; // 掩码后ID的低16bit
	canFilter.FilterMaskIdHigh = 0; // ID掩码值高16bit
	canFilter.FilterMaskIdLow = 0; // ID掩码值低16bit
	canFilter.FilterMode = CAN_FILTERMODE_IDMASK; // 滤波器模式，设置ID掩码模式
	canFilter.FilterScale = CAN_FILTERSCALE_32BIT; // 32位
	canFilter.SlaveStartFilterBank = 0;  //共14个滤波器

	if (HAL_CAN_ConfigFilter(&_hcan, &canFilter) != HAL_OK)
	{
		Error_Handler();
	}
	if (HAL_CAN_ActivateNotification(&_hcan, CAN_IT_RX_FIFO0_MSG_PENDING)
			!= HAL_OK)
	{
		Error_Handler();
	}
	if (HAL_CAN_Start(&_hcan) != HAL_OK)
	{
		Error_Handler();
	}
}

ComCan_Msg_t ComCan::GetValue()
{
	ComCan_Msg_t msg =
	{ 0 };
	if (_canMsg.valid)
	{
		memcpy(&msg, &_canMsg, sizeof(msg));
		_canMsg.valid = 0;
	}
	return msg;
}
void ComCan::IrqHandler()
{
	//CAN ID等头部信息
	CAN_RxHeaderTypeDef pHeader =
	{ 0 };
	if (HAL_CAN_GetRxMessage(&_hcan, CAN_RX_FIFO0, &pHeader, _canMsg.data)
			== HAL_OK)
	{
		_canMsg.id = pHeader.StdId;
		_canMsg.len = pHeader.DLC;

		_canMsg.valid = 1;
	}
}
void ComCan::SendCmd()
{
	CAN_TxHeaderTypeDef pHeader =
	{ 0 };
	uint8_t aData[] =
	{ 0, 1, 2, 0 };
	pHeader.IDE = CAN_ID_STD;
	pHeader.DLC = sizeof(aData);
	pHeader.StdId = CAN_ID_TEST;
	pHeader.RTR = CAN_RTR_DATA;
	uint32_t TxMailbox;
	if (HAL_CAN_AddTxMessage(&_hcan, &pHeader, aData, &TxMailbox) != HAL_OK)
	{
		Error_Handler();
	}
}
