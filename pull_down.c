/*
 * File:   pull_down.c
 * Author: sagar
 *
 * Created on May 16, 2024, 5:51 PM
 */


#include <xc.h>

void main(void) {
    TRISC=0XFF;
    TRISD=0X00;
    while(1)
    {
        if(RC0==1)
        {
            RD0=1;
        }
        else
        {
            RD0=0;
        }
    }
            
    return;
}

