/*
 * File:   LED_blink_UsingUSART.c
 * Author: sagar
 *
 * Created on May 31, 2024, 11:50 AM
 */


#include <xc.h>
#define _XTAL_FREQ 20000000

void timer()
{
    while(TMR0IF==0);
    TMR0L=60;
    TMR0IF=0;
}
void main(void) {
    TRISB=0X00;
    T0CON=0XC7;
    int i=0;
    while(1)
    {
        RB1=1;
        for(i=0;i<100;i++)
        {
        timer();
        
        }
        RB1=0;
        for(i=0;i<100;i++)
        {
        timer();
        
        }
    }
    return;
}
