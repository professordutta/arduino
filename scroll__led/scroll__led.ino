#include <SoftwareSerial.h>
SoftwareSerial mySerial(10,11);
int n,m;
char temp[100];
char temp1;
void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600);
  Serial.print("!UMESH DUTTA\r");
  //Serial.print("\r");
}

void loop()
{  
    do
    {
      while(!mySerial.available());
      temp[m]=mySerial.read();
      temp1=temp[m];
      m=m+1;
    }while(temp1='#');
    
    Serial.print("!");
    
    for(n=0;n<m;n++)
    {
      Serial.print(temp[m]);
    }
    
    Serial.print("\r");
    
  
  
}

