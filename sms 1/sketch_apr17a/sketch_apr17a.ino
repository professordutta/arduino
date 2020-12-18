
#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

SoftwareSerial mySerial(10, 11); // RX, TX
LiquidCrystal lcd(13, 12, 6, 5, 4, 3);


char temp[12];
int m;

int n,v,s;

int sw;
int sw1;
void gsm_init()
{
  Serial.begin(9600);  //Baud rate of the GSM/GPRS Module 
  Serial.print("\r");
  delay(1000);                  
  Serial.print("AT+CMGF=1\r");    
  delay(1000);
  Serial.print("AT+CMGS=\"+919999962262\"\r");   //Number to which you want to send the sms
  delay(1000);
  
   
 
}
void gsm_init()
{
  Serial.begin(9600);  //Baud rate of the GSM/GPRS Module 
  Serial.print("\r");
  delay(1000);                  
  Serial.print("AT+CMGF=1\r");    
  delay(1000);
  Serial.print("AT+CMGS=\"+919910526865\"\r");   //Number to which you want to send the sms
  delay(1000);
  
   
 
}

void sent()
{
  delay(1000);
  Serial.write(0x1A);
  delay(1000); 
}


void setup()  
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Welcome");
  pinMode(9,INPUT);
   pinMode(8,INPUT);
  
  mySerial.begin(9600);
 }

void loop() // run over and over
{
  sw=digitalRead(9);
  if(sw==LOW)
  {
    
  for(m=0;m<12;m++)
  {
  while(!mySerial.available());
  if (mySerial.available())
  {
  temp[m]=mySerial.read();
  Serial.write(temp[m]);
  }
  }
  
  if(temp[11]=='0')
  {
    lcd.setCursor(0,1);
    lcd.print("Neeraj");
    delay(2000);
    lcd.setCursor(0,1);
    lcd.print("      ");
    n=1;
  }
  
  if(temp[11]=='D')
  {
    lcd.setCursor(0,1);
    lcd.print("Saransh");
    delay(2000);
    lcd.setCursor(0,1);
    lcd.print("       ");
    s=1;
  }
  
  
  if(temp[11]=='1')
  {
    lcd.setCursor(0,1);
    lcd.print("Vikrant");
    delay(2000);
    lcd.setCursor(0,1);
    lcd.print("       ");
    v=1;
  }
  
  }
  
  if(sw==HIGH)
  {
    
    sw1=digitalRead(8);
    
    if(sw1==LOW)
    {
    
    lcd.setCursor(0,1);
    lcd.print("Sending SMS..");
    if(s==1 && n==1 && v==1)
    {
      gsm_init();
      Serial.print("All Present");
      sent();
      lcd.setCursor(0,1);
      lcd.print("SMS Sent.....");
      
      
    }
    
    if(s==0 && n==0 && v==0)
    {
      gsm_init();
      Serial.print("All Absent");
      sent();
      lcd.setCursor(0,1);
      lcd.print("SMS Sent.....");
      
    }
    
    if(s==0 && n==1 && v==1)
    {
      gsm_init();
      Serial.print("Neeraj and Vikrant are present & Saransh is Absent Today");
      sent();
      lcd.setCursor(0,1);
      lcd.print("SMS Sent.....");
      
    }
    
    if(s==1 && n==0 && v==1)
    {
      gsm_init();
      Serial.print("Sharansh and Vikrant are present & Neeraj is Absent Today");
      sent();
      lcd.setCursor(0,1);
      lcd.print("SMS Sent.....");
      
    }
    
    if(s==1 && n==1 && v==0)
    {
      gsm_init();
      Serial.print("Sharansh and Neeraj are present & Vikrant is Absent Today");
      sent();
      lcd.setCursor(0,1);
      lcd.print("SMS Sent.....");
      
    }
    
    if(s==0 && n==0 && v==1)
    {
      gsm_init();
      Serial.print("Vikrant is present & Saransh and Neeraj are Absent Today");
      sent();
      lcd.setCursor(0,1);
      lcd.print("SMS Sent.....");
      
    }
    
    if(s==1 && n==0 && v==0)
    {
      gsm_init();
      Serial.print("Sharansh is present & Neeraj and Vikrant are Absent Today");
      sent();
      lcd.setCursor(0,1);
      lcd.print("SMS Sent.....");
      
    }
    
    if(s==0 && n==1 && v==0)
    {
      gsm_init();
      Serial.print("Neeraj is present & Saransh and Vikrant are Absent Today");
      sent();
      lcd.setCursor(0,1);
      lcd.print("SMS Sent.....");
      
    }
    
    }
    
    
    
    
    
    
    
  }
  
  
 
}

