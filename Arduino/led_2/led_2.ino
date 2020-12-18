int temp;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
temp=analogRead(A0);
Serial.print("Integer output is:");
Serial.println(temp);
delay(1000);
}
