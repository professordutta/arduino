char temp;
int i;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (!Serial.available());
  // stay on this line till no serial data is received
  if (Serial.available() > 0)
  {
    temp = Serial.read();
    if (temp == 'A')
    {
      for (i = 0; i < 10; i++)
      {
        digitalWrite(13, HIGH);
        delay(1000);
        digitalWrite(13, LOW);
        delay(1000);
      }
    }
  }

  }
