/*
 * File:   SHIFTING.c
 * Author: sagar
 *
 * Created on May 16, 2024, 11:08 AM
 */


#include <xc.h>
#define _XTAL_FREQ 20000000

void main(void) {
    TRISD=0X00;
    PORTD=0X00;
    
    while(1){
    
    PORTD=0X01;
    
     __delay_ms(100);
    PORTD=0X02;
    
    
    
    __delay_ms(100);
    PORTD=0X04;
    
    __delay_ms(100);
    PORTD=0X08;
    
    __delay_ms(100);
    PORTD=0X10;
    
    __delay_ms(100);
    PORTD=0X20;
    
    __delay_ms(100);
    PORTD=0X40;
    
    __delay_ms(100);
    PORTD=0X80;
    
    __delay_ms(100);
    }
    return;
}
