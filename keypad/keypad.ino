int r1=A3;
int r2=A2;
int r3=A1;
int r4=A0;

int c1=7;
int c2=8;
int c3=5;
int c4=4;

void setup()
{
  Serial.begin(9600);
  
  pinMode(r1,OUTPUT);
  pinMode(r2,OUTPUT);
  pinMode(r3,OUTPUT);
  pinMode(r4,OUTPUT);

  pinMode(c1,INPUT);
  pinMode(c2,INPUT);
  pinMode(c3,INPUT);
  pinMode(c4,INPUT);
  
}
void loop()
{
  int val;
  //setting the columns as high initially
  digitalWrite(c1,HIGH);
  digitalWrite(c2,HIGH);
  digitalWrite(c3,HIGH);
  digitalWrite(c4,HIGH);
  
  //checking everything one by one
  //case 1: col1 =0 while other col as 1
  digitalWrite(r1,LOW);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,HIGH);
  //checking each column for row1 one by one
  if(digitalRead(c1)==0)
  {
    Serial.println("key 1 pressed");
  }
  else if(digitalRead(c2)==0)
  {
    Serial.println("Key 2 pressed");
  }
  else if(digitalRead(c3)==0)
  {
    Serial.println("Key 3 pressed");
  }
  else if(digitalRead(c4)==0)
  {
    Serial.println("Key A pressed");
  }
  
  //case 2: col2 =0 while other col as 1
  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,HIGH);
  //checking each column for row1 one by one
  if(digitalRead(c1)==0)
  {
    Serial.println("key 4 pressed");
  }
  else if(digitalRead(c2)==0)
  {
    Serial.println("Key 5 pressed");
  }
  else if(digitalRead(c3)==0)
  {
    Serial.println("Key 6 pressed");
  }
  else if(digitalRead(c4)==0)
  {
    Serial.println("Key B pressed");
  }
  
  //case 3: col3 =0 while other col as 1
  digitalWrite(r1,HIGH);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,LOW);
  digitalWrite(r4,HIGH);
  //checking each column for row1 one by one
  if(digitalRead(c1)==0)
  {
    Serial.println("key 7 pressed");
  }
  else if(digitalRead(c2)==0)
  {
    Serial.println("Key 8 pressed");
  }
  else if(digitalRead(c3)==0)
  {
    Serial.println("Key 9 pressed");
  }
  else if(digitalRead(c4)==0)
  {
    Serial.println("Key C pressed");
  }
  
  //case 1: col1 =0 while other col as 1
  digitalWrite(r1,HIGH);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,LOW);
  //checking each column for row1 one by one
  if(digitalRead(c1)==0)
  {
    Serial.println("key F pressed");
  }
  else if(digitalRead(c2)==0)
  {
    Serial.println("Key 0 pressed");
  }
  else if(digitalRead(c3)==0)
  {
    Serial.println("Key E pressed");
  }
  else if(digitalRead(c4)==0)
  {
    Serial.println("Key D pressed");
  }
  //giving delay between keypress
  delay(200);
  
}


