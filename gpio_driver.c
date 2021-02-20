
#include "gpio_driver.h"

void  GPIO_PeriClockControl(Gpio_RegDef_t *pGPIOx,uint8_t EnorDi) //EnorDi- Enable or disable
{ 	if(EnorDi==ENABLE)
	{
	if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_EN();
		}
	else if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_EN();
		}
	else if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_EN();
		}
	else if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_EN();
		}
	else if(pGPIOx == GPIOE)
		{
			GPIOE_PCLK_EN();
		}
	}
	else
	{
    //need to do
	}
}

//to do initialization

void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	//1. Configuration of the MODE of GPIOx
	uint32_t temp=0;

	temp=(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode<< (2* pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->MODER&=~(0x3<<(2* pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));  //~(0x3) -> ~(11) -> 00 so you are reset the value.
	pGPIOHandle->pGPIOx->MODER|=temp;  //set the value

	//2. Configure the speed   //pg282
	temp= ((pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed<<2* pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDR&=~(0x3<<(2* pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDR|=temp;

	//3. GPIO port pull-up/pull-down register

	temp=(pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl<<(2* pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR&=~(0x3<<(2* pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR|=temp;

	//4.GPIO port output type register

	temp=(pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType<<(pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OTYPER&=~(0x1<<pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OTYPER|=temp;

	//5. GPIO alternate function low register (pg 285)
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode== GPIO_MODE_ALTFN)
	{
	uint8_t temp1,temp2;
	temp1= pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber/8;
	temp2= pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber%8;
	pGPIOHandle->pGPIOx->AFR[temp1] &=~(0xf<<(4*temp2));
	pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFuncMode<<(4*temp2));
	}
}

void GPIO_DeInit(Gpio_RegDef_t *pGPIOx)
{
	//pg 281/1749 ,233/1749

	if(pGPIOx == GPIOA)
	{
		GPIOA_REG_RESET();
	}
	if(pGPIOx == GPIOB)
	{
		GPIOB_REG_RESET();
	}
	if(pGPIOx == GPIOB)
	{
		GPIOC_REG_RESET();
	}
}

//to read

uint8_t GPIO_ReadFromInputPin(Gpio_RegDef_t *pGPIOx,uint8_t PinNumber)
{
    uint8_t value;
   //value = (uint8_t)pGPIOx ->IDR;
    // maskingggggggggggg
    value = ( uint8_t)((pGPIOx->IDR>>PinNumber)& 0x0000001);
    return value;
}


uint16_t GPIO_ReadFromInputPort(Gpio_RegDef_t *pGPIOx)
{
	uint16_t value;
	value = pGPIOx->IDR;
	return value;
}

//to write

void GPIO_WriteToOutputPin(Gpio_RegDef_t *pGPIOx,uint8_t PinNumber, uint8_t value)
{
  if(value == GPIO_PIN_SET)
  {
	  pGPIOx ->ODR |= (1<<PinNumber);

  }else
  {
	  pGPIOx ->ODR &= ~(1<<PinNumber);

  }
}
void GPIO_WriteToOutputPort(Gpio_RegDef_t *pGPIOx,uint16_t value)
{
	pGPIOx->ODR = value;
}

//to toggle

void GPIO_ToggleOutputPin(Gpio_RegDef_t *pGPIOx,uint8_t PinNumber)
{
	pGPIOx->ODR^=(1<<PinNumber);
}

