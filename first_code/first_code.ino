void setup() {
  // put your setup code here, to run once:

  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(2)==LOW && digitalRead(3)==LOW)
{
 digitalWrite(13,HIGH); 
 digitalWrite(12,HIGH); 
}
if(digitalRead(2)==HIGH && digitalRead(3)==HIGH)
{
 digitalWrite(13,LOW); 
 digitalWrite(12,LOW); 
}

if(digitalRead(2)==LOW && digitalRead(3)==HIGH)
{
 digitalWrite(13,HIGH); 
 digitalWrite(12,LOW); 
}

if(digitalRead(2)==HIGH && digitalRead(3)==LOW)
{
 digitalWrite(13,LOW); 
 digitalWrite(12,HIGH); 
}

}
