#include <SPI.h>

void setup()
{
  SPI.begin(); //begin SPI 
  pinMode(SS,OUTPUT);
  digitalWrite(SS,HIGH);
  //SPI.setClockDivider(SPI_CLOCK_DIV8);
}


void loop()
{
  digitalWrite(SS,LOW);
  SPI.transfer('A');
  digitalWrite(SS,HIGH);
  delay(1000);
  
}
