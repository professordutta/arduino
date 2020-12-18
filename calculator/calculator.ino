
int temp1=0;
int temp2=0;
int sum=0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.print("Enter the first number:");
  while(!Serial.available());
  if(Serial.available()>0)
  {
    temp1=Serial.read();
  }
  Serial.write(temp1);
  Serial.print('\n');
  Serial.print("Enter second number:");
  while(!Serial.available());
  if(Serial.available()>0)
  {
    temp2=Serial.read();
  }
  Serial.write(temp2);
  sum=temp1+temp2;
  Serial.print('\n');
  Serial.print("Result of Addition is sum:");
  Serial.print(sum-96);
  Serial.print('\n');
  delay(1000);
}
