void setup()
{
  pinMode(12,OUTPUT);
  digitalWrite(12,LOW);
  pinMode(3,INPUT);
  digitalWrite(3,HIGH);
}

void loop()
{
  if(digitalRead(3)==LOW)
  {
    digitalWrite(12,HIGH);
  }
  
  if(digitalRead(3)==HIGH)
  {
    digitalWrite(12,LOW);
  }
}
