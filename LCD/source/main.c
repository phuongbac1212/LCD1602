#include <stm32f10x.h>
#include "user_delay.h"
#include "LCD.h"

void GPIOInit() {
  
  RCC->APB2ENR |= (IOPA | IOPB);
  GPIOA->CRH = ((OUT_MODE_50HZ << MODE12_SHIFT) | (OUT_MODE_50HZ << MODE13_SHIFT) | (OUT_MODE_50HZ << MODE14_SHIFT) | (OUT_MODE_50HZ << MODE15_SHIFT));
  GPIOB->CRL = ((OUT_MODE_50HZ << MODE0_SHIFT) | (OUT_MODE_50HZ << MODE1_SHIFT) |(OUT_MODE_50HZ << MODE2_SHIFT) | (OUT_MODE_50HZ << MODE3_SHIFT) | (OUT_MODE_50HZ << MODE4_SHIFT) | (OUT_MODE_50HZ << MODE5_SHIFT) | (OUT_MODE_50HZ << MODE6_SHIFT) | (OUT_MODE_50HZ << MODE7_SHIFT));
}

int main() {
  GPIOInit();
  DelayInit();
  LCD_init();
  
  while (1) {
    LCD_SendCmd((char)0x0C);
    LCD_Puts("TEST");
    DelayMs(500);
    LCD_ClrScr();
  }
}
