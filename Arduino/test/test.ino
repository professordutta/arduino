void setup()
{
  // put your setup code here, to run once:
  pinMode(2,INPUT); // configure pin 2 (D4) as output pin
  //to turn on the on board led make state of pin 2 low
  //digitalWrite(2,HIGH); // make state of pin 2 low  
  Serial.begin(9600);
}
void loop() 

{
  // put your main code here, to run repeatedly:
  if(digitalRead(2)==LOW)
  {
    Serial.println("Button Pressed");
  }
  else
  {
    Serial.println("Button Not Pressed");
  }
}

