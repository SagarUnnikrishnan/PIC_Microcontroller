/*
 * File:   Motor.c
 * Author: sagar
 *
 * Created on May 17, 2024, 12:53 PM
 */


#include <xc.h>

void main(void) {
    TRISC=0X00;
    while(1){
    RC0=1;
    RC1=0;
    RC2=1;
    
    RC3=1;
    RC4=0;
    RC5=1;
    }
 
    return;
}
