#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
char temp;
void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("String Played:");
  Serial.begin(9600);
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  while(!Serial.available());
  if(Serial.available()>0)
  {
    temp=Serial.read();
    if(temp=='1')
    {
      lcd.print("E LOW");
      delay(1000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("String Played:");
      lcd.setCursor(0,1);
      
    }
    
    
    if(temp=='2')
    {
      lcd.print("A...");
      delay(1000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("String Played:");
      lcd.setCursor(0,1);
    }
    
    
    if(temp=='3')
    {
      lcd.print("D...");
      delay(1000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("String Played:");
      lcd.setCursor(0,1);
    }
    
    if(temp=='4')
    {
      lcd.print("G.....");
      delay(1000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("String Played:");
      lcd.setCursor(0,1);
    }
    
    if(temp=='5')
    {
      lcd.print("B......");
      delay(1000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("String Played:");
      lcd.setCursor(0,1);
    }
    
    if(temp=='6')
    {
      lcd.print("E HIGH....");
      delay(1000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("String Played:");
      lcd.setCursor(0,1);
    }
    
    
    
    
  }
}
