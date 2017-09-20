#include <stm32l432xx.h>
#include <core_cm4.h>
#include "system.c"

void badDelay ( uint32_t x ) {
  while (x--);
}

void initLeds(void) {
  RCC -> AHB2ENR |= RCC_AHB2ENR_GPIOBEN;

  GPIOB -> MODER &= ~GPIO_MODER_MODE3_Msk;
  GPIOB -> MODER |= ( 0b01 << GPIO_MODER_MODE3_Pos);
  GPIOB -> OTYPER &= ~GPIO_OTYPER_OT_3;
  GPIOB -> PUPDR &= ~GPIO_PUPDR_PUPD3_Msk;
}

int main(void)
{
  initLeds();
  while (1)
  {
      badDelay(1e5);
      GPIOB -> ODR ^= GPIO_ODR_OD3;
  }
}
