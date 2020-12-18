void setup()
{
  pinMode(13,OUTPUT);
  pinMode(12,INPUT);
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
