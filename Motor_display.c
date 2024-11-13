/*
 * File:   Motor_display.c
 * Author: sagar
 *
 * Created on May 27, 2024, 11:27 AM
 */


#include <xc.h>
#define _XTAL_FREQ 20000000


void command(char a)
{
    PORTD=a;
    RC0=0;
    RC1=1;
    __delay_ms(100);
    RC1=0;
}

void data(char a)
{
    PORTD=a;
    RC0=1;
    RC1=1;
    __delay_ms(100);
    RC1=0;  
}

    void display(char a[30])
 {
    int i=0; 
    for (i=0;a[i]!='\0';i++)
    {
    data(a[i]);
    }
 }
    
void main(void) {
    ADCON1=0X0F;
    TRISC=0X00;
    TRISD=0X00;
    TRISB=0XFF;
    TRISA=0X00;
    
    command(0x01);           //clr scrn
    command(0x06);          //incrmnt cursor
    command(0x0E);          //dsplay on cursor blinking
    command(0x80);          //cursor to 1st line
    command(0x38);          //lcd 2 lines
    display("hello World");
    
    while(1)
    {
    if(RB4==0)
    {
        RA0=1;
        RA1=1;
        RA2=0;
        command(0x01);
        display("forward");
    }
    else if(RB7==0)
    {
      RA0=1;
      RA1=0;
      RA2=1;
      command(0x01);
      display("backward");
    }
    }        

    
    
    return;
}