
#include <SoftwareSerial.h>
#include<String.h>

SoftwareSerial mySerial(10, 11); // RX, TX


char str1[13]={'6','5','0','0','2','4','A','1','6','1','8','1','\0'};

char temp[13];
int m;
void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600);
  delay(100);
}


void loop()
{
  for(m=0;m<12;m++)
  {
  while(!mySerial.available());
  if(mySerial.available()>0)
  {
    temp[m]=mySerial.read();
   }
  }
  temp[12]='\0';
  
  
  for(m=0;m<12;m++)
  {
    Serial.print(temp[m]);
  }
  
  
  if(strcmp(temp,str1)==0)
  {
    Serial.println("match found");
  }
  
  else
  {
    Serial.println("match not found");
  }
  
}
