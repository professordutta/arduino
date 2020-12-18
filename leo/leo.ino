
void setup() {
  // open the serial port:
  // initialize control over the keyboard:
  Mouse.begin();
}

void loop() 
{
  Mouse.move(300,100,0);
  Mouse.end();
  delay(300);
 
  
}
