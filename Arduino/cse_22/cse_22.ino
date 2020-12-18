void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:

if(digitalRead(2)==LOW)
{
  Serial.println("Alert Raised");
  while(digitalRead(2)==LOW);
  //delay(1500);
}

if(digitalRead(3)==LOW)
{
  Serial.println("Alert Deactivated");
  while(digitalRead(3)==LOW);
  //delay(1500);
}


}
