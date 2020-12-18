

void setup()
{
  pinMode(13,OUTPUT);
  pinMode(3,INPUT);
  
}

void loop()
{
  int button=digitalRead(3);
  if(button == HIGH)
  {
    digitalWrite(13,HIGH);
  }
  else
  {
    digitalWrite(13,LOW);
  }
  
}

