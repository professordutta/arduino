float temp;
float temp1;  
void setup() 
{
 Serial.begin(9600);
}

void loop() 
{
  temp = analogRead(A0);
  //Serial.println(temp);
  temp1 = (temp*500.0)/1024.0;
  Serial.println(temp1,1);
  delay(1000);
}
