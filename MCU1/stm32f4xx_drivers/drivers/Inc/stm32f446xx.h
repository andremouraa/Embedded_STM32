/*
 * stm32f446xx.h
 *
 *  Created on: Jun 29, 2020
 *      Author: Andre Moura
 */

#ifndef INC_STM32F446XX_H_
#define INC_STM32F446XX_H_

#include <stdint.h>

#define __vo volatile

/*************************************START: Processor Specific Details******************************/


/*
 * ARM Cortex Mx Processor NVIC ISERx register Addresses
 */

#define NVIC_ISER0 			( (__vo uint32_t*)0xE000E100 )
#define NVIC_ISER1 			( (__vo uint32_t*)0xE000E104 )
#define NVIC_ISER2 			( (__vo uint32_t*)0xE000E108 )
#define NVIC_ISER3 			( (__vo uint32_t*)0xE000E10C )


/*
 * ARM Cortex Mx Processor NVIC ICERx register Addresses
 */

#define NVIC_ICER0 			( (__vo uint32_t*)0xE000E180 )
#define NVIC_ICER1 			( (__vo uint32_t*)0xE000E184 )
#define NVIC_ICER2 			( (__vo uint32_t*)0xE000E188 )
#define NVIC_ICER3 			( (__vo uint32_t*)0xE000E18C )

/*
 * ARM Cortex Mx Processor Priority Register Address
 */

#define	NVIC_PR_BASE_ADDR	( (__vo uint32_t*)0xE000E400)

/*
 * ARM Cortex Mx Processor Priority Register Address
 */

#define NO_PR_BITS_IMPLEMENTED			4

/*
 * Base addresses of FLASH and SRAM memories
 */

#define FLASH_BASEADDR			0x08000000U
#define SRAM1_BASEADDR			0x20000000U
#define SRAM2_BASEADDR			0x20001C00U
#define ROM						0X1FFF0000U
#define SRAM 					SRAM1_BASEADDR

/*
 * AHBx and APBx Bus Peripheral base addresses
 */


#define PERIPH_BASEADDR				0X40000000U
#define APB1PERIPH_BASEADDR			PERIPH_BASEADDR
#define APB2PERIPH_BASEADDR			0x40010000U
#define AHB1PERIPH_BASEADDR			0x40020000U
#define AHB2PERIPH_BASEADDR			0x50000000U


/*
 * AHB1 Peripherals base addresses
 */

#define GPIOA_BASEADDR				(AHB1PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR				(AHB1PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR				(AHB1PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR				(AHB1PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR				(AHB1PERIPH_BASEADDR + 0x1000)
#define GPIOF_BASEADDR				(AHB1PERIPH_BASEADDR + 0x1400)
#define GPIOG_BASEADDR				(AHB1PERIPH_BASEADDR + 0x1800)
#define GPIOH_BASEADDR				(AHB1PERIPH_BASEADDR + 0x1C00)
#define RCC_BASEADDR				(AHB1PERIPH_BASEADDR + 0x3800)

/*
 * APB1 Peripherals base addresses
 */

#define TM2_BASEADDR				(APB1PERIPH_BASEADDR + 0x0000)
#define TM3_BASEADDR				(APB1PERIPH_BASEADDR + 0x0400)
#define TM4_BASEADDR				(APB1PERIPH_BASEADDR + 0x0800)
#define TM5_BASEADDR				(APB1PERIPH_BASEADDR + 0x0C00)
#define TM6_BASEADDR				(APB1PERIPH_BASEADDR + 0x1000)
#define TM7_BASEADDR				(APB1PERIPH_BASEADDR + 0x1400)
#define TM12_BASEADDR				(APB1PERIPH_BASEADDR + 0x1800)
#define TM13_BASEADDR				(APB1PERIPH_BASEADDR + 0x1C00)
#define TM14_BASEADDR				(APB1PERIPH_BASEADDR + 0x2000)

#define RTC_BASEADDR				(APB1PERIPH_BASEADDR + 0x2800)

#define WWDG_BASEADDR				(APB1PERIPH_BASEADDR + 0x2C00)
#define IWDG_BASEADDR				(APB1PERIPH_BASEADDR + 0x3000)

#define SPI2_BASEADDR				(APB1PERIPH_BASEADDR + 0x3800)
#define SPI3_BASEADDR				(APB1PERIPH_BASEADDR + 0x3C00)

