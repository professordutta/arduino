#include <LiquidCrystal.h>
char temp;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(20, 4);
  Serial.begin(9600);
  // Print a message to the LCD.
  lcd.print("UMESH DUTTA ECE");
  lcd.setCursor(0,1);

}

void loop() 
{
  
  while(!Serial.available());
if(Serial.available()>0)
{
temp=Serial.read();
lcd.print(temp);
}  
}
