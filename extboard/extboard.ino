/*===============================================================//
 Demonstration on how to receive an SMS using GSM module
 
 The circuit:
 LCD:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 7
 * LCD D5 pin to digital pin 6
 * LCD D6 pin to digital pin 5
 * LCD D7 pin to digital pin 4
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD pin 3
 * LED anode attached to digital output 9
 * LED cathode attached to ground through a 1K resistor
 
 GSM:
 RX PIN OF GSM TO TX0 PIN OF ARDUINO 
 SHORT THE GROUND PINS OF ARDUINO AND XBEE
============================== EG LABS ===================================*/
 
 
#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 7, 6, 5, 4);
char temp[50];
int m;
 
// give the pin a name:
int led = 9;
// incoming serial byte
int inByte =0;         


int x; 
int y;
void setup()
{
  pinMode(2,OUTPUT);
  digitalWrite(2,LOW);  
  
  pinMode(3,OUTPUT);
  digitalWrite(3,LOW);
  
   pinMode(4,OUTPUT);
  digitalWrite(4,LOW);
  
   pinMode(5,OUTPUT);
  digitalWrite(5,LOW);
  
  
  lcd.begin(16,2);
  lcd.print("welcome..");
  
  // initialize the led pin as an output.
  pinMode(led, OUTPUT);  
  // start serial port at 9600 bps
  Serial.begin(9600);
  // wait for a while till the serial port is ready
  delay(100);
 
// send the initial data once //    
  Serial.print("AT+CMGF=1\r");
  delay(500);
  Serial.print("AT+CNMI=2,2,0,0,0\r");
  delay(2000);
  
  
}
 
void loop()
{
    m=0;
    for(m=0;m<45;m++)
      {
       
        temp[m]=0;
      }
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("MY CREATION.....");
  
 
    do
    {
        while ( !Serial.available() );    
    } while ( '"' != Serial.read() );
  
    
    
    
     
      lcd.setCursor(0,1);
      
     
      for(m=0;m<45;m++)
      {
        while ( !Serial.available() ); 
        inByte = Serial.read();
        temp[m]=inByte;
        
      }
  
      if(temp[0]=='+' && temp[1]=='9' && temp[2]=='1' && temp[3]=='9' && temp[4]=='8' && temp[5]=='7' && temp[6]=='1' && temp[7]=='1' && temp[8]=='5' && temp[9]=='0' && temp[10]=='7' && temp[11]=='2' && temp[12]=='5')
      {
        lcd.setCursor(0,1);
        lcd.print("SMS received");
        lcd.setCursor(0,1);
        lcd.print("            ");
        
        delay(300);
        
        
        
        
        
       
       if(temp[42]=='1' && temp[43]=='O' && temp[44]=='N')
         {
          lcd.setCursor(0,1);
        lcd.print("device 1 ON");
        digitalWrite(2,HIGH);
        delay(2000);
        
         }
         
         if(temp[42]=='1' && temp[43]=='O' && temp[44]=='F')
         {
          lcd.setCursor(0,1);
        lcd.print("device 1 OFF");
        digitalWrite(2,LOW);
        delay(2000);
        
         }
         
         if(temp[42]=='2' && temp[43]=='O' && temp[44]=='N')
         {
          lcd.setCursor(0,1);
        lcd.print("device 2 ON");
        digitalWrite(3,HIGH);
        delay(2000);
        
         }
         
         if(temp[42]=='2' && temp[43]=='O' && temp[44]=='F')
         {
          lcd.setCursor(0,1);
        lcd.print("device 2 OFF");
        digitalWrite(3,LOW);
        delay(2000);
        
         }
         
         if(temp[42]=='3' && temp[43]=='O' && temp[44]=='N')
         {
          lcd.setCursor(0,1);
          lcd.print("device 3 ON");
          digitalWrite(4,HIGH);
          delay(2000);
        
         }
         
         if(temp[42]=='3' && temp[43]=='O' && temp[44]=='F')
         {
          lcd.setCursor(0,1);
        lcd.print("device 3 OFF");
        digitalWrite(4,LOW);
        delay(2000);
        
         }
         
         
         if(temp[42]=='4' && temp[43]=='O' && temp[44]=='N')
         {
          lcd.setCursor(0,1);
        lcd.print("device 4 ON");
        digitalWrite(5,HIGH);
        delay(2000);
        
         }
         
         
         if(temp[42]=='4' && temp[43]=='O' && temp[44]=='F')
         {
        lcd.setCursor(0,1);
        lcd.print("device 4 OFF");
        digitalWrite(5,LOW);
        delay(2000);
         }
         
         


         if(temp[42]=='A' && temp[43]=='O' && temp[44]=='N')
         {
          lcd.setCursor(0,1);
        lcd.print("all devices on");
        digitalWrite(2,HIGH);
        digitalWrite(3,HIGH);
        digitalWrite(4,HIGH);
        digitalWrite(5,HIGH);
        delay(2000);
        
        
         }
         
         if(temp[42]=='A' && temp[43]=='O' && temp[44]=='F')
         {
          lcd.setCursor(0,1);
        lcd.print("all devices off");
        digitalWrite(2,LOW);
        digitalWrite(3,LOW);
        digitalWrite(3,LOW);
        digitalWrite(3,LOW);
        delay(2000);
        
        
         }
 
 
         
         
       
         
       
       
        
        
        
    
}
}
