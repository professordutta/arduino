int temp,val,val1,val2,val3,val4;
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  temp = analogRead(A0);
  val = temp;
  val1 = temp%10;
  val = val/10;
  val2 = val%10;
  val = val/10;
  val3 = val%10;
  val = val/10;
  val4 = val%10;
  Serial.print('A');
  Serial.print(val4);
  Serial.print(val3);
  Serial.print(val2);
  Serial.println(val1);
  
  delay(1000);
  
}
