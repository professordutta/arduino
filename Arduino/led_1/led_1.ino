int n=300;
int parth = 13;
void setup() {
  // put your setup code here, to run once:
  pinMode(parth,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(parth,HIGH);
delay(n);
digitalWrite(parth,LOW);
delay(n);
}
