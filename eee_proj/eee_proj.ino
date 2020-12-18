void setup()
{
  pinMode(7,OUTPUT);
  digitalWrite(7,LOW);
}


void loop()
{
  digitalWrite(7,HIGH);
  delayMicroseconds(45);
  digitalWrite(7,LOW);
  delayMicroseconds(45);
}
