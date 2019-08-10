#ifndef __USER_DELAY_H
#define __USER_DELAY_H
 
#ifdef __cplusplus
extern "C" {
#endif
 
#include "stm32f10x.h"
 
#define uint8_t unsigned char
#define unit16_t unsigned int
#define uint32_t unsigned long int
  
void DelayInit(void);
void DelayUs(uint32_t us);
void DelayMs(uint32_t ms);
 
#ifdef __cplusplus
}
#endif
 
#endif