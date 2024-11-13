/*
 * File:   LEDusingUSART.c
 * Author: sagar
 *
 * Created on May 30, 2024, 5:32 PM
 */


#include <xc.h>
char user[1];
char green[1]="G";
char red[1]="R";
char yellow[1]="Y";
int i;



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
    TRISB=0X00;
    TRISC=0X80;
    TXSTA=0X24;
    RCSTA=0X90;
    SPBRG=129;
    while(1)
    {

        for(i=0;i<1;i++)
            {
                 user[i]=receive();
                 
            }
        
        for(i=0;user[i]!='\0';i++)
            {
              if ((user[i]==red[i]))
              { 
                  RB0=1;
              }
              else if (user[i]==green[i])
              {
                  RB2=1;
              }
  
              else if (user[i]==yellow[i])
              {
                  RB1=1;
              }
    
            }
         
    }
     
    return;
}