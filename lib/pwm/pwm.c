#include"pwm.h"

void pwm_init(uint8_t canal, uint32_t frec){
    RCC->APB2ENR|=RCC_APB2ENR_IOPAEN;
    RCC->APB2ENR|=RCC_APB2ENR_IOPBEN;
    RCC->APB1ENR|=RCC_APB1ENR_TIM3EN;
    TIM3->CNT=0;
    TIM3->PSC=7;
    TIM3->ARR=0x4f;
}
void pwm(uint8_t canal , uint8_t duty){}
