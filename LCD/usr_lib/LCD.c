#include <stm32f10x.h>
#include "LCD.h"
#include "user_delay.h"

void LCD_Enable(){
  
  SET_HIGH(LCD_CONFIG, LCD_EN);
  DelayUs(100);
  SET_LOW(LCD_CONFIG, LCD_EN);
  DelayUs(100);
}


void LCD_SendBit(uint8_t bit) {
  
  LCD_DATA &= LCD_DATA_MASK;
  LCD_DATA |= bit;
  LCD_Enable();
}

void LCD_SendCmd(uint8_t cmd){
  
  SET_LOW(LCD_CONFIG, LCD_RS);
  SET_LOW(LCD_CONFIG, LCD_RW);
  
  LCD_SendBit(cmd);
  LCD_Enable();
}

void LCD_Putc(uint8_t c){
  DelayMs(2);
  SET_HIGH(LCD_CONFIG, LCD_RS);
  SET_LOW(LCD_CONFIG, LCD_RW);
  
  LCD_SendBit(c);
}

void LCD_Puts(char* s) {
  while(*s != 0) {
    LCD_Putc(*s);
    s++;
  }
}

void LCD_ClrScr() {
  LCD_SendCmd(0x01);
}

void LCD_init(){
    SET_LOW(LCD_CONFIG, LCD_RS);
    SET_LOW(LCD_CONFIG, LCD_EN);
    DelayMs(40);
    LCD_SendBit(0x30);
    DelayMs(5);
    LCD_SendBit(0x30);
    DelayMs(5);
    LCD_SendBit(0x30);
    DelayMs(5);
    LCD_SendBit((0x2 << 4) | (2 << 3)); // 0x28 = 4-bit, 2-line, 5x8 font size
    DelayMs(5);
    LCD_SendBit((0xC0) | (1 << 1) | (0 << 0)); // 0x0C = Turn ON display,  cursor, no blinking
    DelayMs(8);
    LCD_ClrScr();         // Clear the screen
    DelayMs(5);
    LCD_SendBit(0x06); // Move from left-to-right, no shifting
    DelayMs(5);
    LCD_ClrScr();

    SET_HIGH(LCD_CONFIG, LCD_RS);
}