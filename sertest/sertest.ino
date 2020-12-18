int i;
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  delay(2000);
  for(i=0;i<10;i++)
  {
  Serial.println(i);
  delay(1000);
  }
}
