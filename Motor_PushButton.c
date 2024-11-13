/*
 * File:   Motor_PushButton.c
 * Author: sagar
 *
 * Created on May 18, 2024, 11:53 AM
 */


#include <xc.h>

void main(void) {
    TRISC=0XFF;
    TRISD=0X00;
    
    while(1)
    {
        if(RC0==0)
        {
            RD0=1;
            RD1=0;
            RD2=1;
            
            RD3=0;
        }
        
        if(RC1==0)
        {
            RD3=1;
            RD4=0;
            RD5=1;
            
            RD2=0;
                   
        }
        
        if(RC2==0)
        {
            RD0=1;
            RD1=0;
            RD2=1;
            RD3=1;
            RD4=1;
            RD5=0;
        }
        
        if(RC3==0)
        {
            RD0=0;
            RD1=1;
            RD2=1;
            RD3=1;
            RD4=0;
            RD5=1; 
        }
    }
    return;
}
