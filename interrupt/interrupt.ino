void setup()
{
  pinMode(2,INPUT);
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
  attachInterrupt(0,abc,FALLING);
}



void abc()
{
  digitalWrite(13,HIGH);
  
  detachInterrupt(0);
}
void loop()
{
  
}
