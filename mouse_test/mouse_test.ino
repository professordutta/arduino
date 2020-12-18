int i;
int button1=2;
int button2=3;
int button3=4;
int x,y,z;


void setup()
{
  Serial.begin(9600);

  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
  pinMode(button3,INPUT);
  digitalWrite(button1,HIGH);
  digitalWrite(button2,HIGH);
  digitalWrite(button3,HIGH);


}
void loop()
{
 
  x=digitalRead(button1);
  y=digitalRead(button2);
  z=digitalRead(button3);
  delay(100);
  
  if(x==HIGH && y==HIGH && z==HIGH)
  {
    i++;
    Serial.println(i);
    delay(10);
  }
  
  if(x==LOW && y==HIGH && z==HIGH)
  {
    i--;
    Serial.println(i);
    delay(10);
  }
  
  
  
}


