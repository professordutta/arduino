void setup()
{
  Mouse.begin();
}

void loop()
{
  Mouse.move(300,100,0);
  delay(100);
  Mouse.end();
}
