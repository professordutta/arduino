void setup()
{
  
}


void loop()
{
  
  //set MOSI and SCK as o/p
  
  DDRB = (1<<MOSI) | (1<<SCK);
  
  //Enable SPI, Master, Set clock rate as fclk/16
  
  SPCR = (1<<SPE) | (1<<MSTR) | (1<<SPR0);
  SPDR ='A';
  
  while(!(SPSR & (1<<SPIF)));
  
  delay(1000);
}
