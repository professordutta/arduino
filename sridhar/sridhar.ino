float temp;
float temp1;
int m=0;
int time_var;
void setup()
{
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
  Serial.begin(9600);
  
}


void loop()
{
  temp=analogRead(A0);
  temp1 = (temp*500.0)/1023.0;
  Serial.println(temp1,2);
  delay(1000);
  
  if(temp1>27.0 && temp1<29.0)
  {
    if(m==0)
    {
      time_var=millis()/1000;
      Serial.println("Measurement Started");
      m=1;
    }
    Serial.print("Gadget in mouth");
  }
  
  else
  {
    Serial.println("Gadget taken out of mouth");
    m=0;
    Serial.println(time_var);
  }
 
}
