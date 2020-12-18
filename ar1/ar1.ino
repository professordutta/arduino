float temp;
float temp1;
float temp2;
void setup()
{
  Serial.begin(9600);
  delay(100);
}


void loop()
{
  temp=analogRead(A0);
  temp2=analogRead(A1);
  Serial.print("temperature:");
  
  temp1=((temp*5)/1023.0)*100;
  
  Serial.print(temp1);
 
  Serial.print('\n');
  
  
  Serial.print("Moisture:");
  Serial.print(temp2);
  Serial.print('\n');
  
  
  delay(1000);
}
