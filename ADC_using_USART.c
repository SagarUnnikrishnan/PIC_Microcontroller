/*
 * File:   ADC_using_USART.c
 * Author: sagar
 *
 * Created on June 6, 2024, 11:21 AM
 */


#include <xc.h>
#include <stdio.h>
#define _XTAL_FREQ 20000000

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
  


void main(void) {
    TRISA=0XFF;
    TRISC=0X00;
    
    ADCON0 = 0X01;
    ADCON1 = 0X00;
    ADCON2 = 0X86;
    
    TXSTA = 0X24;
    RCSTA = 0X90;
    SPBRG = 129;
    
  int a;
  int i;
  float volt;
  char buffer[10];
  
  while (1) {
    GODONE = 1;
    while (GODONE == 1);
    a = ADRESL;
    a = a + (ADRESH << 8);


      volt=(a*5)/1023.0;
      
      sprintf(buffer,"volt=%f\r\n",volt);
      display(buffer);
    
    return;
}
}
