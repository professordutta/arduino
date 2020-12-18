int temp;
void setup()
{
  pinMode(2,INPUT);
  digitalWrite(2,HIGH);
  Serial.begin(9600);
  
}


void loop()
{
  if(digitalRead(2)==HIGH)
  {
    temp=analogRead(A0);
    if(temp>850)
    {
    Serial.println("D");
    delay(500);
    }
  }
  
  else
  {
    temp=analogRead(A0);
    if(temp>850)
    {
    Serial.println("B");
    delay(500);
    }
  }
  
}

