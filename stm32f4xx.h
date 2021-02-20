//MCU Specific Header File
#ifndef STM32F4XX_H_
#define STM32F4XX_H_

#include<stdint.h>

#define ENABLE 1
#define DISBALE 0
#define SET ENABLE
#define RESET DISABLE
// Defining Memory Base Addresses
#define SRAM1_BASEADDR 0x20000000U
#define SRAM2_BASEADDR 0x2001C000U
#define FLASH_BASEADDR 0x08000000U
#define ROM_BASEADDR 0x1FFF0000U

// Defining peripheral Base Addresses

#define APB1_BASEADDR 0x40000000U
#define APB2_BASEADDR 0x40010000U
#define AHB1_BASEADDR 0x40020000U

// Defining Peripherals' Base Address which is hanging on to AHB1 Bus

//#define GPIOA_BASEADDR 0x40020000U
//#define GPIOB_BASEADDR 0x40020400U

#define GPIOA_BASEADDR (AHB1_BASEADDR+ 0x0U)
#define GPIOB_BASEADDR (AHB1_BASEADDR+0x0400U)
#define GPIOC_BASEADDR (AHB1_BASEADDR+0x0800U)
#define GPIOD_BASEADDR (AHB1_BASEADDR+0x0C00U)
#define GPIOE_BASEADDR (AHB1_BASEADDR+0x1000U)
#define RCC_BASEADDR (AHB1_BASEADDR+0x3800UL) //0x40023800

//defining peripherals base address which are hanging on to APB1 bus

#define TIM2 (APB1_BASEADDR + 0x0000)
#define TIM3 (APB1_BASEADDR + 0x0400)
#define TIM4 (APB1_BASEADDR + 0x0800)
#define TIM5 (APB1_BASEADDR + 0x0C00)
#define TIM6 (APB1_BASEADDR + 0x1000)
#define TIM7 (APB1_BASEADDR + 0x1400)
#define TIM12 (APB1_BASEADDR + 0x1800)
#define TIM13 (APB1_BASEADDR + 0x1C00)
#define TIM14 (APB1_BASEADDR + 0x2000)
#define RTC_BKP_REG (APB1_BASEADDR + 0x2800)
#define WWDG (APB1_BASEADDR + 0x2C00)
#define IWDG (APB1_BASEADDR + 0x3000)
#define I2S2ext (APB1_BASEADDR + 0x3400)
#define I2S2 (APB1_BASEADDR + 0x3800)
#define I2S3 (APB1_BASEADDR + 0x3C00)
#define I2S3ext (APB1_BASEADDR + 0x4000)
#define USART2 (APB1_BASEADDR + 0x4400)
#define USART3 (APB1_BASEADDR + 0x4800)
#define UART4 (APB1_BASEADDR + 0x4C00)
#define UART5 (APB1_BASEADDR + 0x5000)
#define I2C1 (APB1_BASEADDR + 0x5400)
#define I2C2 (APB1_BASEADDR + 0x5800)
#define I2C3 (APB1_BASEADDR + 0x5C00)
#define CAN1 (APB1_BASEADDR + 0x6400)
#define CAN2 (APB1_BASEADDR + 0x6800)
#define PWR (APB1_BASEADDR + 0x7000)
#define DAC (APB1_BASEADDR + 0x7400)
#define UART7 (APB1_BASEADDR + 0x7800)
#define UART8 (APB1_BASEADDR + 0x7C00)

//defining peripherals base address which are hanging on to APB2 bus

