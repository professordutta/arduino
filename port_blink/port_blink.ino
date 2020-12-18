int m;
void setup()
{
  DDRB = B00111111;
}


void loop()
{
  PORTB = B00111111;
  for(m=0;m<6;m++)
  {
  PORTB = PORTB<<1;
  delay(1000);
  }
}
