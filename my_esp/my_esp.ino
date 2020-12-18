int temp, temp1;
void setup() 
{
  
  Serial.begin(9600);
  
  
  delay(1000);
  
  Serial.println("AT+RST\r\n");
  delay(5000);

  Serial.println("AT+CWMODE=3\r\n");
  delay(1000);

  Serial.println("AT+CWJAP=\"D-Link_DIR-600M\",\"mriic28051960\"\r\n");
  delay(2000);

  Serial.println("AT+CIPMUX=0\r\n");
  delay(1000);
}

void loop() {
  
  temp=analogRead(A0);
  temp1=(temp*500)/1024;
  
  
  Serial.println("AT+CIPSTART=\"TCP\",\"184.106.153.149\",80\r\n");
  delay(1000);
  String sendStr = "GET /update?key=5VLUJQVYDCTOO49D&field1=56789";
  sendStr += "\r\n\r\n";
  
  String ATcmd = "AT+CIPSEND=";
  ATcmd += sendStr.length();
  ATcmd += "\r\n";
  
  //delay(1000);
  
  Serial.println(ATcmd);
  
  delay(1000);
  Serial.println(sendStr);
  
  delay(16*1000);
}
