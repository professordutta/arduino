#include <SoftwareSerial.h>
SoftwareSerial mySerial(2,3);// 2-rx 3-tx
char temp;
char temp1[200];
int m,n;
void setup() {
  // put your setup code here, to run once:
  mySerial.begin(9600);
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
  mySerial.print("!Welcome to Chaudhary Niwas\r");
  delay(1000);
 
}

void loop() {
  // put your main code here, to run repeatedly:

do
{
  while(!Serial.available());
  temp=Serial.read();
}while(temp!='@');

do
{
  while(!Serial.available());
  temp=Serial.read();
  temp1[m]=temp;
  m=m+1;
}while(temp!='#');

mySerial.print("!");
for(n=0;n<(m-1);n++)
{
  mySerial.print(temp1[n]);
}
mySerial.print("\r");
m=n=0;

}

