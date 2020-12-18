#include <SoftwareSerial.h>
SoftwareSerial mySerial(10,11);
int m;
char temp[100];
char temp1;
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  mySerial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

do
{
  while(!mySerial.available());

  if(mySerial.available()>0)
  {
    temp1=mySerial.read();
  }
  
}while(temp1!='*');

for(m=0;m<48;m++)
{
  while(!mySerial.available());
  if(mySerial.available()>0)
  {
    temp[m]=mySerial.read();
  }
}

for(m=0;m<48;m++)
{
  Serial.print(temp[m]);
}
}



