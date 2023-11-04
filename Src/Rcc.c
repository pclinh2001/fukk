/*
 * Rcc.c
 *
 *  Created on: Oct 30, 2023
 *      Author: pclinh2001
 */


#include "Rcc.h"

#define PLL_M 12
#define PLL_N 96
#define PLL_P 0 // PLLP = 2

void SysClockConfig(void)
{
	// 1. ENABLE HSE and wait for the HSE to become Ready
	RCC->CR |= 1<<16;
	while (!(RCC->CR & (1<<17)));

	// 2. Set the POWER ENABLE CLOCK and VOLTAGE REGULATOR
	RCC->APB1ENR |= 1<<28;
	PWR->CR |= 3<<14;


	// 3. Configure the FLASH PREFETCH and the LATENCY Related Settings
	 FLASH->ACR = (1<<8) | (1<<9)| (1<<10)| (5<<0);

	// 4. Configure the PRESCALARS HCLK, PCLK1, PCLK2
	// AHB PR
	RCC->CFGR &= ~(1<<4);

	// APB1 PR
	RCC->CFGR |= (4<<10);

	// APB2 PR
	RCC->CFGR &= ~(1<<13);

		// 5. Configure the MAIN PLL
	RCC->PLLCFGR = (PLL_M <<0) | (PLL_N << 6) | (PLL_P <<16) | (1<<22);  // (1<<22);

	// 6. Enable the PLL and wait for it to become ready
	RCC->CR |= (1<<24);
	while (!(RCC->CR & (1<<25)));



	// 7. Select the Clock Source and wait for it to be set
	RCC->CFGR |= RCC_CFGR_SW_PLL;  // RCC->CFGR |= (2<<0);
	while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);  // while (!(RCC->CFGR & (2<<2)));


}
