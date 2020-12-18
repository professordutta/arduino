// code for the home automation using arduino
// gsm module sim900 is used with arduino uno atmega328
// written by  UMESH DUTTA


char temp[50];
int m;
int inByte =0;        
void setup()
{
  // initialize serial communication with baud rate of 9600 bps
  Serial.begin(9600);
  // wait for a while till the serial port is ready
  delay(100);
// configure the gsm modemin sms mode   
  Serial.print("AT+CMGF=1\r");
  delay(500);
 // route the contents of the received sms on to serial port
  Serial.print("AT+CNMI=2,2,0,0,0\r");
  //define pins 2 ad 3 as o/p pins
  pinMode(13,OUTPUT);
  // make default status of pin 2 and 3 low
  digitalWrite(13,LOW);
  delay(500);
}
//  loop function starts here
void loop()
{
  // clear the temporary variable temp
    m=0;
    for(m=0;m<45;m++)
      {
        temp[m]=0;
      }
   // wait for the reception of the message
   // " is a identifier for the start of the message
    do
    {
        while ( !Serial.available() );   
    } while ( '"' != Serial.read() );

   // read the sms which will have date, time, sms body and the senders number
      for(m=0;m<45;m++)
      {
        while ( !Serial.available() );
        inByte = Serial.read();
        temp[m]=inByte;
      }

     
      // after testing it is found that the main body of the sms will start from psition 42 ie. for m=42
      // I have used 3 digit code for the sms and so position 42, 43 and 44 will contain the main body of the sms
      // print the received sms main body on the lcd screen
    
      
     //now write different conditions and required actions
    
    /*codes are
     D1N----------device 1 on
     D1F----------device 1 off
    
     */    
     // device 1 is connected to pin 2 and device 2 is connected to pin 3 of the arduino
   
      if(temp[42]=='D' && temp[43]=='1' && temp[44]=='N')
      {
        digitalWrite(13,HIGH);
       
      }
     
      if(temp[42]=='D' && temp[43]=='1' && temp[44]=='F')
      {
        digitalWrite(13,LOW);
        
      }
     
}