#define SPDIF_BASEADDR				(APB1PERIPH_BASEADDR + 0x4000)

#define USART2_BASEADDR				(APB1PERIPH_BASEADDR + 0x4400)
#define USART3_BASEADDR				(APB1PERIPH_BASEADDR + 0x4800)
#define UART4_BASEADDR				(APB1PERIPH_BASEADDR + 0x5C00)
#define UART5_BASEADDR				(APB1PERIPH_BASEADDR + 0x5000)

#define I2C1_BASEADDR				(APB1PERIPH_BASEADDR + 0x5400)
#define I2C2_BASEADDR				(APB1PERIPH_BASEADDR + 0x5800)
#define I2C3_BASEADDR				(APB1PERIPH_BASEADDR + 0x5C00)

#define CAN1_BASEADDR				(APB1PERIPH_BASEADDR + 0x6400)
#define CAN2_BASEADDR				(APB1PERIPH_BASEADDR + 0x6800)
#define HDMI_BASEADDR				(APB1PERIPH_BASEADDR + 0x6C00)
#define PWR_BASEADDR				(APB1PERIPH_BASEADDR + 0x7000)
#define DAC_BASEADDR				(APB1PERIPH_BASEADDR + 0x7400)

/*
 * APB2 Peripherals base addresses
 */

#define TIM1_BASEADDR				(APB2PERIPH_BASEADDR + 0x0000)
#define TIM8_BASEADDR				(APB2PERIPH_BASEADDR + 0x0400)

#define USART1_BASEADDR				(APB2PERIPH_BASEADDR + 0x1000)
#define USART6_BASEADDR				(APB2PERIPH_BASEADDR + 0x1400)

#define ADC_BASEADDR				(APB2PERIPH_BASEADDR + 0x2000)
#define SDMMC_BASEADDR				(APB2PERIPH_BASEADDR + 0x2C00)

#define SPI1_BASEADDR				(APB2PERIPH_BASEADDR + 0x3000)
#define SPI4_BASEADDR				(APB2PERIPH_BASEADDR + 0x3400)

#define SYSCFG_BASEADDR				(APB2PERIPH_BASEADDR + 0x3800)
#define EXTI_BASEADDR				(APB2PERIPH_BASEADDR + 0x3C00)

#define TIM9_BASEADDR				(APB2PERIPH_BASEADDR + 0x4000)
#define TIM10_BASEADDR				(APB2PERIPH_BASEADDR + 0x4400)
#define TIM11_BASEADDR				(APB2PERIPH_BASEADDR + 0x4800)
#define SAI1_BASEADDR				(APB2PERIPH_BASEADDR + 0x5800)
#define SAI2_BASEADDR				(APB2PERIPH_BASEADDR + 0x5C00)

/**************** PERIPHERAL REGISTER DEFINITION STRUCTURES ****************/

typedef struct
{
	__vo uint32_t MODER;			//Mode Register
	__vo uint32_t OTYPER;			//Output Type Register
	__vo uint32_t OSPEEDR;			//Output Speed Register
	__vo uint32_t PUPDR;			//Pull-up/Pull-down Register
	__vo uint32_t IDR;				//Input Data Register
	__vo uint32_t ODR;				//Output Data Register
	__vo uint32_t BSRR;				//Bit Set/Reset Register
	__vo uint32_t LCKR;				//Configuration Lock Register
	__vo uint32_t AFR[2];			//Alternate Function Register

} GPIO_RegDef_t;

