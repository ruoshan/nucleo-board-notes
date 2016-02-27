#include <stdint.h>
#include <stdbool.h>
#include <stm32f4xx.h>

#define LED_PIN 5
#define LED_ON()  GPIOA->BSRR |= (1 << LED_PIN)
#define LED_OFF() GPIOA->BSRR |= (1 << (LED_PIN + 16))

#define HZ 16000000

uint32_t current_ms = 0;

void SysTick_Handler() {
    current_ms += 1;
}

void delay(uint32_t ms) {
    while(true) {
        if (current_ms > ms) {
            current_ms = 0;
            break;
        }
    }
    return;
}

int main() {
    /* Enbale GPIOA clock */
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    /* Configure GPIOA pin 5 as output */
    GPIOA->MODER |= (1 << (LED_PIN << 1));
    /* Configure GPIOA pin 5 in max speed */
    GPIOA->OSPEEDR |= (3 << (LED_PIN << 1));

    SysTick_Config(HZ / 1000);
LOOP:
    LED_OFF();
    delay(1000);
    LED_ON();
    delay(1000);
    goto LOOP;
    return 0;
}
