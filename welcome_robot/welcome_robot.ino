char temp;
void setup()
{
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
}

void loop()
{
  while(!Serial.available());
  if(Serial.available()>0)
  {
    temp = Serial.read();
    if(temp=='1')
    {
      digitalWrite(12,HIGH);
      digitalWrite(13,HIGH);
    }
    
    if(temp=='2')
    {
      digitalWrite(12,LOW);
      digitalWrite(13,LOW);
    }
  }
}