typedef struct
{
	__vo uint32_t CR; 				//Clock control register
	__vo uint32_t PLLCFGR; 			//PLL configuration register
	__vo uint32_t CFGR; 			//Clock configuration register
	__vo uint32_t CIR; 				//Clock interrupt register

	__vo uint32_t AHB1RSTR; 		//AHB1 peripheral reset register
	__vo uint32_t AHB2RSTR;			//AHB2 peripheral reset register
	__vo uint32_t AHB3RSTR; 		//AHB3 peripheral reset register
	uint32_t RESERVED0;
	__vo uint32_t APB1RSTR; 		//APB1 peripheral reset register
	__vo uint32_t APB2RSTR; 		//APB2 peripheral reset register

	uint32_t RESERVED1[2];

	__vo uint32_t AHB1ENR; 			//AHB1 peripheral clock enable register
	__vo uint32_t AHB2ENR;			//AHB2 peripheral clock enable register
	__vo uint32_t AHB3ENR;			//AHB3 peripheral clock enable register
	__vo uint32_t RESERVED2;
	__vo uint32_t APB1ENR;			//APB1 peripheral clock enable register
	__vo uint32_t APB2ENR;			//APB2 peripheral clock enable register

	uint32_t RESERVED3[2];

	__vo uint32_t AHB1LPENR;		//AHB1 peripheral clock enable in low power mode register
	__vo uint32_t AHB2LPENR;		//AHB2 peripheral clock enable in low power mode register
	__vo uint32_t AHB3LPENR;		//AHB3 peripheral clock enable in low power mode register
	uint32_t RESERVED4;
	__vo uint32_t APB1LPENR;		//APB1 peripheral clock enable in low power mode register
	__vo uint32_t APB2LPENR;		//APB2 peripheral clock enable in low power mode register

	uint32_t RESERVED5[2];

	__vo uint32_t BDCR;				//Backup domain control register
	__vo uint32_t CSR;				//Clock control & status register

	uint32_t RESERVED6[2];

	__vo uint32_t SSCGR; 			//Spread spectrum clock generation register
	__vo uint32_t PLLI2SCFGR; 		//PLLI2S configuration register
	__vo uint32_t PLLSAICFGR; 		//PLL configuration register
	__vo uint32_t DCKCFGR; 			//Dedicated clock configuration register
	__vo uint32_t CKGATENR; 		//Clocks gated enable register
	__vo uint32_t DCKCFGR2; 		//Dedicated clocks configuration register 2


}RCC_RegDef_t;

typedef struct{
	__vo uint32_t IMR;				//Interrupt mask register
	__vo uint32_t EMR;				//Event mask register
	__vo uint32_t RTSR;				//Rising trigger selection register
	__vo uint32_t FTSR;				//Falling trigger selection register
	__vo uint32_t SWIER;			//Software interrupt event register
	__vo uint32_t PR;				//Pending register

}EXTI_RegDef_t;

typedef struct{
	__vo uint32_t MEMRMP;			//Memory remap register
	__vo uint32_t PMC;				//Peripheral mode configuration register
	__vo uint32_t EXTICR[4];		//External interruption configuration register
	uint32_t RESERVED1[2];
	__vo uint32_t CMPCR;			//Compensation cell control register
	uint32_t RESERVED2[2];
	__vo uint32_t CFGR;				//Configuration register

}SYSCFG_RegDef_t;


/*
 * Peripheral Definitions
 */

#define GPIOA ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC ((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD ((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE ((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF ((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG ((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH ((GPIO_RegDef_t*)RCC_BASEADDR)



#define RCC ((RCC_RegDef_t*)RCC_BASEADDR)
#define EXTI ((EXTI_RegDef_t*)EXTI_BASEADDR)
#define SYSCFG ((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)

/*
 * Clock Enable Macros for GPIOx peripherals
 */

#define GPIOA_PCLK_EN()  ( RCC->AHB1ENR |= (1 << 0) )
#define GPIOB_PCLK_EN()  ( RCC->AHB1ENR |= (1 << 1) )
#define GPIOC_PCLK_EN()  ( RCC->AHB1ENR |= (1 << 2) )
#define GPIOD_PCLK_EN()  ( RCC->AHB1ENR |= (1 << 3) )
#define GPIOE_PCLK_EN()  ( RCC->AHB1ENR |= (1 << 4) )
#define GPIOF_PCLK_EN()  ( RCC->AHB1ENR |= (1 << 5) )
#define GPIOG_PCLK_EN()  ( RCC->AHB1ENR |= (1 << 6) )
#define GPIOH_PCLK_EN()  ( RCC->AHB1ENR |= (1 << 7) )

/*
 * Clock Enable Macros for I2Cx peripherals
 */

#define I2C1_PCLK_EN()  ( RCC->APB1ENR |= (1 << 21) )
#define I2C2_PCLK_EN()  ( RCC->APB1ENR |= (1 << 22) )
#define I2C3_PCLK_EN()  ( RCC->APB1ENR |= (1 << 23) )

/*
 * Clock Enable Macros for SPIx peripherals
 */

#define SPI1_PCLK_EN()  ( RCC->APB2ENR |= (1 << 12) )
#define SPI4_PCLK_EN()  ( RCC->APB2ENR |= (1 << 13) )
#define SPI2_PCLK_EN()  ( RCC->APB1ENR |= (1 << 14) )
#define SPI3_PCLK_EN()  ( RCC->APB1ENR |= (1 << 15) )


