int x,y;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

x = analogRead(A0);
y = analogRead(A1);
Serial.print("X:");
Serial.println(x);
Serial.print("Y:");
Serial.println(y);
delay(300);
}
