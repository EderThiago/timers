#include"pwm.h"

void pwm_init(uint8_t canal, uint32_t frec){
    if(canal==1){
        RCC->APB2ENR|=RCC_APB2ENR_IOPAEN;
        GPIOA->CRL&=~(0xf<<(6*4));
        GPIOA->CRL&=~(0xb<<(6*4));
    }
    if(canal==2){
        RCC->APB2ENR|=RCC_APB2ENR_IOPAEN;
        GPIOA->CRL&=~(0xf<<(7*4));
        GPIOA->CRL&=~(0xb<<(7*4));
    }
    if(canal==3){
        RCC->APB2ENR|=RCC_APB2ENR_IOPBEN;
        GPIOB->CRL&=~(0xf<<(0*4));
        GPIOB->CRL&=~(0xb<<(0*4));
    }
    if(canal==4){
        RCC->APB2ENR|=RCC_APB2ENR_IOPBEN;
        GPIOB->CRL&=~(0xf<<(1*4));
        GPIOB->CRL&=~(0xb<<(1*4));
    }
    
    TIM3->CNT=0;
    TIM3->PSC=7;
    TIM3->ARR=((1000000/frec)-1);
    TIM3->EGR|=TIM_EGR_UG;
    TIM3->CR1|=TIM_CR1_CEN;
    
}
void pwm(uint8_t canal , uint8_t duty){
    if(duty>100)duty=100;

    if(canal==1) TIM3-> CCR1=((TIM3->ARR+1)*duty/100);
    if(canal==2) TIM3-> CCR2=((TIM3->ARR+1)*duty/100);
    if(canal==3) TIM3-> CCR3=((TIM3->ARR+1)*duty/100);
    if(canal==4) TIM3-> CCR1=((TIM3->ARR+1)*duty/100);
}