#define TIM1 (APB2_BASEADDR + 0x0000)
#define TIM8 (APB2_BASEADDR + 0x0400)
#define USART1 (APB2_BASEADDR + 0x1000)
#define USART6 (APB2_BASEADDR + 0x1400)
#define ADC1_ADC2_ADC3 (APB2_BASEADDR + 0x2000)
#define SDIO (APB2_BASEADDR + 0x2C00)
#define SPI1 (APB2_BASEADDR + 0x3000)
#define SPI4 (APB2_BASEADDR + 0x3400)
#define SYSCFG (APB2_BASEADDR + 0x3800)
#define EXTI (APB2_BASEADDR + 0x3C00)
#define TIM9 (APB2_BASEADDR + 0x4000)
#define TIM10 (APB2_BASEADDR + 0x4400)
#define TIM11 (APB2_BASEADDR + 0x4800)
#define SPI5 (APB2_BASEADDR + 0x5000)
#define SPI6 (APB2_BASEADDR + 0x5400)



#define _vo volatile
typedef struct
{
	_vo uint32_t MODER;
	_vo uint32_t OTYPER;
	_vo uint32_t OSPEEDR;
	_vo uint32_t PUPDR;
	_vo uint32_t IDR;
	_vo uint32_t ODR;
	_vo uint32_t BSRR;
	_vo uint32_t LCKR;
	_vo uint32_t AFR[2];
}Gpio_RegDef_t; //GPIOx - base address of x typecasted to the structure

#define GPIOA ((Gpio_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB ((Gpio_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC ((Gpio_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD ((Gpio_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE ((Gpio_RegDef_t*)GPIOE_BASEADDR)



//Some generic macros
#define ENABLE           1
#define DISABLE          0
#define SET              ENABLE
#define RESET            DISABLE
#define GPIO_PIN_SET     SET
#define GPIO_PIN_RESET   RESET


typedef struct
{
	_vo uint32_t CR;
	_vo uint32_t PLLCFGR;
	_vo uint32_t CFGR;
	_vo uint32_t CIR;
	_vo uint32_t AHB1RSTR;
	_vo uint32_t AHB2RSTR;
	_vo uint32_t AHB3RSTR;
	uint32_t Reserved0;
	_vo uint32_t APB1RSTR;
	_vo uint32_t APB2RSTR;
	uint32_t Reserved1;
	uint32_t Reserved2;
	_vo uint32_t AHB1ENR;
	_vo uint32_t AHB2ENR;
	_vo uint32_t AHB3ENR;
	uint32_t Reserved3;
	_vo uint32_t APB1ENR;
	_vo uint32_t APB2ENR;
	uint32_t Reserved4;
	uint32_t Reserved5;
	_vo uint32_t AHB1LPENR;
	_vo uint32_t AHB2LPENR;
	_vo uint32_t AHB3LPENR;
	uint32_t Reserved6;
	_vo uint32_t APB1LPENR;
	_vo uint32_t APB2LPENR;
	uint32_t Reserved7;
	uint32_t Reserved8;
	_vo uint32_t BDCR;
	_vo uint32_t CSR;
	uint32_t Reserved9;
	uint32_t Reserved10;
	_vo uint32_t SSCGR;
	_vo uint32_t PLLI2SCFGR;
}Rcc_RegDef_t;
#define RCC ((Rcc_RegDef_t*)RCC_BASEADDR)
//Peripheral Clock Enable
#define GPIOA_PCLK_EN() (RCC->AHB1ENR|=(1<<0))
#define GPIOB_PCLK_EN() (RCC->AHB1ENR|=(1<<1))
#define GPIOC_PCLK_EN() (RCC->AHB1ENR|=(1<<2))
#define GPIOD_PCLK_EN() (RCC->AHB1ENR|=(1<<3))
#define GPIOE_PCLK_EN() (RCC->AHB1ENR|=(1<<4))
//Peripheral clock disable
#define GPIOA_PCLK_DIS() (RCC->AHB1ENR&=~(1<<0))
#define GPIOB_PCLK_DIS() (RCC->AHB1ENR&=~(1<<1))
#define GPIOC_PCLK_DIS() (RCC->AHB1ENR&=~(1<<2))
#define GPIOD_PCLK_DIS() (RCC->AHB1ENR&=~(1<<3))
#define GPIOE_PCLK_DIS() (RCC->AHB1ENR&=~(1<<4))



#include "gpio_driver.h"

#endif
