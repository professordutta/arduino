#include <String.h>
String stringone;
String stringtwo;
int temp1;
int temp2;
char temp;
void setup()
{
  Serial.begin(9600);
  stringone="m2";
  temp1=15;
  temp2=30;
  temp=',';
}


void loop()
{
  stringtwo = stringone+temp+temp1+temp+temp2;
  Serial.print(stringtwo);
  while(1);
}
