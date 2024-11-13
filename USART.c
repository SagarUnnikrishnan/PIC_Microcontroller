/*
 * File:   USART.c
 * Author: sagar
 *
 * Created on May 29, 2024, 11:57 AM
 */


#include <xc.h>

void transmit(char a)
{
  while(TXIF==0);
  TXREG=a;
  TXIF=0;
      
}

char receive()
{
    while(RCIF==0);
    return RCREG;
        
}

void display(char a[20])
{
   int i=0;
   for(i=0;a[i]!='\0';i++)
   {
       transmit(a[i]);
   }
}

void main(void) {
    TRISC=0X80;
    TXSTA=0X24;
    RCSTA=0X90;
    SPBRG=129;
    //display("Hello");
   
    while(1)
    {
        char a;
        a=receive();
        transmit(a);
    }
    return;
}
