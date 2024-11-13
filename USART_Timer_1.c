/*
 * File:   USART_Timer_1.c
 * Author: sagar
 *
 * Created on June 3, 2024, 11:59 AM
 */


#include <xc.h>

void timer()
{
    while(TMR1IF==0);
    TMR1H=0XE7;
    TMR1L=0X96;
    TMR1IF=0;
}

void main(void) {
    TRISD=0X00;
    TRISE=0X00;
    T1CON=0X71;
    int i;
    while(1)
    {
      RE0=1;
        for(i=0;i<100;i++)
        {
        timer();
        
        }
        RE0=0;
        for(i=0;i<100;i++)
        {
        timer();
        
        }
    }
    return;
}  
    