/*
 * Clock Enable Macros for USARTx peripherals
 */

#define USART2_PCLK_EN()  ( RCC->APB1ENR |= (1 << 17) )
#define USART3_PCLK_EN()  ( RCC->APB1ENR |= (1 << 18) )
#define UART4_PCLK_EN()  ( RCC->APB1ENR |= (1 << 19) )
#define UART5_PCLK_EN()  ( RCC->APB1ENR |= (1 << 20) )

#define USART1_PCLK_EN()  ( RCC->APB2ENR |= (1 << 4) )
#define USART6_PCLK_EN()  ( RCC->APB2ENR |= (1 << 5) )

/*
 * Clock Enable Macros for SYSCFG peripheral
 */

#define SYSCFG_PCLK_EN()  ( RCC->APB2ENR |= (1 << 14) )


/*
 * Clock Enable Macros for GPIOx peripherals
 */

#define GPIOA_PCLK_EN()  ( RCC->AHB1ENR |= (1 << 0) )
#define GPIOB_PCLK_EN()  ( RCC->AHB1ENR |= (1 << 1) )
#define GPIOC_PCLK_EN()  ( RCC->AHB1ENR |= (1 << 2) )
#define GPIOD_PCLK_EN()  ( RCC->AHB1ENR |= (1 << 3) )
#define GPIOE_PCLK_EN()  ( RCC->AHB1ENR |= (1 << 4) )
#define GPIOF_PCLK_EN()  ( RCC->AHB1ENR |= (1 << 5) )
#define GPIOG_PCLK_EN()  ( RCC->AHB1ENR |= (1 << 6) )
#define GPIOH_PCLK_EN()  ( RCC->AHB1ENR |= (1 << 7) )

/*
 * Clock Enable Macros for I2Cx peripherals
 */

#define I2C1_PCLK_EN()  ( RCC->APB1ENR |= (1 << 21) )
#define I2C2_PCLK_EN()  ( RCC->APB1ENR |= (1 << 22) )
#define I2C3_PCLK_EN()  ( RCC->APB1ENR |= (1 << 23) )

/*
 * Clock Enable Macros for SPIx peripherals
 */

#define SPI1_PCLK_EN()  ( RCC->APB2ENR |= (1 << 12) )
#define SPI4_PCLK_EN()  ( RCC->APB2ENR |= (1 << 13) )
#define SPI2_PCLK_EN()  ( RCC->APB1ENR |= (1 << 14) )
#define SPI3_PCLK_EN()  ( RCC->APB1ENR |= (1 << 15) )


/*
 * Clock Enable Macros for USARTx peripherals
 */

#define USART2_PCLK_EN()  ( RCC->APB1ENR |= (1 << 17) )
#define USART3_PCLK_EN()  ( RCC->APB1ENR |= (1 << 18) )
#define UART4_PCLK_EN()  ( RCC->APB1ENR |= (1 << 19) )
#define UART5_PCLK_EN()  ( RCC->APB1ENR |= (1 << 20) )

#define USART1_PCLK_EN()  ( RCC->APB2ENR |= (1 << 4) )
#define USART6_PCLK_EN()  ( RCC->APB2ENR |= (1 << 5) )

/*
 * Clock Enable Macros for SYSCFG peripheral
 */

#define SYSCFG_PCLK_EN()  ( RCC->APB2ENR |= (1 << 14) )


/*
 * Clock Disable Macros for GPIOx peripherals
 */

#define GPIOA_PCLK_DI()  ( RCC->AHB1ENR &= ~(1 << 0) )
#define GPIOB_PCLK_DI()  ( RCC->AHB1ENR &= ~(1 << 1) )
#define GPIOC_PCLK_DI()  ( RCC->AHB1ENR &= ~(1 << 2) )
#define GPIOD_PCLK_DI()  ( RCC->AHB1ENR &= ~(1 << 3) )
#define GPIOE_PCLK_DI()  ( RCC->AHB1ENR &= ~(1 << 4) )
#define GPIOF_PCLK_DI()  ( RCC->AHB1ENR &= ~(1 << 5) )
#define GPIOG_PCLK_DI()  ( RCC->AHB1ENR &= ~(1 << 6) )
#define GPIOH_PCLK_DI()  ( RCC->AHB1ENR &= ~(1 << 7) )

