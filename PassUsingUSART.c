/*
 * File:   PassUsingUSART.c
 * Author: sagar
 *
 * Created on May 30, 2024, 11:49 AM
 */


#include <xc.h>
char user[5];
char pass[5]="1234";
int i;
int count=0;
int j=0;

void transmit(char a)
{
  while(TXIF==0);
  TXREG=a;
  TXIF=0;
      
}

void display(char a[20])
{
   int i=0;
   for(i=0;a[i]!='\0';i++)
   {
       transmit(a[i]);
   }
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
   

    while(1)
    {   j=0;
        for(i=0;i<4;i++)
          {
              user[i]=receive();
              transmit(user[i]);
               
          }
        for(i=0;i<4;i++)                              //count used for counting no: of times user input data
          {                                             
             if (user[i]==pass[i])
               {                                         // j used for incrementing position in array for matching
                  j++;
               }
          }
       
    
        if(j==4)
        {
          display("Correct pass");  
        }
        else
        {
          display("Incorrect pass");  
        }
         
    }
     
    return;
}