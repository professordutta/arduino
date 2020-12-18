void setup()
{
  pinMode(13,OUTPUT);
  pinMode(12,INPUT);
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
}


void loop()
{
  
  if(digitalRead(12)==LOW)
  {
  digitalWrite(13,HIGH);
  }
  
  else
  {
  digitalWrite(13,LOW);
  }
  
}
