#include <SPI.h>

void setup()
{
  pinMode(MISO,OUTPUT);
  Serial.begin(9600);
  
  //turn on the SPI in slave mode
  
  SPCR |= _BV(SPE);
 
 SPI.attachInterrupt(); 
}


// if interrupt occurs then the following ISR is executed

ISR (SPI_STC_vect)
{
  char c ;
  c =SPDR;
  Serial.println(c);
}

void loop()
{
  while(1); // stay here
  
}
