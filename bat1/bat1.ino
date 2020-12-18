int temp;
//char temp1;
void setup()
{
  Serial.begin(9600);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
}

void loop()
{
  
  while(!Serial.available());
  if(Serial.available()>0)
  {
    temp=Serial.read();
    
    if(temp>5)
    {
      digitalWrite(12,HIGH);
      digitalWrite(11,LOW);
      delay(5000);
      digitalWrite(12,LOW);
      digitalWrite(11,HIGH);
      delay(5000);
    }
    
    
  }
  
}
