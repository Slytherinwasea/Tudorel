#include <LedControl.h>

int DIN = 5;
int CS =  6;
int CLK = 7;

byte a[8]=     {B00011000,B00111100,B01111110,B11111111,B00011000,B00011000,B00011000,B00011000,};
LedControl lc=LedControl(DIN,CLK,CS,0);

void setup(){
 lc.shutdown(0,false);       //The MAX72XX is in power-saving mode on startup
 lc.setIntensity(0,15);      // Set the brightness to maximum value
 lc.clearDisplay(0);         // and clear the display
}

void loop(){ 

    byte b[8]=   {B00011000,B00111100,B01111110,B11111111,B00011000,B00011000,B00011000,B00011000,};
   printByte(b);
     
    delay(500);

    printEduc8s();
   
    lc.clearDisplay(0);
    
    delay(150);
}

void printEduc8s()
{
  printByte(a);
  delay(500);
}

void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}
