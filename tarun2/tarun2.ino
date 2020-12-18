void setup()
{
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
}

void loop()
{
  if(digitalRead(2)==HIGH && digitalRead(3)==LOW && digitalRead(4)==LOW && digitalRead(5)==LOW)
 {
   digitalWrite(6,HIGH);
   digitalWrite(7,LOW);
   
 } 
 
 if(digitalRead(2)==LOW && digitalRead(3)==HIGH && digitalRead(4)==LOW && digitalRead(5)==LOW)
 {
   digitalWrite(6,LOW);
   digitalWrite(7,HIGH);
   
 }
 
 
 if(digitalRead(2)==LOW && digitalRead(3)==LOW && digitalRead(4)==LOW && digitalRead(5)==LOW)
 {
   digitalWrite(6,LOW);
   digitalWrite(7,LOW);
   
 }
 
}
