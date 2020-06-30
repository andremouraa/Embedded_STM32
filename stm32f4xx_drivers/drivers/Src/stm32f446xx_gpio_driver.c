/*
 * stm32f446xx_gpio_driver.c
 *
 *  Created on: Jun 29, 2020
 *      Author: Andre Moura
 */

#include "stm32f446xx_gpio_driver.h"

// Clock Setup

/****************************************************
 * @fn				- GPIO_PeriClockControl
 *
 * @brief			- This function enables or disables peripheral clock for the given GPIO port
 *
 * @param[in] 		- Base address of the GPIO peripheral
 * @param[in]		- ENABLE or DISABLE macros
 * @param[in]		-
 *
 * @return			-
 *
 * @note			-
 *
 */

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{
	if (EnorDi == ENABLE){
		if (pGPIOx == GPIOA)
		{
			GPIOA_PCLK_EN();
		} else if (pGPIOx == GPIOB)
		{
			GPIOB_PCLK_EN();
		} else if (pGPIOx == GPIOC)
		{
			GPIOC_PCLK_EN();
		} else if (pGPIOx == GPIOD)
		{
			GPIOD_PCLK_EN();
		} else if (pGPIOx == GPIOE)
		{
			GPIOE_PCLK_EN();
		} else if (pGPIOx == GPIOF)
		{
			GPIOF_PCLK_EN();
		} else if (pGPIOx == GPIOG)
		{
			GPIOG_PCLK_EN();
		} else if (pGPIOx == GPIOH)
		{
			GPIOH_PCLK_EN();
		}
	} else {
		if (pGPIOx == GPIOA)
		{
			GPIOA_PCLK_DI();
		} else if (pGPIOx == GPIOB)
		{
			GPIOB_PCLK_DI();
		} else if (pGPIOx == GPIOC)
		{
			GPIOC_PCLK_DI();
		} else if (pGPIOx == GPIOD)
		{
			GPIOD_PCLK_DI();
		} else if (pGPIOx == GPIOE)
		{
			GPIOE_PCLK_DI();
		} else if (pGPIOx == GPIOF)
		{
			GPIOF_PCLK_DI();
		} else if (pGPIOx == GPIOG)
		{
			GPIOG_PCLK_DI();
		} else if (pGPIOx == GPIOH)
		{
			GPIOH_PCLK_DI();
		}

	}
}

// Init and De-Init

/****************************************************
 * @fn				- GPIO_Init
 *
 * @brief			- This function initialize the given GPIO pin and set the needed parameters
 *
 * @param[in] 		- The Struct GPIO_Handle
 * @param[in]		-
 * @param[in]		-
 *
 * @return			- none
 *
 * @note			- none
 *
 */


void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	uint32_t temp = 0; //Temporary register

	//1. Configure the mode of GPIO pin
	if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG) 											// Compare if is a Non-Interrupt Mode
	{
		temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)); 	// Shift the value of "PinMode" to the right position and store at "temp"
		pGPIOHandle->pGPIOx->MODER &= ~(3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));					// Cleaning the bits
		pGPIOHandle->pGPIOx->MODER |= temp;																		// Set the pin mode on the board

	} else
	{
		//this part will code later. (interrupt mode)
	}

	temp = 0;																									// Reset the "temp" variable

	//2. Configure the speed
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2* pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)); 		// Shift the value of "PinSpeed" to the right position and store at "temp"
	pGPIOHandle->pGPIOx->OSPEEDR &= ~(3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));					// Cleaning the bits
	pGPIOHandle->pGPIOx->OSPEEDR |= temp;																		// Set the pin speed on the board

	temp = 0;																									// Reset the "temp" variable

	//3. Configure the PuPd settings
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2* pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));// Shift the value of "PinPuPd" to the right position and store at "temp"
	pGPIOHandle->pGPIOx->PUPDR &= ~(3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));						// Cleaning the bits
	pGPIOHandle->pGPIOx->PUPDR |= temp;																			// Set the pin PUPD on the board

	temp = 0;

	//4. Configure the OutType
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);			// Shift the value of "PinOPType" to the right position and store at "temp"
	pGPIOHandle->pGPIOx->OTYPER &= ~(1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);							// Cleaning the bits
	pGPIOHandle->pGPIOx->OTYPER = temp;																			// Set the pin output type on the board

	temp = 0;																									// Reset the "temp" variable

	//5. Configure the Alternate funcionality

	if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN)
		{
			if (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber <= GPIO_PIN_NO_7)												// Compare if the pin number is equal or below 7
			{
				temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4* pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));	//Shift the value of "PinAltFunMode" to the right position and store at "temp"
				pGPIOHandle->pGPIOx->AFR[0] &= ~(15 << (4 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)); 		// Cleaning the bits
				pGPIOHandle->pGPIOx->AFR[0] = temp;																// Set the Af on the board
			}else
			{
				temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4* (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber - 8))); //Shift the value of "PinAltFunMode" to the right position and store at "temp"
				pGPIOHandle->pGPIOx->AFR[1] &= ~(15 << (4 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber - 8));	// Cleaning the bits
				pGPIOHandle->pGPIOx->AFR[1] = temp;																// Set the Af on the board
			}
		}

}


