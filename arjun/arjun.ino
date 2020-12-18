int temp;
void setup()
{
  Serial.begin(9600);
}


void loop()
{
  temp=analogRead(A0);
  Serial.println(temp);
  delay(1000);
}
