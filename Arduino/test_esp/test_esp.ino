#include <SoftwareSerial.h>
#include <string.h>    // Library to use string functions
SoftwareSerial mySerial(2,3);// rx-2 3-tx
char temp;
char connectionCommand[]="AT+CIPSTART=2,\"TCP\",\"api.thingspeak.com\",80";
// command for connecting to thingspeak server
char updateLink[] = "GET /update?api_key=5VLUJQVYDCTOO49D&field1=7\r\n";
// link to be updated once the connection established

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // initialize serial communication at 9600 bps baud rate
  mySerial.begin(9600); // initialize software serial port at 9600 bps
}
void resp()
{
  do
  {
    //wait till 'O' is received
    while(!mySerial.available());
    if(mySerial.available()>0)
    {
      temp=mySerial.read();
    }
  }while(temp!='O');
  Serial.print("O"); // print 'O' on serial port
  do
  {
    // wait for receiving 'K'
    while(!mySerial.available());
    if(mySerial.available()>0)
    {
      temp=mySerial.read();
    }
  }while(temp!='K');
  Serial.println("K"); //print 'K' on serial port
}
void loop() {
  // put your main code here, to run repeatedly:
  mySerial.println("AT");
  resp();
  delay(4000);
  mySerial.println("AT+CIPMUX=1");
  resp();
  delay(2000);
  mySerial.println("AT+CWMODE=3");
  resp();
  delay(2000);
  mySerial.println(connectionCommand);  // executing connection build command
  delay(2000);  // waiting for the command to be executed
  mySerial.print( "AT+CIPSEND=2," ); // sending data command execution start
  mySerial.println(strlen(updateLink));  // calculating link length to be send
  delay(2);
  if(mySerial.find( ">" ) )   // waiting to enter into the send mode
  {
    mySerial.print(updateLink);  // sending data to thingspeak
    delay(10000); //delay of 10 sec before the loop repeat again
  }
}
