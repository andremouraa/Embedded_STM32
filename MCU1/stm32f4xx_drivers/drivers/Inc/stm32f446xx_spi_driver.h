/*
 * stm32f446xx_sp_driver.h
 *
 *  Created on: Jul 06, 2020
 *      Author: Andre Moura
 */

/*
 * Configuration structure for SPIx peripheral
 */

typedef struct
{
	uint8_t SPI_DeviceMode;			/*!< possible value from @SPI_DEVICE_MODES >*/
	uint8_t SPI_BusConfig;			/*!< possible value from @SPI_BUSCONFIG >*/
	uint8_t SPI_SlckSpeed;			/*!< possible value from @SPI_SCLK SPEED >*/
	uint8_t SPI_DFF;				/*!< possible value from @SPI_DFF >*/
	uint8_t SPI_CPOL;				/*!< possible value from @SPI_CPOL >*/
	uint8_t SPI_CPHA;				/*!< possible value from @SPI_CPHA >*/
	uint8_t SPI_SSM;				/*!< possible value from @SPI_SSM >*/

}SPI_Config_t;

/*
 * Handle structure for SPIx peripheral
 */

typedef struct
{
	SPI_RegDef_t *pSPIx;
	SPI_Config_t SPIConfig;

}SPI_Handle_t;


// SPI Macros

/*
 *  @SPI_DEVICE_MODES
 *  SPI DEVICE MODES
 */

#define SPI_MODE_MASTER
#define SPI_MODE_SLAVE

/*
 *	@SPI_BUSCONFIG
 *	SPI BUS CONFIGURATION
 */

#define SPI_BUS_SIMPLEX			1
#define SPI_BUS_HALFDUPLEX		2
#define SPI_BUS_FULLDUPLEX		3

/*
 *	@SPI_SCLK SPEED
 *	SPI SCLK SPEED
 */

#define SPI_BAUD_DIV2		0
#define SPI_BAUD_DIV4		1
#define SPI_BAUD_DIV8		2
#define SPI_BAUD_DIV16		3
#define SPI_BAUD_DIV32		4
#define SPI_BAUD_DIV64		5
#define SPI_BAUD_DIV128		6
#define SPI_BAUD_DIV256		7

/*
 * @SPI_DFF
 * SPI DATA FRAME FORMAT
 */

#define SPI_DFF8			0
#define SPI_DFF16			1

/*
 * @SPI_CPOL
 * SPI CLOCK POLARITY
 */

#define SPI_CPOL_IDLE_LOW	0
#define SPI_CPOL_IDLE_HIGH	1

/*
 * @SPI_CPHA
 * SPI CLOCK PHASE
 */
#define SPI_CPHA_1ST_EDGE	0
#define SPI_CPHA_2ND_EDGE	1

/*
 * @SPI_SSM
 * SPI SOFTWARE SLAVE MANAGEMENT
 */

#define SPI_SSM_DI			0
#define SPI_SSM_EN			1



/*********************************
 * APIs supported by this driver *
 *********************************/

// Clock Setup

void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi);

// Init and De-Init

void SPI_Init(SPI_Handle_t *pSPIHandle);
void SPI_DeInit(SPI_RegDef_t *pSPIx);

// Data Send and Receive

void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t Len);
void SPI_ReceiveData(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t Len);

// IRQ Configuration and ISR Handling

void SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);
void SPI_IRQPriorityConfig (uint8_t IRQNumber, uint8_t IRQPriority);
void SPI_IRQHandling(SPI_Handle_t *pHandle);



