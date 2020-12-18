#include <SoftwareSerial.h>

SoftwareSerial mySerial(10,9);

#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 7, 6, 5, 4);


char temp[50];
int m;


int inByte =0;         


int x; 
int y;
void setup()
{



  mySerial.begin(9600);
  delay(100);
  // start serial port at 9600 bps
  Serial.begin(9600);

  // wait for a while till the serial port is ready
  delay(100);

// send the initial data once //    
  mySerial.print("AT+CMGF=1\r");
  delay(500);
  mySerial.print("AT+CNMI=2,2,0,0,0\r");
  lcd.begin(20, 4);
  lcd.print("**Device Control..**");
  delay(500);
 

}

void loop()
{
    m=0;
    for(m=0;m<45;m++)
      {

        temp[m]=0;
      }


    do
    {
        while ( !mySerial.available() );    
    } while ( '"' != mySerial.read() );







      for(m=0;m<45;m++)
      {
        while ( !mySerial.available() ); 
        inByte = mySerial.read();
        temp[m]=inByte;

      }
      
      lcd.setCursor(0,2);
      
      for(m=42;m<45;m++)
      {
        lcd.print(temp[m]);
      }
      delay(100);

      Serial.print(temp[42]-48);
      Serial.print(temp[43]-48);
      Serial.print(temp[44]-48);
      
      delay(1000);







}


