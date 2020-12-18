#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
#include<String.h>
LiquidCrystal lcd(2,3,4,5,6,7);
SoftwareSerial mySerial(10,11);
int m;
int count;
char temp[13];
char temp1[13] = { '1','8','0','0','8','9','1','C','1','C','9','1','\0'};
void setup()
{
  mySerial.begin(9600);
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("Welcome User");
  delay(2000);
  
}

void loop()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Scan your Card:");

  for(m=0;m<12;m++)
  {
    while(!mySerial.available());
    if(mySerial.available()>0)
    {
      temp[m]=mySerial.read();
      Serial.print(temp[m]);
    }
  }
  temp[12]='\0';

  Serial.println(" ");

  if(strcmp(temp,temp1)==0)
  {
    Serial.println("Access granted");
    count = 0;
    lcd.setCursor(0,1);
    lcd.print("Acess granted");
    delay(1500);
  } 

  else
  {
    Serial.println("Access denied");
    lcd.setCursor(0,1);
    lcd.print("Acess denied");
    delay(1500);
    count  = count + 1;
    if(count==3)
    {
      Serial.println("No more trials");
      Serial.println("System is locked");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("System Locked");
      while(1);
    }
  }
  Serial.println(" ");
}

