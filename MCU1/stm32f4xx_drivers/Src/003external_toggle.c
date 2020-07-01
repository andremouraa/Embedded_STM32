/*
 * 003external_toggle.c
 *
 *  Created on: 30 de jun de 2020
 *      Author: Andre Moura
 */

#include "stm32f446xx.h"

void delay(void){

	for (uint32_t i = 0; i < 500000; i++);
}

int main(void)
{

	// 1. Set the PC 0 configurations

	GPIO_Handle_t GpioLed;

	GpioLed.pGPIOx = GPIOC;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOC, ENABLE);
	GPIO_Init(&GpioLed);

	// 2. Set the PC 1 configurations

	GPIO_Handle_t GpioButton;

	GpioButton.pGPIOx = GPIOC;
	GpioButton.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_1;
	GpioButton.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_INP;
	GpioButton.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PU;

	GPIO_Init(&GpioButton);

	while(1){

		if (!(GPIO_ReadFromInputPin(GPIOC, GPIO_PIN_NO_1)))
		{
			GPIO_ToggleOutputPin(GPIOC, GPIO_PIN_NO_0);
			delay();
		}
	}

	return 0;
}
