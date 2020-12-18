float temp;

void setup()
{
  Serial.begin(9600);
  
}


void loop()
{
  temp = analogRead(A0);
  temp = temp*(5.0/1023.0);
  Serial.println(temp);
  delay(500);
}
