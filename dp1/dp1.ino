
int temp;
void setup()
{
  Serial.begin(9600);
  
}


void loop()
{
  //temp=analogRead(A0);
  Serial.write("UMESH");
  Serial.write('\r');  
  delay(100);
  
}
