#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,10,9,8,7);

void int1()
{
 lcd.print("interrupt");
 delay(1000);
 lcd.clear();
 lcd.setCursor(0,0);
 detachInterrupt(0);
}

void setup()
{
  lcd.begin(16,2);
  pinMode(13,OUTPUT);
  pinMode(2,INPUT);
  
}



void loop()
{
  attachInterrupt(0,int1,FALLING);
 digitalWrite(13,HIGH);
 delay(1000);
 digitalWrite(13,LOW);
 delay(1000); 
}
