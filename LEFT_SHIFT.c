/*
 * File:   LEFT SHIFT.c
 * Author: sagar
 *
 * Created on May 16, 2024, 11:44 AM
 */


#include <xc.h>
#define _XTAL_FREQ 20000000

void main(void) {
    TRISB=0X00;
    int i;
    while(1)
    {
        for(i=0;i<8;i++)
        {
            PORTB=0X01<<i;
            __delay_ms(100);
        }
    }                    
    
    return;
}
