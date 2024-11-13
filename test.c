 /*
 * File:   test.c
 * Author: sagar
 *
 * Created on May 15, 2024, 12:36 PM
 */


#include <xc.h>
#define _XTAL_FREQ 20000000

void main(void) {
    TRISD=0X00;
    PORTD=0X00;
    while(1)
    {
        PORTD=0XAA;
        __delay_ms(100);
        PORTD=0X55;
        __delay_ms(100);
 
    
    
    }
            
    return;
}
