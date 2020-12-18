
int i;
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  delay(2000);
  for(i=0;i<100;i++)
  {
  Serial.println(i);
  delay(1000);
  }
  i=0;
}
