/*
 * iap.h
 *
 *  Created on: 2020年9月4日
 *      Author: Administrator
 */

#ifndef IAP_H_
#define IAP_H_
#include "stm32f1xx.h"

class Iap{
public:
	void StartService();
private:
	inline void SetVector(const uint32_t addr)
	{
		__set_FAULTMASK(1);
		SCB->VTOR=FLASH_BASE |addr;
		__set_FAULTMASK(0);
	}
	typedef void (*func_t) ();

	void RunApp();

	const uint32_t ADDR_IAP_BASE=0x3000;
};



#endif /* IAP_H_ */
