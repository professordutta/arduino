void setup()
{
  pinMode(2,INPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
}

void loop()
{
  if(digitalRead(2)==HIGH)
  {
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    delay(5000);
  }
  
  if(digitalRead(2)==LOW)
  {
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    delay(2000);
    
    digitalWrite(9,HIGH);
    digitalWrite(8,LOW);
    digitalWrite(10,LOW);
    delay(1000);
    
    digitalWrite(10,HIGH);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    delay(2000);

    
  }
  
  
  
  
  
}
