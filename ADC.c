/*
 * File:   ADC.c
 * Author: sagar
 *
 * Created on June 5, 2024, 11:06 AM
 */


#include <xc.h>
#include <stdio.h>
#define _XTAL_FREQ 20000000

void data(char a) {
  PORTD = a;
  RC6 = 1;
  RC7 = 1;
  __delay_ms(100);
  RC7 = 0;
}

void command(char a) {
  PORTD = a;
  RC6 = 0;
  RC7 = 1;
  __delay_ms(100);
  RC7 = 0;
}

void display(char a[]) 
{
  int i;
  for(i=0;a[i]!='\0';i++)
  {
  data(a[i]);
  }
}

void main(void) {
  TRISD = 0X00;
  TRISC = 0X00;
  TRISA = 0xFF;

  ADCON0 = 0X01;
  ADCON1 = 0X00;
  ADCON2 = 0X86;

  command(0x01);
  command(0x06);
  command(0x0E);
  command(0x80);
  command(0x38);

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
      
      sprintf(buffer,"volt=%f",volt);
      command(0x80);
      display(buffer);      
  }
}
      