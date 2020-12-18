int x;
int s1;
int s2;
void setup()
{
  pinMode(2,INPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  
  
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  
  
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  
  
}


void sms()
{
  Serial.print("\r");
  delay(1000);                  
  Serial.print("AT+CMGF=1\r");    
  delay(1000);
  Serial.print("AT+CMGS=\"+919873804937\"\r");    //Number to which you want to send the sms
  delay(1000);
  Serial.print("Emergency, I need your help\r");   //The text of the message to be sent
  delay(1000);
  Serial.write(0x1A);
  delay(1000);
 while(1); 
}


void loop()
{
  x=digitalRead(2);
  
  s1=digitalRead(3);
  s2=digitalRead(4);
  
  if(x==LOW)
  {
    digitalWrite(13,HIGH);
    sms();
  }
 
 
 if(s1==LOW)
  {
    digitalWrite(5,HIGH);
    delay(300);
    digitalWrite(5,LOW);
    delay(300);
  }
  
  if(s2==LOW)
  {
    digitalWrite(6,HIGH);
    delay(300);
    digitalWrite(6,LOW);
    delay(300);
  } 
  
  
  
}


