/*
 * File:   RC_Car.c
 * Author: sagar
 *
 * Created on May 18, 2024, 12:26 PM
 */


#include <xc.h>

void main(void) {
    ADCON1=0X0F;
    TRISC=0XFF;
    TRISD=0X00;
    TRISB=0X00;
    
    while(1)
    {
        
        if(RC0==0)   //forward
        {
           if(RC2==0) //left
          {
            RD0=1;
            RD1=0;
            RD2=1;
            RD5=1;
            RD6=1;
            RD7=0;
            
            RB0=1;
            RB1=0;
            RB2=1;
            RB5=1;
            RB6=1;
            RB7=0;
          }
           
           else if(RC3==0)  //right
          {
            RB0=0;
            RB1=1;
            RB2=1;
            RB5=1;
            RB6=0;
            RB7=1;
            
            RD0=0;
            RD1=1;
            RD2=1;
            RD5=1;
            RD6=0;
            RD7=1;
           }
        
           else
           {
            RD0=1;
            RD1=0;
            RD2=1;
            RD5=1;
            RD6=1;
            RD7=0;
            
            RB0=0;
            RB1=1;
            RB2=1;
            RB5=1;
            RB6=0;
            RB7=1;
           }
           
        }
        else if(RC1==0)   //backward
        {
            RD0=0;
            RD1=1;
            RD2=1;
            RD5=1;
            RD6=0;
            RD7=1;
            
            RB0=1;
            RB1=0;
            RB2=1;
            RB5=1;
            RB6=1;
            RB7=0;
           
        }
        else
           {
               PORTD=0X00;
               PORTB=0X00;
           }
      
     }
    return;
}
