int x,y,z;
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  x=analogRead(A0);
  y=analogRead(A1);
  z=analogRead(A2);
  Serial.println(x);
  Serial.println(y);
  delay(1000);
}
