void setup()
{
  Serial.begin(9600);
  pinMode(2,INPUT);
  digitalWrite(2,HIGH);
}

void loop()
{
  temp=temp+1;
  if(digitalRead(2)==LOW)
  {
  Serial.println(temp);
  
  }
  delay(1000);
  
}
