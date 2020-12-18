int temp;
void setup()
{
  pinMode(13,OUTPUT);
  pinMode(2,INPUT);


}

void loop()
{
  temp=digitalRead(2);
  if(temp==HIGH)
  {
  digitalWrite(13,HIGH);
  }
  else
  {
  digitalWrite(13,LOW);
  
}
}
