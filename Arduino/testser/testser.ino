char temp[10];
String op = " ";
int z,m;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0)
  {
    z=Serial.readBytesUntil('#',temp,20);
    op = String(temp);
    m = op.toInt();
    Serial.println(m);
    delay(2000);
  }

}
