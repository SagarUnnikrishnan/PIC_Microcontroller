/*
 * File:   PWM.c
 * Author: sagar
 *
 * Created on June 4, 2024, 11:56 AM
 */


#include <xc.h>
#define _XTAL_FREQ 20000000

void data(char a)
{
    PORTD=a;
    RC6=1;
    RC7=1;
    __delay_ms(100);
    RC7=0;
}

void command(char a)
{
    PORTD=a;
    RC6=0;
    RC7=1;
    __delay_ms(100);
    RC7=0;
}

void display(char a[20])
{
    int i=0;
    for(i=0;i<15;i++)
    {
        data(a[i]);
    }
    
}
void main(void) {
    TRISC=0X08;
    TRISD=0X00;
    TRISB=0XFF;
    
    ADCON1=0X0F;
    T2CON=0X7F;
    CCP1CON=0X0F;
    
    
    
    command(0x01);  
    command(0x06);  
    command(0x0E); 
    command(0x80);  
    command(0x38); 
    unsigned int r;
    RC2=0;
    while(1)
{
        for(r=0;r<255;r++)
        {
            CCPR1L=r;
            __delay_ms(10);
        }
        
         for(r=255;r>0;r--)
        {
            CCPR1L=r;
            __delay_ms(10);
        }
        
   /* if(RC3==0)
    {
        command(0x01);
        CCPR1L=0X40;
        display("25% Duty Cycle");
    }
    
    else if(RB3==0)
    {
        command(0x01);
        CCPR1L=0X80;
        display("50% Duty Cycle");
    }
    
    else if(RB5==0)
    {
        command(0x01);
        CCPR1L=0XC0;
        display("75% Duty Cycle");
    }*/
}
    return;
}
