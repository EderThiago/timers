#include"pwm.h"

void pwm_init(uint8_t canal, uint32_t frec){
    
    TIM3->CNT=0;
    TIM3->PSC=7;
    TIM3->ARR=((1000000/frec)-1);
    TIM3->EGR|=TIM_EGR_UG;
    TIM3->CR1|=TIM_CR1_CEN;
    
}
void pwm(uint8_t canal , uint8_t duty){
    if(duty>100)duty=100;

    if(canal==1) TIM3-> CCR1=((TIM3))
}