/*
 * Clock Disable Macros for I2Cx peripherals
 */

#define I2C1_PCLK_DI()  ( RCC->APB1ENR &= ~(1 << 21) )
#define I2C2_PCLK_DI()  ( RCC->APB1ENR &= ~(1 << 22) )
#define I2C3_PCLK_DI()  ( RCC->APB1ENR &= ~(1 << 23) )

/*
 * Clock Disable Macros for SPIx peripherals
 */

#define SPI1_PCLK_DI()  ( RCC->APB2ENR &= ~(1 << 12) )
#define SPI4_PCLK_DI()  ( RCC->APB2ENR &= ~(1 << 13) )
#define SPI2_PCLK_DI()  ( RCC->APB1ENR &= ~(1 << 14) )
#define SPI3_PCLK_DI()  ( RCC->APB1ENR &= ~(1 << 15) )

/*
 * Clock Disable Macros for USARTx peripherals
 */

#define USART2_PCLK_DI()  ( RCC->APB1ENR &= ~(1 << 17) )
#define USART3_PCLK_DI()  ( RCC->APB1ENR &= ~(1 << 18) )
#define UART4_PCLK_DI()  ( RCC->APB1ENR &= ~(1 << 19) )
#define UART5_PCLK_DI()  ( RCC->APB1ENR &= ~(1 << 20) )
#define USART1_PCLK_DI()  ( RCC->APB2ENR &= ~(1 << 4) )
#define USART6_PCLK_DI()  ( RCC->APB2ENR &= ~(1 << 5) )

/*
 * Clock Disable Macros for SYSCFG peripheral
 */

#define SYSCFG_PCLK_DI()  ( RCC->APB2ENR &= ~(1 << 14) )

/*
 * Macros to reset GPIOx peripherals
 */

#define GPIOA_REG_RESET()	do{ (RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR &= ~(1 << 0)); } while(0)
#define GPIOB_REG_RESET()	do{ (RCC->AHB1RSTR |= (1 << 1)); (RCC->AHB1RSTR &= ~(1 << 1)); } while(0)
#define GPIOC_REG_RESET()	do{ (RCC->AHB1RSTR |= (1 << 2)); (RCC->AHB1RSTR &= ~(1 << 2)); } while(0)
#define GPIOD_REG_RESET()	do{ (RCC->AHB1RSTR |= (1 << 3)); (RCC->AHB1RSTR &= ~(1 << 3)); } while(0)
#define GPIOE_REG_RESET()	do{ (RCC->AHB1RSTR |= (1 << 4)); (RCC->AHB1RSTR &= ~(1 << 4)); } while(0)
#define GPIOF_REG_RESET()	do{ (RCC->AHB1RSTR |= (1 << 5)); (RCC->AHB1RSTR &= ~(1 << 5)); } while(0)
#define GPIOG_REG_RESET()	do{ (RCC->AHB1RSTR |= (1 << 6)); (RCC->AHB1RSTR &= ~(1 << 6)); } while(0)
#define GPIOH_REG_RESET()	do{ (RCC->AHB1RSTR |= (1 << 7)); (RCC->AHB1RSTR &= ~(1 << 7)); } while(0)

/*
 * Macros to EXTI GPIO Selection
 */
#define GPIO_BASEADDR_TO_CODE(x)   ((x == GPIOA) ? 0 :\
									(x == GPIOB) ? 1 :\
									(x == GPIOC) ? 2 :\
									(x == GPIOD) ? 3 :\
									(x == GPIOE) ? 4 :\
									(x == GPIOF) ? 5 :\
									(x == GPIOG) ? 6 :\
									(x == GPIOH) ? 7 :0) // It's an if statement using ternary operators
/*
 *  Macros IRQ Numbers
 */

#define IRQ_NO_EXTI0			6
#define IRQ_NO_EXTI1			7
#define IRQ_NO_EXTI2			8
#define IRQ_NO_EXTI3			9
#define IRQ_NO_EXTI4			10
#define IRQ_NO_EXTI5_9			23
#define IRQ_NO_EXTI10_15		40


// Some generic macros

#define ENABLE 			1
#define DISABLE 		0
#define SET				ENABLE
#define RESET			DISABLE
#define GPIO_PIN_SET	SET
#define GPIO_PIN_RESET	RESET

/*
 * EXIT Macros
 */





#include "stm32f446xx_gpio_driver.h"

#endif /* INC_STM32F446XX_H_ */
