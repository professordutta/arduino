void setup()
{
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  digitalWrite(26,LOW);
  digitalWrite(27,LOW);
}

void loop()
{
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  
}
