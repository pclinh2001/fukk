/*
 * F4_Delay.h
 *
 *  Created on: Oct 30, 2023
 *      Author: pclinh2001
 */

#ifndef F4_DELAY_H_
#define F4_DELAY_H_

#include "main.h"

void TIM9_Config (void);
void Delay_us (uint16_t us);
void Delay_ms (uint16_t ms);

#endif /* F4_DELAY_H_ */
