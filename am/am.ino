void setup()
{
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
 
}


void loop()
{
  if(digitalRead(7)==LOW && digitalRead(8)==LOW)
  {
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
  }
  
  if(digitalRead(7)==HIGH && digitalRead(8)==LOW)
  {
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
  }
  
  if(digitalRead(7)==LOW && digitalRead(8)==HIGH)
  {
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
  }
  
  if(digitalRead(7)==HIGH && digitalRead(8)==HIGH)
  {
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
  }
  

}
