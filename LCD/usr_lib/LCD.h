#ifndef __LCD_H
#define __LCD_H
  
  #include "stm32f10x.h"
  
  //************************************
  // config LCD 
  //************************************
  
  #define SET_LOW(a ,b) a &= ~b;
  #define SET_HIGH(a, b) a |= b;

  #define LCD_CONFIG GPIOB->ODR
  #define LCD_DATA GPIOA->ODR

  #define LCD_DATA_MASK 0xFF
  #define LCD_RS (1 << 12) 
  #define LCD_RW (1 << 13)
  #define LCD_EN (1 << 14)
  #define LCD_D0 (1 << 0)
  #define LCD_D1 (1 << 1)
  #define LCD_D2 (1 << 2)
  #define LCD_D3 (1 << 3)
  #define LCD_D4 (1 << 4)
  #define LCD_D5 (1 << 5)
  #define LCD_D6 (1 << 6)
  #define LCD_D7 (1 << 7)
  
  //************************************
  // config PORTA, PORTB pin out for LCD
  //************************************  
  #define IOPA (1 << 2)
  #define IOPB (1 << 3)
  
  #define OUT_MODE_50HZ (0x3)
  #define MODE12_SHIFT (16)
  #define MODE13_SHIFT (20)
  #define MODE14_SHIFT (24)
  #define MODE15_SHIFT (28)
  #define MODE0_SHIFT (0)
  #define MODE1_SHIFT (4)
  #define MODE2_SHIFT (8)
  #define MODE3_SHIFT (12)
  #define MODE4_SHIFT (16)
  #define MODE5_SHIFT (20)
  #define MODE6_SHIFT (24)
  #define MODE7_SHIFT (28)
  
  
  
  //************************************
  // LCD function
  //************************************
  void LCD_SendBit(uint8_t bit);
  void LCD_SendCmd(uint8_t cmd);
  void LCD_Putc(uint8_t c);
  void LCD_Puts(char* s);
  void LCD_ClrScr();
  void LCD_Init();
  
#endif