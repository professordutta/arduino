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
char temp[3];
int m;
int k;
 
// give the pin a name:
// incoming serial byte
int inByte =0;         

/*
void smssend()
{
  Serial.begin(9600);  //Baud rate of the GSM/GPRS Module 
  Serial.print("\r");
  delay(300);                  
  Serial.print("AT+CMGF=1\r");    
  delay(300);
  Serial.print("AT+CMGS=\"+919873804937\"\r");    //Number to which you want to send the sms
  delay(300);
  Serial.print("Command successfullly executed....\r");   //The text of the message to be sent
  delay(300);
  Serial.write(0x1A);
  delay(1000); 
  Serial.flush();
}

*/



void setup()
{
  pinMode(10, OUTPUT); 
  pinMode(8, OUTPUT); 
  pinMode(3,OUTPUT); 
  pinMode(2,OUTPUT);
  digitalWrite(3,LOW);
  digitalWrite(2,LOW);  
  digitalWrite(8,LOW);  
  digitalWrite(10,LOW);  
  lcd.begin(20, 4);
  lcd.print("**Device Control..**");
  lcd.setCursor(0, 1);
  lcd.print("*****Using SMS******  ");
  delay(1000);
  
  // initialize the led pin as an output.
  // start serial port at 9600 bps
  Serial.begin(9600);
  // wait for a while till the serial port is ready
  delay(100);
 
// send the initial data once //    
  Serial.print("AT+CMGF=1\n\r");
  delay(500);
  Serial.print("AT+CNMI=2,2,0,0,0\n\r");
  delay(2000);
  
 lcd.clear();
}
 
void loop()
{
   
    k=k+1;
     
    
    lcd.setCursor(0,0);
    lcd.print("MY CREATION..");
    lcd.print(k);
    
    m=0;
  
    do
    {
        while ( !Serial.available() );    
    } while ( '"' != Serial.read() );
  
    do
    {
        while ( !Serial.available() );    
    } while ( '"' != Serial.read() );
  
    do
    {
        while ( !Serial.available() );    
    } while ( '"' != Serial.read() );
    
    do
    {
        while ( !Serial.available() );    
    } while ( '"' != Serial.read() );
    
    while ( !Serial.available() );
    inByte = Serial.read();     
    while ( !Serial.available() );
    inByte = Serial.read();
    
    

      /*lcd.clear();
      lcd.setCursor(0,0);
      
      lcd.print("Automation System");
      lcd.setCursor(0,1);
      */
       lcd.setCursor(0,1);
       
      for(m=0;m<3;m++)
      {
        while ( !Serial.available() ); 
        inByte = Serial.read();
        temp[m]=inByte;
      }
      
      
      
      
     
     
      if(temp[0]=='1' && temp[1]=='O' && temp[2]=='N')
      {
         lcd.setCursor(0,1);
        lcd.print("1ON");
        digitalWrite(3,HIGH);
        //smssend();
        
      }
      
      if(temp[0]=='2' && temp[1]=='O' && temp[2]=='N')
      {
         lcd.setCursor(0,1);
        lcd.print("2ON");
        digitalWrite(2,HIGH);
        //smssend();
      }
      
      if(temp[0]=='3' && temp[1]=='O' && temp[2]=='N')
      {
         lcd.setCursor(0,1);
        lcd.print("3ON");
        digitalWrite(8,HIGH);
       // smssend();
      }
      
      if(temp[0]=='4' && temp[1]=='O' && temp[2]=='N')
      {
         lcd.setCursor(0,1);
        lcd.print("4ON");
        digitalWrite(10,HIGH);
       // smssend();
      }
      
      
      if(temp[0]=='1' && temp[1]=='O' && temp[2]=='F')
      {
         lcd.setCursor(0,1);
        lcd.print("1OF");
        digitalWrite(3,LOW);
        //smssend();
      }
      
      if(temp[0]=='2' && temp[1]=='O' && temp[2]=='F')
      {
         lcd.setCursor(0,1);
        lcd.print("2OF");
        digitalWrite(2,LOW);
        //smssend();
      }
      
      if(temp[0]=='3' && temp[1]=='O' && temp[2]=='F')
      {
         lcd.setCursor(0,1);
        lcd.print("3OF");
        digitalWrite(8,LOW);
        //smssend();
      }
      
      if(temp[0]=='4' && temp[1]=='O' && temp[2]=='F')
      {
         lcd.setCursor(0,1);
        lcd.print("4OF");
        digitalWrite(10,LOW);
      //  smssend();
      }
      
      
      
       if(temp[0]=='A' && temp[1]=='O' && temp[2]=='N')
      {
         lcd.setCursor(0,1);
        
        lcd.print("AON");
        
        digitalWrite(2,HIGH);
        digitalWrite(3,HIGH);
        digitalWrite(8,HIGH);
        digitalWrite(10,HIGH);
       // smssend();
      }
      if(temp[0]=='A' && temp[1]=='O' && temp[2]=='F')
      {
         lcd.setCursor(0,1);
         
        lcd.print("AOF");
         
        digitalWrite(2,LOW);
        digitalWrite(3,LOW);
        digitalWrite(8,LOW);
        digitalWrite(10,LOW);
        
       // smssend();
      }
        
       // if ( inByte == '\r' )
         
         // break;
        //else;
       
        
        
        
    
}
