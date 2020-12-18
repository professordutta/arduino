char temp;
void setup()
{
  Serial1.begin(9600);
}

void loop()
{
  while(!Serial1.available());
  if(Serial1.available()>0)
  {
    temp = Serial1.read();
    Keyboard.begin();
    Keyboard.print(temp);
    Keyboard.end();
  }
}