/****************************************************
 * @fn				- GPIO_DeInit
 *
 * @brief			- This function reset all the registers of a GPIO Port
 *
 * @param[in] 		- Base address of the GPIO peripheral
 * @param[in]		-
 * @param[in]		-
 *
 * @return			- none
 *
 * @note			- none
 *
 */

void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{

	if (pGPIOx == GPIOA)
	{
		GPIOA_REG_RESET();

	} else if (pGPIOx == GPIOB)
	{
		GPIOB_REG_RESET();
	} else if (pGPIOx == GPIOC)
	{
		GPIOC_REG_RESET();
	} else if (pGPIOx == GPIOD)
	{
		GPIOD_REG_RESET();
	} else if (pGPIOx == GPIOE)
	{
		GPIOE_REG_RESET();
	} else if (pGPIOx == GPIOF)
	{
		GPIOF_REG_RESET();
	} else if (pGPIOx == GPIOG)
	{
		GPIOG_REG_RESET();
	} else if (pGPIOx == GPIOH)
	{
		GPIOH_REG_RESET();
	}

}

// Read and Write

/****************************************************
 * @fn				- GPIO_ReadFromInputPin
 *
 * @brief			- This function reads the value of a GPIO pin
 *
 * @param[in] 		- Base address of the GPIO peripheral
 * @param[in]		- The desired pin number
 * @param[in]		-
 *
 * @return			- none
 *
 * @note			- none
 *
 */

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	uint8_t value = 0;
	value = (uint8_t) ((pGPIOx->IDR >> PinNumber) & 1);
	return value;
}

/****************************************************
 * @fn				- GPIO_ReadFromInputPort
 *
 * @brief			- This function reads the value of a GPIO Port
 *
 * @param[in] 		- Base address of the GPIO peripheral
 * @param[in]		-
 * @param[in]		-
 *
 * @return			- none
 *
 * @note			- none
 *
 */

uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
	uint16_t value = 0;
	value = (uint16_t) pGPIOx->IDR;
	return value;
}

/****************************************************
 * @fn				- GPIO_WriteToOuputPin
 *
 * @brief			- This function write a value in a GPIO pin
 *
 * @param[in] 		- Base address of the GPIO peripheral
 * @param[in]		- Pin Number
 * @param[in]		- Value to be written, it can be 1 or 0
 *
 * @return			- none
 *
 * @note			- none
 *
 */

void GPIO_WriteToOuputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
{
	if (Value == GPIO_PIN_SET){
		pGPIOx->ODR |= (1 << PinNumber);
	}else
	{
		pGPIOx->ODR &= ~(1 << PinNumber);
	}
}

/****************************************************
 * @fn				- GPIO_WriteToOuputPort
 *
 * @brief			- This function write a value in the GPIO Port
 *
 * @param[in] 		- Base address of the GPIO peripheral
 * @param[in]		- Value with 16 bits to be written
 * @param[in]		-
 *
 * @return			- none
 *
 * @note			- none
 *
 */


void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{
	pGPIOx->ODR = Value;
}

/****************************************************
 * @fn				- GPIO_WriteToOuputPort
 *
 * @brief			- This function inverts the value of bit
 *
 * @param[in] 		- Base address of the GPIO peripheral
 * @param[in]		- Pin Number
 * @param[in]		-
 *
 * @return			- none
 *
 * @note			- none
 *
 */

void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx->ODR ^= (1 << PinNumber);
}

// IRQ Configuration and ISR Handling

void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi)
{

}

void GPIO_IRQHandling(uint8_t PinNumber)
{

}
