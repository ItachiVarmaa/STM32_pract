//led- stm32


#include"stm32f4xx.h"
#define DELAYCOUNT (80000)
static void delay(void)
{
 uint32t_t i = 0;
 for ( i=0; i<=DELAYCOUNT; i++);
}
int main(void)
{
 SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOCEN);
 GPIOC->MODER = 0X55555555;
 while(1)
{
GPIOC->BSRR|= GPIO_BSSR_BS13;
 delay();
GPIOC->BSSR |=GPIO_BSSR_BS13;
 delay();
 }

}
