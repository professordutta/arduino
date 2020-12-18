void setup()
{
  pinMode(8,OUTPUT);
  digitalWrite(8,LOW);
}

void loop()
{
  digitalWrite(8,HIGH);
  delay(30);
  digitalWrite(8,LOW);
  delay(2);
  
}
