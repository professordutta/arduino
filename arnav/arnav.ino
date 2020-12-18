char temp;
void setup()
{
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
  
}


void loop()
{
  
  while(!Serial.available());
  if(Serial.available()>0)
  {
    temp=Serial.read();
    if(temp=='T')
    {
      digitalWrite(13,HIGH);
      while(1);
    }
    
    else
    {
      digitalWrite(13,LOW);
    }
  }
  
}
