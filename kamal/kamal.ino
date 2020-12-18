
int i;
char temp;

void setup()
{
  pinMode(7,INPUT);
  Serial.begin(9600);
  Serial.println("UMESH");
}


void loop()
{
  temp=digitalRead(7);
  
  if(temp==HIGH)
  {
    Serial.println(i);
    delay(200);
    i++;
  }
}
