/*
 * File:   CAPSLOCK.c
 * Author: sagar
 *
 * Created on June 2, 2024, 2:41 PM
 */


#include <xc.h>

void transmit(char ch) 
{
    while (TXIF == 0);
    TXREG = ch;
    TXIF = 0;

}

char receive() 
{
    while (RCIF == 0);
    return RCREG;
}

void display(char ch[20]) 
{
    
    int i = 0;
    for (i = 0; ch[i] != '\0'; i++) 
    {
        transmit(ch[i]);
    }
}

void CAPS(char ch) {
    if (ch >= 'a' && ch <= 'z') 
    {
        ch = ch - 32;
        transmit(ch);
    } 
    else 
    {
        display("Invalid");
    }
    
    return;
}

void main(void) {
    TRISC = 0X80;
    TXSTA = 0X24;
    RCSTA = 0X90;
    SPBRG = 129;
    while (1) 
    {
      CAPS(receive());
    }

    return;
}
