#include "avr/io.h"
int temp;
void setup()
{
  DDRB=0b00000000;
  DDRD=0b11111111;
  PORTD = 0b00000000;
}

void loop()
{
  temp=PINB;
  
  if(temp & 0x0F == 0x00)
  {
    PORTD=0xFF;
  }
  
  else
  {
    PORTD=0x00;
  }
}
