int led = 13;
int val;
void setup() {
  Serial.begin( 9600 ); 
  pinMode(led,OUTPUT);
  
}
void loop() {
  while(!Serial.available());
  if ( Serial.available() > 0 ) {
    // read a numbers from serial port
    val = Serial.parseInt();
    if (val > 0) {
        Serial.print("Data received is: ");
        Serial.println(String(val));
        // Here blink the LED        
        blk(val);
    }
  }
}
void blk(int val) {
  for (int i=0; i<val; i++) {
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
    delay(1000);
  }
}
