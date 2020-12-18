float temp;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("UMESH DUTTA");

}

void loop() {
  // put your main code here, to run repeatedly:

  temp=analogRead(A0);

  temp = (temp*5.0)/1023.0;

  Serial.println(temp);
  delay(1000);

}
