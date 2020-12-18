#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,10,9,8,7);
char temp;
void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

while(!Serial.available());
if(Serial.available()>0)
{
  temp=Serial.read();
  lcd.print(temp);
}
}
