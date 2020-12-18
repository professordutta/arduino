#include <SoftwareSerial.h>
SoftwareSerial mySerial(10,11);
int m;
int count;
char temp[12];
void setup()
{
  mySerial.begin(9600);
  Serial.begin(9600);
  
}

void loop()
{
  for(m=0;m<12;m++)
  {
  while(!mySerial.available());
  if(mySerial.available()>0)
  {
    temp[m]=mySerial.read();
    Serial.print(temp[m]);
  }
  }
   Serial.println(" ");
  if(temp[9]=='9' && temp[10]=='9' && temp[11]=='2')
 {
   Serial.println("Access granted");
   count = 0;
 } 
 
 else
 {
   Serial.println("Access denied");
   count  = count + 1;
   if(count==3)
   {
     Serial.println("No more trials");
     Serial.println("System is locked");
     while(1);
   }
 }
  Serial.println(" ");
}
