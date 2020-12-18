#include<stdlib.h>
#define SSID "mriic_IOT"
#define PASS "mriic_iot"
#define IP "184.106.153.149" // thingspeak.com
String GET = "GET /update?key=1MWKJ3ITBYFTZKW6&";
//8X7EJE0ZEOLMLVFZ
int delaycount=2000;
char str[100];
char str2[20];
// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(115200);
    Serial.println("AT");
  delay(1000);
 // if(Serial.find("OK")){
   
    connectWiFi();
  }
  //}

void loop() {
  strcpy(str,"field1=");
  strcat(str,"15");
  updateThings(str);
  delay(delaycount);  
}

void updateThings(String tenmpF){

  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += IP;
  cmd += "\",80";
  Serial.println(cmd);
  delay(2000);
  if(Serial.find("Error")){
    return;
  }
  cmd = GET;
  cmd += tenmpF;
  cmd += "\r\n\r\n";
  Serial.print("AT+CIPSEND=");
  Serial.println(cmd.length());
  if(Serial.find(">")){
    Serial.print(cmd);
  }
  else{
    Serial.println("AT+CIPCLOSE=4");
  }
  delay(700);
}

boolean connectWiFi(){
  Serial.println("AT+CWMODE=1");
  delay(2000);
  String cmd="AT+CWJAP=\"";
  cmd+=SSID;
  cmd+="\",\"";
  cmd+=PASS;
  cmd+="\"";
  Serial.println(cmd);
  delay(2000);
  if(Serial.find("OK")){
    return true;
  }
  else{
    return false;
  }
}
