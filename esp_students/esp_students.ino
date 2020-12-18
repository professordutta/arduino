
#include<SoftwareSerial.h>

SoftwareSerial esp(2,3); //RX,TX

char temp;
char temp1;

void esp_init()
{
  delay(2000);
  Serial.println("Sending AT");
  esp.print("AT\r\n");
 while(!esp.available());
 if(esp.available()>0)
 {
  while(esp.read()!='O');
  while(esp.read()!='K');
 }
 Serial.println("AT done");
 delay(4000);

  
 esp.print("AT+CIPMUX=1\r\n");
 while(!esp.available());
 if(esp.available()>0)
 {
  while(esp.read()!='O');
  while(esp.read()!='K');
 }
 Serial.println("AT+CIPMUX=1 done");
 delay(4000);

 esp.print("AT+CWMODE=3\r\n");
 while(!esp.available());
 if(esp.available()>0)
 {
  while(esp.read()!='O');
  while(esp.read()!='K');
 }
 Serial.println("AT+CWMODE=3 done");
 delay(4000);
 
 esp.print("AT+CIPSERVER=1,80\r\n");
 while(!esp.available());
 if(esp.available()>0)
 {
  while(esp.read()!='O');
  while(esp.read()!='K');
 }
 Serial.println("AT+CIPSERVER=1,80 done");
 delay(4000);

 esp.print("AT+CWDHCP=1,1\r\n");
 while(!esp.available());
 if(esp.available()>0)
 {
  while(esp.read()!='O');
  while(esp.read()!='K');
 }
 Serial.println("AT+CWDHCP=1,1 done");
  delay(4000);
}


void setup()
{ 
  Serial.begin(9600);
  esp.begin(9600);
  
 pinMode(13,OUTPUT);
 pinMode(12,OUTPUT);
 pinMode(11,OUTPUT);
 digitalWrite(13,HIGH);
 digitalWrite(12,HIGH);
 digitalWrite(11,HIGH);
 
 //conn();
}

void loop()
{

  esp_init();
  do
 {
    while(!esp.available());
    if(esp.available()>0)
    {
      temp=esp.read();
      Serial.print(temp);
    }
}while(temp!='$');
  
  while(!esp.available());
  if(esp.available()>0)
  {
    temp1=esp.read();
    //Serial.println(temp1);
  }
  
    if(temp1=='A')
    {
      digitalWrite(13,LOW);
      //conn();
    }
    else if(temp1=='B')
    {
      digitalWrite(13,HIGH);
      //conn();
    }
    if(temp1=='C')
    {
      digitalWrite(12,LOW);
    }
    if(temp1=='D')
    {
      digitalWrite(12,HIGH);
      //conn();
    }
    
    if(temp1=='E')
    {
      digitalWrite(11,LOW);
      //conn();
    }
    if(temp1=='F')
    {
      digitalWrite(11,HIGH);
      //conn();
    }
   
    if(temp1=='G')
    {
      digitalWrite(12,LOW);
      digitalWrite(11,LOW);
      digitalWrite(13,LOW);
      //conn();
    }
    if(temp1=='H')
    {
      digitalWrite(12,HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(13,HIGH);
      //conn();
    }

 
}

