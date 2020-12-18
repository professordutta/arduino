int x;
int y;
int z;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  x=analogRead(A0);
  y=analogRead(A1);
  z=analogRead(A2);
  
  Serial.print("x value:")
  Serial.print(x);
  Serial.print('\n');
  
  Serial.print("y value:")
  Serial.print(y);
  Serial.print('\n');
  
  Serial.print("z value:")
  Serial.print(z);
  Serial.print('\n');
}
