
#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
SoftwareSerial mySerial(10, 11); // RX, TX





// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
char temp[12];
int m;


void gsm_init()
{
  Serial.begin(9600);  //Baud rate of the GSM/GPRS Module 
  Serial.print("\r");
  delay(1000);                  
  Serial.print("AT+CMGF=1\r");    
  delay(1000);
  Serial.print("AT+CMGS=\"+919811397880\"\r");    //Number to which you want to send the sms
  delay(1000); 
}


void sent()
{
  delay(1000);
  Serial.write(0x1A);
  delay(1000); 
}



void motor()
{
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  delay(4000);
  digitalWrite(8,LOW);
  digitalWrite(7,LOW);
  
}

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Welcome");
  
   mySerial.begin(9600);
   Serial.begin(9600);
   pinMode(7,OUTPUT);
   pinMode(8,OUTPUT);
   
   digitalWrite(7,LOW);
   digitalWrite(8,LOW);
   
}

void loop()
{
  
  lcd.setCursor(0,0);
  lcd.print("Welcome");
   for(m=0;m<12;m++)
  {
  while(!mySerial.available());
  if (mySerial.available()>0)
  {
  temp[m]=mySerial.read();
  Serial.write(temp[m]);
  }
  }
  
  if(temp[10]=='7' && temp[11]=='8')
  {
    lcd.setCursor(0,1);
    lcd.print("Abhay");
    delay(2000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("scan book");
    
    for(m=0;m<12;m++)
  {
  while(!mySerial.available());
  if (mySerial.available()>0)
  {
  temp[m]=mySerial.read();
  Serial.write(temp[m]);
  }
  
  
  if(temp[10]=='8' && temp[11]=='2')
  {
    lcd.setCursor(0,1);
    lcd.print("Book issued..");
    gsm_init();
    Serial.print("Return the book within 7 days");
    sent();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("SMS SENT...");
    motor();
    lcd.clear();
    
  }
  
  
  
    
  }
  }
  
  
  if(temp[10]=='B' && temp[11]=='8')
  {
    lcd.setCursor(0,1);
    lcd.print("Access Denied");
    delay(2000);
    lcd.clear();
  }
  
  
  
}
