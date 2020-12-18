char temp;
void setup()
{
  Serial.begin(9600);
}


void loop()
{
   DDRB = (1<<MISO);
  SPCR = (1<<SPE);
  while(!(SPSR & (1<<SPIF)));
  temp = SPDR;
  Serial.println(temp);
  delay(1000);
  
}
