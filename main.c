#include <stdint.h>

typedef struct {
    volatile uint32_t CR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;
    volatile uint32_t APB2RSTR;
    volatile uint32_t APB1RSTR;
    volatile uint32_t AHBENR;
    volatile uint32_t APB2ENR;
    volatile uint32_t APB1ENR;
} RCC_TypeDef;

typedef struct {
    volatile uint32_t CRL;
    volatile uint32_t CRH;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t BRR;
    volatile uint32_t LCKR;
} GPIO_TypeDef;


#define RCC     ((RCC_TypeDef*)  0x40021000)
#define GPIOC   ((GPIO_TypeDef*)0x40011000)

// simple delay with while
void delay(volatile uint32_t count){
    while(count--);
}

int main(void){
    // Enable clock for GPIOC
    RCC->APB2ENR |= (1 << 4);

    // Configure PC13 as output (CRH bits 23:20)
    GPIOC->CRH &= ~(0xF << 20);  // clear
    GPIOC->CRH |=  (0x2 << 20);  // MODE=10 (2MHz), CNF=00

    while(1){
        // LED ON (active LOW)
        GPIOC->BRR = (1 << 13);

        delay(500000);

        // LED OFF
        GPIOC->BSRR = (1 << 13);

        delay(500000);
    }
}