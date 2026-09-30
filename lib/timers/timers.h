#include"stm32f103xb.h"
#ifndef TIMERS_H
#define TIMERS_H

void delay_init(void);
void delay_us(uint32_t us);
void delay_ms(uint32_t ms);
void timer_init();
uint32_t timer_millis();












#endif