void setup()
{
  pinMode(2,INPUT);
  pinMode(13,OUTPUT);
  digitalWrite(2,HIGH);
  digitalWrite(13,LOW);
  Serial.begin(9600);
  delay(10);
}


void loop()
{
  
  if(digitalRead(2)==LOW)
  {
    while(digitalRead(2)==LOW)
    {
      Serial.println("Umesh Dutta");
      delay(300);// delay of 0.3 sec
    }
  }
  
}
