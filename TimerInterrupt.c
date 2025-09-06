#include "stm32f4xx.h"

void GPIO_Init(void);
void TIM2_Init(void);

int main(void) {
    GPIO_Init();
    TIM2_Init();

    while (1) {
    }
}

void GPIO_Init(void) {
    RCC->AHB1ENR |= (1 << 0);
    GPIOA->MODER |= (1 << 10);
}

void TIM2_Init(void) {
    RCC->APB1ENR |= (1 << 0);
    TIM2->PSC = 16000 - 1;
    TIM2->ARR = 1000 - 1;
    TIM2->DIER |= (1 << 0);
    TIM2->CR1 |= (1 << 0);
    NVIC_EnableIRQ(TIM2_IRQn);
}

void TIM2_IRQHandler(void) {
    if (TIM2->SR & (1 << 0)) {
        TIM2->SR &= ~(1 << 0);
        GPIOA->ODR ^= (1 << 5);
    }
}
