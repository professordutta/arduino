float temp=0.0;
float buf=0.0;
float vout=0.0;
int vin=0;
float r2=0.0;
void setup()
{
  Serial.begin(9600);
  
}

void loop()
{
  temp=analogRead(A0);
  //Serial.print("value:");
  //Serial.print(temp);
  vout=(5.0/1023.0)*temp;
  buf=(5.0/vout)-1;
  //r2=100.0/buf;
  
  Serial.println(vout);
  
  
  
  delay(1000);
  
  
}
