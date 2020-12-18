int p1=12;
int res =11;
int count;
void setup()
{
  pinMode(p1,INPUT);
  pinMode(res,INPUT);
  digitalWrite(res,HIGH);
  digitalWrite(p1,HIGH);
  Serial.begin(9600);
}

void loop()
{
  if(digitalRead(p1)==LOW)
  {
    count = count + 1;
    delay(300);
  }
  
  if(digitalRead(res)==LOW)
  {
    Serial.print("Total number of votes given to party 1:");
    Serial.println(count);
    delay(300); 
  }
  
  
  
}
