#include "stm32f4xx.h"

void GPIO_Init(void);
void EXTI_Init(void);

int main(void) {
    GPIO_Init();
    EXTI_Init();

    while (1) {
    }
}

void GPIO_Init(void) {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    GPIOA->MODER |= (1 << (0 * 2)) | (1 << (4 * 2));
    GPIOA->MODER &= ~(3 << (8 * 2));
}

void EXTI_Init(void) {
    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
    SYSCFG->EXTICR[2] &= ~(0xF << 0);
    SYSCFG->EXTICR[2] |= (0 << 0);
    EXTI->IMR |= (1 << 8);
    EXTI->RTSR |= (1 << 8);
    NVIC_EnableIRQ(EXTI9_5_IRQn);
}

void EXTI9_5_IRQHandler(void) {
    if (EXTI->PR & (1 << 8)) {
        EXTI->PR |= (1 << 8);
        GPIOA->ODR ^= (1 << 0);
        GPIOA->ODR ^= (1 << 4);
    }
}
