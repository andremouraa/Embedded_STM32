/*
 * stm32f446xx_gpio_driver.h
 *
 *  Created on: Jun 29, 2020
 *      Author: Andre Moura
 */

#ifndef INC_STM32F446XX_GPIO_DRIVER_H_
#define INC_STM32F446XX_GPIO_DRIVER_H_


#include "stm32f446xx.h"

typedef struct {

	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;					/*!< possible value from @GPIO_PIN_MODES >*/
	uint8_t GPIO_PinSpeed;					/*!< possible value from @GPIO_PIN_SPEED >*/
	uint8_t GPIO_PinPuPdControl;			/*!< possible value from @GPIO_PIN_PUPD >*/
	uint8_t GPIO_PinOPType;					/*!< possible value from @GPIO_PIN_OPTYPE >*/
	uint8_t GPIO_PinAltFunMode;

}GPIO_PinConfig_t;


// Handle structure for a GPIO pin

typedef struct
{
	GPIO_RegDef_t *pGPIOx; // This hold the base address of the GPIO port to which the pin belongs
	GPIO_PinConfig_t GPIO_PinConfig; // This holds the GPIO pin configuration settings

}GPIO_Handle_t;

/*
 * 	@GPIO_PIN_NUMBERS
 *  GPIO pin numbers
 */

#define GPIO_PIN_NO_0		0		// Pin 0
#define GPIO_PIN_NO_1		1		// Pin 1
#define GPIO_PIN_NO_2		2		// Pin 2
#define GPIO_PIN_NO_3		3		// Pin 3
#define GPIO_PIN_NO_4		4		// Pin 4
#define GPIO_PIN_NO_5		5		// Pin 5
#define GPIO_PIN_NO_6		6		// Pin 6
#define GPIO_PIN_NO_7		7		// Pin 7
#define GPIO_PIN_NO_8		8		// Pin 8
#define GPIO_PIN_NO_9		9		// Pin 9
#define GPIO_PIN_NO_10		10		// Pin 10
#define GPIO_PIN_NO_11		11		// Pin 11
#define GPIO_PIN_NO_12		12		// Pin 12
#define GPIO_PIN_NO_13		13		// Pin 13
#define GPIO_PIN_NO_14		14		// Pin 14
#define GPIO_PIN_NO_15		15		// Pin 15


/*
 * 	@GPIO_PIN_MODES
 *  GPIO pin possible modes
 */

#define GPIO_MODE_INP 		0		//Input
#define GPIO_MODE_OUT		1		//Output
#define GPIO_MODE_ALTFN		2		//Alternate Function
#define GPIO_MODE_ANALOG	3		//Analog
#define GPIO_MODE_IT_FT		4		//Interruption Falling Trigger
#define GPIO_MODE_IT_RT		5		//Interruption Rising Trigger
#define GPIO_MODE_IT_RFT	6		//Interruption Rising and Falling Trigger

/*
 * 	@GPIO_PIN_OPTYPE
 *  GPIO pin possible output types
 */

#define GPIO_OP_TYPE_PP		0		//Push-Pull
#define GPIO_OP_TYPE_OD		1		//Open Drain

/*
 * 	@GPIO_PIN_SPEED
 *  GPIO pin possible output speeds
 */

#define GPIO_SPEED_LOW		0		//Low Speed
#define GPIO_SPEED_MEDIUM	1		//Medium Speed
#define GPIO_SPEED_FAST		2		//Fast Speed
#define GPIO_SPEED_HIGH		3		//High Speed

/*
 *  @GPIO_PUPD
 *  GPIO pin pull-up pull-down
 */

#define GPIO_NO_PUPD		0		//No pull-up and pull-down
#define GPIO_PU				1		//Pull-Up
#define GPIO_PD				2		//Pull-Down


/*********************************
 * APIs supported by this driver *
 *********************************/

// Clock Setup

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);

// Init and De-Init

void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

// Read and Write

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOuputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

// IRQ Configuration and ISR Handling

void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi);
void GPIO_IRQHandling(uint8_t PinNumber);















#endif /* INC_STM32F446XX_GPIO_DRIVER_H_ */
