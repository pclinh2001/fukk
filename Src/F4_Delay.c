/*
 * F4_Delay.h
 *
 *  Created on: Oct 30, 2023
 *      Author: pclinh2001
 */

#include "F4_delay.h"

void TIM9_Config (void)
{
    RCC-> APB2ENR |= (1<<16); // enable clock for TIM9

    TIM9 -> PSC = 100 - 1;  // PSC
    TIM9 -> ARR = 65536 - 1;    // ARR

    TIM9->CR1 |= (1<<0);    // Enable Counter
 //   while (!(TIM9->SR & (1<<0)));
}

void Delay_us (uint16_t us)
{
	/************** STEPS TO FOLLOW *****************
	1. RESET the Counter
	2. Wait for the Counter to reach the entered value. As each count will take 1 us,
		 the total waiting time will be the required us delay
	************************************************/
	TIM9 -> CNT = 0;
	while (( TIM9->CNT) < us);
}

void Delay_ms (uint16_t ms)
{
	for (uint16_t i=0; i<ms; i++)
	{
		Delay_us (1000); // delay of 1 ms
	}
}

