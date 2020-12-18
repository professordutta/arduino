

//char temp;

unsigned char temp 

void setup()
{
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  //mySerial.begin(9600);
  Serial.begin(9600);
  Serial.println("UMESH DUTTA");
  delay(10);
}


void loop()
{
 // while(!Serial.available());
 
 Serial.println("Hello");
 Serial.println("MRIU");
  if(Serial.available()>0)
  {
    temp=Serial.read();
    Serial.print(temp);
    
    if(temp=='A')  // forward motion 
    {
      digitalWrite(4,HIGH);
      digitalWrite(5,LOW);
      digitalWrite(6,HIGH);
      digitalWrite(7,LOW);
    }
    
    if(temp=='2')  // backward motion 
    {
      digitalWrite(4,LOW);
      digitalWrite(5,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(7,HIGH);
    }
    
    if(temp=='3')  // right motion 
    {
      digitalWrite(4,HIGH);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
    }
    
    if(temp=='4')  // left motion 
    {
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,HIGH);
      digitalWrite(7,LOW);
    }
    
    if(temp=='5')  // stop motion 
    {
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
    }
    
  }
}
