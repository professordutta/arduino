int x;
int y;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  x = analogRead(A0);
  y = analogRead(A1);
  
  Serial.print("x:");
  Serial.println(x);
  Serial.print("y:");
  Serial.println(y);
  delay(1000);
}
