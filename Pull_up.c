/*
 * File:   Pull_up.c
 * Author: sagar
 *
 * Created on May 16, 2024, 12:40 PM
 */


#include <xc.h>

void main(void) {
    TRISC=0XFF;
    TRISB=0X00;
    while(1)
    {
        if(RC3==0)
        {
            RB1=1;
        }
        else
        {
            RB1=0;
        }
    }
            
    return;
}
