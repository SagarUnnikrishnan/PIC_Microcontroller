/*
 * File:   Password.c
 * Author: sagar
 *
 * Created on May 27, 2024, 8:20 PM
 */


#include <xc.h>
#define _XTAL_FREQ 20000000
char user[5];
char pass[5]="1234";
int i;
int count=0;
int j=0;


void command(char a)
{
    PORTD=a;
    RC0=0;
    RC1=1;
    __delay_ms(100);
    RC1=0;
}

void data(char a)
{
    PORTD=a;
    RC0=1;
    RC1=1;
    __delay_ms(100);
    RC1=0;
    user[count]=a;
    count++;
    
}

    void display(char a[30])
    {
    int k=0;
    for (k=0;a[k]!='\0';k++)
    {
    data(a[k]);
    }
    }


void main(void) 
{
    ADCON1=0X0F;
    TRISC=0X00;
    TRISD=0X00;
    TRISB=0XF0;

    
    command(0x01);  //clr scrn
    command(0x06);  //incrmnt cursor
    command(0x0E);  //dsplay on cursor blinking
    command(0x80);  //cursor to 1st line
    command(0x38);  //lcd 2 lines
    
    
    while(1)
    {
      PORTB=0X0E;
      if(RB4==0)
      {
        data('0');
        while(RB4==0);
      }
      
      if(RB5==0)
      {
        data('1');
        while(RB5==0); 
      }
      
      if(RB6==0)
      {
        data('2');
        while(RB6==0); 
      }
      
      if(RB7==0)
      {
        data('3');
        while(RB7==0); 
      }
      
      
      
      
       PORTB=0X0D;
      if(RB4==0)
      {
        data('4');
        while(RB4==0);
      }
      
      if(RB5==0)
      {
        data('5');
        while(RB5==0); 
      }
      
      if(RB6==0)
      {
        data('6');
        while(RB6==0); 
      }
      
      if(RB7==0)
      {
        data('7');
        while(RB7==0); 
      }
       
       
       
       
       
        PORTB=0X0B;
      if(RB4==0)
      {
        data('8');
        while(RB4==0);
      }
      
      if(RB5==0)
      {
        data('9');
        while(RB5==0); 
      }
      
      if(RB6==0)
      {
        data('A');
        while(RB6==0); 
      }
      
      if(RB7==0)
      {
        data('B');
        while(RB7==0); 
      }
        
        
        
        
         PORTB=0X07;
      if(RB4==0)
      {
        data('C');
        while(RB4==0);
      }
      
      if(RB5==0)
      {
        data('D');
        while(RB5==0); 
      }
      
      if(RB6==0)
      {
        data('E');
        while(RB6==0); 
      }
      
      if(RB7==0)
      {
        data('F');
        while(RB7==0); 
      }
    
    if(count==4)
    {
        for(i=0;i<4;i++)                              //count used for counting no: of times user input data
        {                                             
            if (user[i]==pass[i])
            {                                         // j used for incrementing position in array for matching
              j++;
            }
        }
        if(j==4)
        {
            command(0x01);
            display("Correct pass");
            RC4=1;
            RC3=0;
            RC2=1;
        }
        else
        {
            command(0x01);
            display("Incorrect pass");   
        } 
    }
    }
    
    return;
}
