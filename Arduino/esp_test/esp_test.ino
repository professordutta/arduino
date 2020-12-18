#include <SoftwareSerial.h>
SoftwareSerial mySerial(11,12);
char temp;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(1000);
  Serial.print("Hello");
  mySerial.begin(115200);
  pinMode(2,OUTPUT);
  delay(2000);

}

void loop() {
  // put your main code here, to run repeatedly: 
  mySerial.println("AT");
  digitalWrite(2,HIGH);
  delay(50);
  while(!mySerial.available());
  if(mySerial.available()>0)
  {
    temp=mySerial.read();
    Serial.print(temp);
  }
  delay(1000);
  digitalWrite(2,LOW);
  delay(2000);
}
