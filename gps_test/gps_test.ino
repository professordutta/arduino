#include <SoftwareSerial.h>
//Create software serial object to communicate with GPS
SoftwareSerial gps(10,11);
void setup() 
{
 //Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
 Serial.begin(9600);
 while(!Serial);
 //Being serial communication with Arduino and GPS Module //Important rate must be 9600
 gps.begin(9600);
 delay(1000);
 Serial.println("Setup Complete!");
}
void loop() 
{
 if(gps.available()){
 Serial.write(gps.read());
 }
 if(Serial.available()){    
   gps.write(Serial.read());
 }
}
