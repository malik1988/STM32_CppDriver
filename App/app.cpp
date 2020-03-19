/*
 * app.cpp
 *
 *  Created on: Mar 19, 2020
 *      Author: Malik
 */
#include "app.h"
#include "uart_fixed_len_recv.h"
#include "uart_flex_len_recv.h"
#include "usart.h"

UartFixedLen *pUartFixed;
UartFlexLen *pUartFlex;

void AppInit()
{
	pUartFixed = new UartFixedLen(&huart1);
	pUartFlex = new UartFlexLen(&huart2);
}

void AppLoop()
{

}
