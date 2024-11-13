/*
 * File:   4PUSHBUTTONS.c
 * Author: sagar
 *
 * Created on May 17, 2024, 10:46 AM
 */


#include <xc.h>
#define _XTAL_FREQ 20000000

void main(void) {
    TRISC=0XFF;
    TRISB=0X00;
   
    while(1)
    {
      if(RC0==0)
      {
      PORTB=0XFF;
      }
      
      if(RC1==0)
      {
       PORTB=0XFF;   
       __delay_ms(1000);
       PORTB=0X00;
       __delay_ms(1000);
      }
      
      if(RC2==0)
      {
       int i;
       for(i=0;i<8;i++)
       {
       PORTB=0X01<<i;
       __delay_ms(100);
       }
      }
       if(RC3==0)
      {
       int i;
       for(i=0;i<8;i++)
       {
       PORTB=0X80>>i;
       __delay_ms(100);
       }
      }
    }
    
    return;
}
