#include <SoftwareSerial.h>
SoftwareSerial mySerial(10,11);

int s1=2;
int s2=3;
int s3=4;
int s4=5;
int s5=6;
int s6=7;

char temp;
void setup() {
  // put your setup code here, to run once:
mySerial.begin(9600);
Serial.begin(9600);
pinMode(13,OUTPUT);
digitalWrite(13,LOW);

pinMode(s1,OUTPUT);
pinMode(s2,OUTPUT);
pinMode(s3,OUTPUT);
pinMode(s4,OUTPUT);
pinMode(s5,OUTPUT);
pinMode(s6,OUTPUT);

digitalWrite(s1,HIGH);
digitalWrite(s2,HIGH);
digitalWrite(s3,HIGH);
digitalWrite(s4,HIGH);
digitalWrite(s5,HIGH);
digitalWrite(s6,HIGH);

}

void check_response()
{
  do
  {
  while(!mySerial.available());
  if(mySerial.available()>0)
  {
    temp=mySerial.read();
  }
  }while(temp!='O');

  do
  {
  while(!mySerial.available());
  if(mySerial.available()>0)
  {
    temp=mySerial.read();
  }
  }while(temp!='K');

  mySerial.flush();

}

void gsm_init()
{
  mySerial.print("AT\r\n");
  Serial.println("AT sent");
  check_response();
  Serial.println("AT executed");
  delay(1000);
  mySerial.print("AT+CMGF=1\r\n");
  Serial.println("AT+CMGF=1 sent");
  check_response();
  Serial.println("AT+CMGF=1 executed");
  delay(1000);
  mySerial.print("AT+CNMI=2,2,0,0,0\r\n");
  Serial.println("AT+CNMI sent");
  check_response();
  Serial.println("AT+CNMI executed");
}

void loop() {
  // put your main code here, to run repeatedly:

gsm_init();
Serial.println("Initialization Completed");
Serial.println("Waiting to receive the sms...");

do
{
  while(!mySerial.available());

  if(mySerial.available()>0)
  {
    temp=mySerial.read();
  }
}while(temp!='*');

while(!mySerial.available());
if(mySerial.available()>0)
{
  temp=mySerial.read();
}
Serial.print("Data value received is:");
Serial.println(temp);

//flush mySeial

mySerial.flush();

if(temp=='A')
{
  digitalWrite(s1,LOW);
}

if(temp=='B')
{
  digitalWrite(s1,HIGH);
}

if(temp=='C')
{
  digitalWrite(s2,LOW);
}

if(temp=='D')
{
  digitalWrite(s2,HIGH);
}

if(temp=='E')
{
  digitalWrite(s3,LOW);
}

if(temp=='F')
{
  digitalWrite(s3,HIGH);
}

if(temp=='G')
{
  digitalWrite(s4,LOW);
}

if(temp=='H')
{
  digitalWrite(s4,HIGH);
}

if(temp=='I')
{
  digitalWrite(s5,LOW);
}

if(temp=='J')
{
  digitalWrite(s5,HIGH);
}

if(temp=='K')
{
  digitalWrite(s6,LOW);
}

if(temp=='L')
{
  digitalWrite(s6,HIGH);
}

if(temp=='M')
{
  digitalWrite(s1,LOW);
  digitalWrite(s2,LOW);
  digitalWrite(s3,LOW);
  digitalWrite(s4,LOW);
  digitalWrite(s5,LOW);
  digitalWrite(s6,LOW);
}

if(temp=='N')
{
  digitalWrite(s1,HIGH);
  digitalWrite(s2,HIGH);
  digitalWrite(s3,HIGH);
  digitalWrite(s4,HIGH);
  digitalWrite(s5,HIGH);
  digitalWrite(s6,HIGH);
}

}
