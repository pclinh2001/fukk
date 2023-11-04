/*
 * gpio.c
 *
 *  Created on: Oct 30, 2023
 *      Author: pclinh2001
 */

#include "gpio.h"


void GPIO_Config()
{
    // Enable GPIO
      RCC -> AHB1ENR = (1 << 0) | ( 1 << 2);
    // PC13 output

    GPIOC -> MODER |= ( 1 << 26);
    GPIOC -> OTYPER &= ~(1<<13); // ouput push - pull
    GPIOC -> OSPEEDR &= ~(1<<26); // low speed


    GPIOC -> PUPDR |= (1 << 26); //pull up

    // PA0 Input

    GPIOA -> MODER &= ~(3 << 0);
    GPIOA -> MODER |= (0U << 0);

    GPIOA -> PUPDR |= (1 << 0); //pull_up
}


