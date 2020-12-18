int temp,temp1;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:


temp=analogRead(A0);

temp1 = (temp*500)/1023;
Serial.print("*");
Serial.print(temp1);
Serial.println("#");

delay(4000);


}
