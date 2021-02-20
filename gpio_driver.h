#ifndef INC_GPIO_DRIVER_H_
#define INC_GPIO_DRIVER_H_

#include<stdint.h>
#include "stm32f4xx.h"

typedef struct
{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAltFuncMode;

}GPIO_PinConfig_t;


typedef struct
{

	Gpio_RegDef_t *pGPIOx;
	GPIO_PinConfig_t GPIO_PinConfig;

}GPIO_Handle_t;

//GPIO Pin Numbers

#define GPIO_PIN_NO_0 0
#define GPIO_PIN_NO_1 1
#define GPIO_PIN_NO_2 2
#define GPIO_PIN_NO_3 3
#define GPIO_PIN_NO_4 4
#define GPIO_PIN_NO_5 5
#define GPIO_PIN_NO_6 6
#define GPIO_PIN_NO_7 7
#define GPIO_PIN_NO_8 8
#define GPIO_PIN_NO_9 9
#define GPIO_PIN_NO_10 10
#define GPIO_PIN_NO_11 11
#define GPIO_PIN_NO_12 12
#define GPIO_PIN_NO_13 13
#define GPIO_PIN_NO_14 14
#define GPIO_PIN_NO_15 15

//Modes of GPIOx (pg281/1749)

#define GPIO_MODE_IN 0
#define GPIO_MODE_OUT 1
#define GPIO_MODE_ALTFN 2
#define GPIO_MODE_ANALOG 3

//GPIO port output type
#define GPIO_OP_TYPE_PP 0
#define GPIO_OP_TYPE_OD 1

//Speed of GPIOx (pg282/1749)
#define GPIO_SPEED_LOW 0
#define GPIO_SPEED_MEDIUM 1
#define GPIO_SPEED_FAST 2
#define GPIO_SPEED_VERY 3

//GPIO pin for pull up or pull down
#define GPIO_NO_PUPD 0
#define GPIO_NO_PU 1
#define GPIO_NO_PD 2

//to control clock setting
void  GPIO_PeriClockControl(Gpio_RegDef_t *pGPIOx,uint8_t EnorDi);//EnorDi- Enable or disable


//to do initialization

void GPIO_Init(GPIO_Handle_t *pGPIOHandle);

void GPIO_DeInit(Gpio_RegDef_t *pGPIOx); //pg 281/1749 ,233/1749

//to read

uint8_t GPIO_ReadFromInputPin(Gpio_RegDef_t *pGPIOx,uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(Gpio_RegDef_t *pGPIOx);

//to write

void GPIO_WriteToOutputPin(Gpio_RegDef_t *pGPIOx,uint8_t PinNumber, uint8_t value);
void GPIO_WriteToOutputPort(Gpio_RegDef_t *pGPIOx,uint16_t value);

//to toggle



void GPIO_ToggleOutputPin(Gpio_RegDef_t *pGPIOx,uint8_t PinNumber);
#endif
