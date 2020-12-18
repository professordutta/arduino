unsigned char temp;
void setup()
{
  Serial.begin(9600);
}


void loop()
{
  while(!Serial.available());
  if(Serial.available()>0)
  {
    temp=Serial.read();
    Serial.write(temp);
    delay(200);
  }
}
