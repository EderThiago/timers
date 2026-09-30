#include "timers.h"
int t_delay=0;
int overflow=0;
void delay_init(){
    RCC->APB2ENR|=RCC_APB1ENR_TIM2EN;
    TIM2->CNT=0;
    TIM2->PSC=7;
    TIM2->ARR=0x4f;
    TIM2->CNT=0;
    TIM2->CR1=1;
    
}
void delay_us(uint32_t us){
    while(t_delay<us){
        t_delay=0x4f*overflow + TIM2->CNT;
    }
    t_delay==0;
}
void delay_ms(uint32_t ms){
    while(t_delay<(1000*ms)){
        t_delay=0x4f*overflow + TIM2->CNT;
    }
    t_delay==0;

}
void timer_init(){
    RCC->APB2ENR|=RCC_APB1ENR_TIM2EN;
    TIM2->CNT=0;
    TIM2->PSC=7;
    TIM2->ARR=0x4f;
    TIM2->CNT=0;
    TIM2->DIER|=TIM_DIER_UIE;
    TIM2->EGR|=TIM_EGR_UG;
    TIM2->SR&=~TIM_SR_UIF;
    NVIC_EnableIRQ(TIM2_IRQn);
    TIM2->CR1|=TIM_CR1_CEN;
}
uint32_t timer_millis(){
    return (TIM2->CNT + 0x4f*overflow) * 1000;
}
void TIM2_IRQHandler(){
    if(TIM2->SR&TIM_SR_UIF){
        overflow++;
        TIM2->SR&=~TIM_SR_UIF;
    }

}