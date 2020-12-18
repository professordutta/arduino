#include <SoftwareSerial.h>
#include<String.h>
SoftwareSerial mySerial(10,11);
int m;
int count;
char temp_var;
char temp[13];
char temp1[13] = { '1','3','0','0','6','F','9','B','9','1','7','6','\0'};
char temp2[13] = { '1','3','0','0','6','F','F','C','A','8','2','8','\0'};
char temp3[13] = { '1','3','0','0','6','F','D','4','7','D','D','5','\0'};
char temp4[13] = { '1','3','0','0','6','F','F','A','9','3','1','5','\0'};
char temp5[13] = { '1','3','0','0','6','F','F','9','B','A','3','F','\0'};
char temp6[13] = { '5','5','0','0','2','F','E','8','2','D','B','F','\0'};
char temp7[13] = { '6','C','0','0','2','6','C','1','1','9','9','2','\0'};
char temp8[13] = { '8','5','0','0','4','3','3','0','3','D','C','B','\0'};
char temp9[13] = { '6','C','0','0','2','6','E','0','6','F','C','5','\0'};
char temp10[13] = { '6','C','0','0','9','0','9','7','0','A','6','1','\0'};
char temp11[13] = { '8','5','0','0','4','2','B','0','4','9','3','E','\0'};




void setup()
{
  mySerial.begin(9600);
  Serial.begin(9600);
  pinMode(12,OUTPUT);
  pinMode(2,INPUT);
  digitalWrite(2,HIGH);
  digitalWrite(12,LOW);
}

void loop()
{
   for(m=0;m<12;m++)
  {
    while(!mySerial.available()&& !Serial.available() && digitalRead(2)==HIGH);
    
    if(digitalRead(2)==LOW)
    {
      digitalWrite(12,HIGH);
      delay(3500);
      digitalWrite(12,LOW);
      count = 0;
      m=12;
    }
    
    if(mySerial.available()>0)
    {
      count = 1;
      temp[m]=mySerial.read();
      Serial.print(temp[m]);
    }
    
    if(Serial.available() > 0)
    {
      count = 2;
      temp_var = Serial.read();
      m=12;
    }
  }
  if( count == 1)
  {
  
  temp[12]='\0';
  
   if(strcmp(temp,temp1)==0 || strcmp(temp,temp2)==0 || strcmp(temp,temp3)==0 || strcmp(temp,temp4)==0 || strcmp(temp,temp5)==0 || strcmp(temp,temp6)==0 || strcmp(temp,temp7)==0 || strcmp(temp,temp8)==0 || strcmp(temp,temp9)==0 || strcmp(temp,temp10)==0 || strcmp(temp,temp11)==0)
  {
    Serial.println("Access granted");
    digitalWrite(12,HIGH);
    delay(3500);
    digitalWrite(12,LOW);
    
  }
  }
  
  
  if(count == 2)
  {
    if (temp_var == 'A')
    {
      digitalWrite(12,HIGH);
      delay(3500);
      digitalWrite(12,LOW);
      temp_var = ' ';
    }
    
    
  }
 
    
 


}
