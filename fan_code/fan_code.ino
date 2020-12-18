int d =4;
char temp;
void setup()
{
  pinMode(12,OUTPUT);
  pinMode(2,INPUT);
  digitalWrite(12,HIGH);
  attachInterrupt(0,frun,FALLING);// interrupt at pin 2
  Serial.begin(9600); // intialize serial comm
  
}

void frun()
{
  // here generate a delayed pulse depending on received serial data
  delay(d);
  digitalWrite(12,LOW);
  delay(10); // stay low for 10 ms
  digitalWrite(12,HIGH);
  Serial.print("check");
  
}

void loop()
{
  //Serial.print("Hello");
  while(!Serial.available());
  Serial.println("Data Received");
  if(Serial.available()>0)
  {
    temp = Serial.read();
    if(temp=='A')
    {
      d = d+1;
      Serial.println(d);
      if(d>=8)
      {
        d=8;
      }
    }
    
    if(temp=='B')
    {
      Serial.println(d);
      d=d-1;
      if(d<=2)
      {
        d=2;
      }
    }
  }
  
  
}
