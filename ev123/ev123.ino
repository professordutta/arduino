char temp;
void setup()
{
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  
}

void loop()
{
  
  while(!Serial.available());
  if(Serial.available()>0)
  {
    temp = Serial.read();
    if(temp=='A')
    {
      digitalWrite(13,HIGH);
    }
    
    if(temp=='B')
    {
      digitalWrite(13,LOW);
    }
  }
  
  
}
