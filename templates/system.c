void setClock_24_HSE (void) {

    RCC -> CR |= RCC_CR_HSEON;
    while ((RCC -> CR & RCC_CR_HSERDY) == 0);

    RCC -> CFGR |= RCC_CFGR_PLLMULL3; //x3
    RCC -> CFGR2 |= RCC_CFGR2_PREDIV1_DIV1; //Not divide
    RCC -> CFGR |= RCC_CFGR_PLLXTPRE_PREDIV1; //Not divide again
    RCC -> CFGR |= RCC_CFGR_PLLSRC; //Clocks from PREDIV1
    RCC -> CR |= RCC_CR_PLLON;
    while ((RCC -> CR & RCC_CR_PLLRDY) == 0);
    RCC -> CFGR |= RCC_CFGR_SW_PLL;
    
}

void SystemInit(void) {
  setClock_24_HSE();
}
