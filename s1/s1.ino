void setup()
{
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  digitalWrite(13,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  
}


void loop()
{
  if(digitalRead(10)==HIGH && digitalRead(11)==HIGH )
  {
    digitalWrite(13,HIGH);
    digitalWrite(12,HIGH);
    
  }
  
  
  if(digitalRead(10)==LOW && digitalRead(11)==HIGH )
  {
    digitalWrite(13,LOW);
    digitalWrite(12,HIGH);
    
  }
  
  
  if(digitalRead(10)==HIGH && digitalRead(11)==LOW )
  {
    digitalWrite(13,HIGH);
    digitalWrite(12,LOW);
    
  }
  
  
  if(digitalRead(10)==LOW && digitalRead(11)==LOW )
  {
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    
  }
  
  
  
   
}
