void setClock_24_MSI_LSE (void) {

    RCC -> CR |= RCC_CR_HSION;
    while ((RCC -> CR & RCC_CR_HSIRDY) == 0);
    RCC -> CFGR = ((RCC->CFGR & ~RCC_CFGR_SW_Msk) | RCC_CFGR_SW_HSI);

    RCC -> CR &= ~RCC_CR_MSION_Msk;
    while ((RCC -> CR & RCC_CR_MSIRDY) != 0);
    RCC -> CR &= ~RCC_CR_MSIRANGE_Msk;
    RCC -> CR |= (0b1011 << RCC_CR_MSIRANGE_Pos);
    RCC -> CR |= RCC_CR_MSIRGSEL;
    RCC -> APB1ENR1 |= RCC_APB1ENR1_PWREN;
    PWR -> CR1 |= PWR_CR1_DBP;
    RCC -> BDCR |= (0b11 << RCC_BDCR_LSEDRV_Pos);
    RCC -> BDCR |= RCC_BDCR_LSEON;
    while ((RCC->BDCR & RCC_BDCR_LSERDY) == 0);
    RCC -> CR |= RCC_CR_MSIPLLEN;
    RCC -> CR |= RCC_CR_MSION;
    while ((RCC -> CR & RCC_CR_MSIRDY) == 0);
    RCC -> CFGR |= ( 0b1011 << RCC_CFGR_HPRE_Pos);
    RCC -> CFGR = ((RCC->CFGR & ~RCC_CFGR_SW_Msk) | RCC_CFGR_SW_MSI);
}

void SystemInit(void) {
  setClock_24_MSI_LSE();
}
