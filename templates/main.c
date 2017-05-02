#include <stm32f100xb.h>
#include <core_cm3.h>
#include "system.c"

// Эта функция умирает, если включить -O
void wait (int d) {
  int x = d*1000;
  while (x--);
}

void blinks( int x ) {
  while (1) 
  {     
    wait(24 * x );
    GPIOC->BSRR = GPIO_BSRR_BR8;    // Погасили синий
    GPIOC->BSRR = GPIO_BSRR_BS9;  // Зажгли зелёный
    wait(24 * x );
    GPIOC->BSRR = GPIO_BSRR_BR9;        // Погасили зелёный
    GPIOC->BSRR = GPIO_BSRR_BS8;  // Зажгли синий
  }
}

void enableLEDs() {
  RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;

  GPIOC->CRH &= ~GPIO_CRH_CNF8;
  GPIOC->CRH |= GPIO_CRH_MODE8_0;
  GPIOC->BSRR |= GPIO_BSRR_BR8;

  GPIOC->CRH &= ~GPIO_CRH_CNF9;
  GPIOC->CRH |= GPIO_CRH_MODE9_0;
  GPIOC->BSRR |= GPIO_BSRR_BR9;
}

void setup (void) {
  setClock_24_HSE();
  enableLEDs();
}

int main(void)
{
  setup();
  blinks( 40 );
}
