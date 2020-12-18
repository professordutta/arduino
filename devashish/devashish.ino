
#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

SoftwareSerial mySerial(10, 11); // RX, TX
LiquidCrystal lcd(13, 12, 6, 5, 4, 3);


char temp[12];
int m;
int n,v,s;

int sw;
int sw1;


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
    lcd.clear();
    lcd.setCursor(0,0);
    
  for(m=0;m<12;m++)
  {
  while(!mySerial.available() && digitalRead(9)==LOW);
  if (mySerial.available())
  {
  temp[m]=mySerial.read();
  Serial.write(temp[m]);
  }
  }
  
  if(temp[11]=='9')
  {
    lcd.setCursor(0,1);
    lcd.print("Neeraj");
    delay(2000);
    lcd.setCursor(0,1);
    lcd.print("      ");
    n=1;
  }
  
  if(temp[11]=='B')
  {
    lcd.setCursor(0,1);
    lcd.print("Saransh");
    delay(2000);
    lcd.setCursor(0,1);
    lcd.print("       ");
    s=1;
  }
  
  
  if(temp[11]=='3')
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
    
    
   if(s==1 && n==1 && v==1)
    {
     
      Serial.print("All Present");
      lcd.setCursor(0,1);
      lcd.print("All Present");
      
      
    }
    
    
    
    if(s==0 && n==0 && v==0)
    {
      
      Serial.print("All Absent");
 
      lcd.setCursor(0,1);
      lcd.print("All Absent");
      
    }
    
    if(s==0 && n==1 && v==1)
    {
      
      Serial.print("Saransh is Absent Today");
      
      lcd.setCursor(0,1);
      lcd.print("Saransh Absent");
      
    }
    
    if(s==1 && n==0 && v==1)
    {
      
      Serial.print("Neeraj is Absent Today");
      
      lcd.setCursor(0,1);
      lcd.print("Neeraj Absent");
      
    }
    
    if(s==1 && n==1 && v==0)
    {
      
      Serial.print("Vikrant is Absent Today");
      
      lcd.setCursor(0,1);
      lcd.print("Vikrant Absent");
      
    }
    
    if(s==0 && n==0 && v==1)
    {
      
      Serial.print("Saransh and Neeraj are Absent Today");
      
      lcd.setCursor(0,0);
      lcd.print("Saransh & Neeraj");
      lcd.setCursor(0,1);
      lcd.print("Absent");
      
    }
    
    if(s==1 && n==0 && v==0)
    {
      
      Serial.print("Neeraj and Vikrant are Absent Today");
      
      lcd.setCursor(0,0);
      lcd.print("Neeraj &Vikrant");
      lcd.setCursor(0,1);
      lcd.print("Absent");
 
    }
    
    if(s==0 && n==1 && v==0)
    {
      Serial.print("Saransh and Vikrant are Absent Today");
      
      lcd.setCursor(0,0);
      lcd.print("Saransh & Vikrant");
      lcd.setCursor(0,1);
      lcd.print("Absent");
    }
    
    
    }
  }

  

