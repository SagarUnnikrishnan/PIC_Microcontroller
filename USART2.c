/*
 * File:   USART2.c
 * Author: sagar
 *
 * Created on May 30, 2024, 11:05 AM
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



void main(void) {
    TRISC=0X80;
    TXSTA=0X24;
    RCSTA=0X90;
    SPBRG=129;
   
    int flag=0;
    
    while(1)
    {
        char a;
        a=receive();
        
        if (a=='*')
        { 
            flag=0;
            
        }
        if(a=='#')
        {
            flag=1;
        }
        
        if(flag==0)
        {
            transmit(a);
        }
        
       
        
    }
    return;
}