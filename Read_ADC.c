#include "stm32f4xx.h"

void delay(uint32_t time) {
    for (uint32_t i = 0; i < time * 1000; i++) {
        
    }
}

int main(void) {
    // Enable GPIOA and ADC1 clocks
    RCC->AHB1ENR |= (1 << 0);     // GPIOAEN
    RCC->APB2ENR |= (1 << 8);     // ADC1EN

    // Set PA0 to analog mode (MODER = 11)
    GPIOA->MODER |= (3 << (0 * 2));

    // Enable ADC1
    ADC1->CR2 |= (1 << 0);        

    uint16_t adc_value;

    while (1) {
        // Select channel 0 (PA0)
        ADC1->SQR3 = 0;

        // Start conversion
        ADC1->CR2 |= (1 << 30);   

        // Wait for conversion to complete
        while (!(ADC1->SR & (1 << 1)));  

        // Read ADC value
        adc_value = ADC1->DR;

        // Toggle PA0 for indication 
        GPIOA->ODR ^= (1 << 0);
        delay(500);  // Roughly 500 ms delay
    }
}
