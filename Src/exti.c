/*
 * exti.c
 *
 *  Created on: Oct 30, 2023
 *      Author: pclinh2001
 */


#include "exti.h"
void exti_config(void)
{
    // 1. Enable the SYSCFG/AFIO bit in RCC register

        RCC -> APB2ENR |= (1 << 14);
	// 2. Configure the EXTI configuration Register in the SYSCFG/AFIO
        SYSCFG->EXTICR[0] &= ~(0xF << 0);

	// 4. Configure the Rising Edge / Falling Edge Trigger

		EXTI->RTSR &= ~(1<<0);  // Disable Rising Edge Trigger for PA1
		EXTI->FTSR |= (1<<0);  // Enable Falling Edge Trigger for PA1

	// 3. Disable the EXTI Mask using Interrupt Mask Register (IMR)
		EXTI->IMR |= (1<<0);
	// 5. Set the Interrupt Priority

		NVIC_SetPriority(EXTI0_IRQn , 1);

	// 6. Enable the interrupt
		NVIC_EnableIRQ (EXTI0_IRQn);
}


