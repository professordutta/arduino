int x,y;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  x=analogRead(A0);
  y=analogRead(A1);
  
  Serial.println(x);
  Serial.println(y);
  delay(400);
  
  if(x>300 && x<320)
  {
    Serial.println('1');
  }
  
  if(x>230 && x<260)
  {
    Serial.println('4');
  }
  
  
  if(x>260 && x<290 )
  {
    Serial.println('5');
  }
  
  
  
}
