/*
 * iap.cpp
 *
 *  Created on: 2020年9月4日
 *      Author: Administrator
 */
#include "iap.h"


void Iap::RunApp()
{
	func_t pFunc;

	SetVector(ADDR_IAP_BASE);
	pFunc=(func_t)(*(__IO uint32_t*)(ADDR_IAP_BASE+4));
	__set_MSP(*(__IO uint32_t*)(ADDR_IAP_BASE));
	pFunc();
}


void Iap::StartService()
{
	//1.recv file


	//2.check file

	//3.write to flash

	//4.reboot
	RunApp();
}
