void setup()
{
  pinMode(2,INPUT);
  digitalWrite(2,LOW);
  Keyboard.begin();
}

void loop()
{
  if(digitalRead(2)==LOW)
  {
    Keyboard.print("Hello");
  }
}
