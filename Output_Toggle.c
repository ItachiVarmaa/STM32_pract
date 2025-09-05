#include "stm32f4xx.h"

void delay_ms(uint32_t ms);

int main(void)
{
    RCC->AHB1ENR |= (1 << 0);
    GPIOA->MODER &= ~(3 << (5 * 2));
    GPIOA->MODER |=  (1 << (5 * 2));
    GPIOA->OTYPER &= ~(1 << 5);
    GPIOA->OSPEEDR |= (2 << (5 * 2));
    GPIOA->PUPDR &= ~(3 << (5 * 2));

    while (1)
    {
        GPIOA->ODR ^= (1 << 5);
        delay_ms(500);
    }
}

void delay_ms(uint32_t ms)
{
    for (uint32_t i = 0; i < ms * 16000; i++)
    {
        ;
    }
}
