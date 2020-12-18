#include<SoftwareSerial.h>
SoftwareSerial esp(10,11);


void setup() {
  
  esp.begin(115200);
  Serial.begin(9600);
  delay(1000);
  
  esp.println("AT+RST\r\n");
  delay(5000);

  esp.println("AT+CWMODE=3\r\n");
  delay(1000);

  esp.println("AT+CWJAP=\"mriic_IOT\",\"mriic_iot\"\r\n");
  delay(2000);

  esp.println("AT+CIPMUX=0\r\n");
  delay(1000);
}

void loop() {
  
  
  esp.println("AT+CIPSTART=\"TCP\",\"184.106.153.149\",80\r\n");
  //delay(1000);
  if(esp.find("OK")){
    Serial.print("TCP CONNECT"); 
  }
  
  String sendStr = "GET/update?key=1WILU5HXHCH2BBBR&field1=";
  sendStr += 123;

  sendStr += "\r\n\r\n";
  
  String ATcmd = "AT+CIPSEND=";
  ATcmd += sendStr.length();
  ATcmd += "\r\n";
  
  delay(1000);
  
  esp.println(ATcmd);
  delay(100);
  if (esp.find(">")) {
    esp.println(sendStr);
    Serial.println("DATA SENT");
  }
  
  delay(1000);
}

