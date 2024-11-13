/*
 * File:   Interrupt.c
 * Author: sagar
 *
 * Created on June 6, 2024, 12:24 PM
 */


#include <xc.h>
#define _XTAL_FREQ 20000000

void main(void) {
    TRISD=0X00;
    TRISC=0X00;
    TRISB=0XFF;
    ADCON1=0X0F;
    
    GIE=1;
    PEIE=1;
    INT0IE=1;
    
    int i;
    while(1)
    {
        
        for(i=0;i<8;i++)
        {
            PORTC=0X00;
            PORTD=0X01<<i;
            __delay_ms(1000);
        }
    }                    
    
    return;
}
void interrupt _isr()               //interrupt service routine
{
    if(INT0IF==1)
    {
        
        for(int i=0;i<19;i++)
        {
        PORTC=~PORTC;
        __delay_ms(500);
        }
        INT0IF=0;
        
    }
}