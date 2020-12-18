#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX


char temp[50];
int m;


int inByte =0;         


int x; 
int y;
void setup()
{




  // start serial port at 9600 bps
  Serial.begin(9600);
  mySerial.begin(9600);
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


    do
    {
        while ( !Serial.available() );    
    } while ( '"' != Serial.read() );







      for(m=0;m<45;m++)
      {
        while ( !Serial.available() ); 
        inByte = Serial.read();
        temp[m]=inByte;

      }

      mySerial.print(temp[42]);
      mySerial.print(temp[43]);
      mySerial.print(temp[44]);








}


