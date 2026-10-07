#include"stm32f103xb.h"
#include"pwm.h"
#include "adc.h"

int valorADC;
int duty;

void setup(){
    adc_init();
    pwm_init(1, 8000000);
}
void loop(){
valorADC=adc_read(1);
duty=valorADC*100/4095;
pwm(1, duty);
}