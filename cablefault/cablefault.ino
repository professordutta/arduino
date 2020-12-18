#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
float temp1;
float temp;
void setup()
{
  lcd.begin(16,2);
  //lcd.print("Hello");
}

void loop()
{
  lcd.setCursor(0,0);
  temp=analogRead(A0);
  lcd.print("Test voltage:");
  temp1=temp*(5.0/1024.0);
  lcd.print(temp1);
  lcd.print("V");
  if(temp1>2.0 && temp1<3.0)
  {
    lcd.setCursor(0,1);
    lcd.print("Cable Ok");
    delay(2000);
    lcd.setCursor(0,1);
    lcd.print("        ");
  }
  
  else
  {
    lcd.setCursor(0,1);
    lcd.print("Cable Fault");
    delay(2000);
    lcd.setCursor(0,1);
    lcd.print("            ");
    
    Serial.begin(9600);  //Baud rate of the GSM/GPRS Module 
    Serial.print("\r");
    delay(1000);                  
    Serial.print("AT+CMGF=1\r");    
    delay(1000);
    Serial.print("AT+CMGS=\"+919654276864\"\r");    //Number to which you want to send the sms
    delay(1000);
    Serial.print("Cable Fault Detected\r");   //The text of the message to be sent
    delay(1000);
    Serial.write(0x1A);
    delay(1000); 
    while(1);
  }
  delay(300);
 
}

