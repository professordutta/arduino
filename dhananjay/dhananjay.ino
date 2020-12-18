int temp,count;
unsigned long time1;
void setup()
{
  Serial.begin(9600);
}


void loop()
{
  time1=millis()/1000;
  temp=analogRead(A0);
  Serial.println(temp);
  if(temp>500 && temp<800)
  {
   count=count+1;
     }
  
  if (time1%60==0)
  {
    Serial.print("Heart rate is:");
    Serial.println(count);
    count=0;
    
  }
  delay(1000); 

  
}
