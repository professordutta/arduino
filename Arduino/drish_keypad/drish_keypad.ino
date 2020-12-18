int c1=2;
int c2=3;
int c3=4;
int r1=6;
int r2=7;
int r3=8;
int r4=9;
int led=13;
char temp[3];
int m, count; 
void setup() {
  // put your setup code here, to run once:
pinMode(c1,INPUT);
pinMode(c2,INPUT);
pinMode(c3,INPUT);
pinMode(r1,OUTPUT);
pinMode(r2,OUTPUT);
pinMode(r3,OUTPUT);
pinMode(r4,OUTPUT);
pinMode(led,OUTPUT);
Serial.begin(9600);
}

void keypad_init()
{
  digitalWrite(c1,HIGH);
  digitalWrite(c2,HIGH);
  digitalWrite(c3,HIGH);
  digitalWrite(r1,LOW);
  digitalWrite(r2,LOW);
  digitalWrite(r3,LOW);
  digitalWrite(r4,LOW);
}

void check_col1()
{
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,HIGH);
  digitalWrite(r1,LOW);
  if(digitalRead(c1)==LOW)
  {
    Serial.print('1');
    temp[m]='1';
  }
  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW);
  if(digitalRead(c1)==LOW)
  {
    Serial.print('4');
    temp[m]='4';
  }
  digitalWrite(r2,HIGH);
  digitalWrite(r3,LOW);
  if(digitalRead(c1)==LOW)
  {
    Serial.print('7');
    temp[m]='7';
  }
  digitalWrite(r3,HIGH);
  digitalWrite(r4,LOW);
  if(digitalRead(c1)==LOW)
  {
    Serial.print('*');
    temp[m]='*';
  }
  digitalWrite(r4,HIGH);
  delay(1000);
}

void check_col2()
{
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,HIGH);
  digitalWrite(r1,LOW);
  if(digitalRead(c2)==LOW)
  {
    Serial.print('2');
    temp[m]='2';
  }
  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW);
  if(digitalRead(c2)==LOW)
  {
    Serial.print('5');
    temp[m]='5';
  }
  digitalWrite(r2,HIGH);
  digitalWrite(r3,LOW);
  if(digitalRead(c2)==LOW)
  {
    Serial.print('8');
    temp[m]='8';
  }
  digitalWrite(r3,HIGH);
  digitalWrite(r4,LOW);
  if(digitalRead(c2)==LOW)
  {
    Serial.print('0');
    temp[m]='0';
  }
  digitalWrite(r4,HIGH);
  delay(1000);
}

void check_col3()
{
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,HIGH);
  digitalWrite(r1,LOW);
  if(digitalRead(c3)==LOW)
  {
    Serial.print('3');
    temp[m]='3';
  }
  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW);
  if(digitalRead(c3)==LOW)
  {
    Serial.print('6');
    temp[m]='6';
  }
  digitalWrite(r2,HIGH);
  digitalWrite(r3,LOW);
  if(digitalRead(c3)==LOW)
  {
    Serial.print('9');
    temp[m]='9';
  }
  digitalWrite(r3,HIGH);
  digitalWrite(r4,LOW);
  if(digitalRead(c3)==LOW)
  {
    Serial.print('#');
    temp[m]='#';
  }
  digitalWrite(r4,HIGH);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
for(m=0;m<3;m++)
{
keypad_init();

//wait for key press

while(digitalRead(c1)==HIGH && digitalRead(c2)==HIGH && digitalRead(c3)==HIGH);

if(digitalRead(c1)==LOW)
{
  check_col1();
}
if(digitalRead(c2)==LOW)
{
  check_col2();
}
if(digitalRead(c3)==LOW)
{
  check_col3();
}

}

if(temp[0]=='7' && temp[1]=='8' && temp[2]=='6')
{
  Serial.println("Password Matched");
  count = 0;
  digitalWrite(led,HIGH);
  delay(1000);
  digitalWrite(led,LOW);
}

else
{
  Serial.println("Invalid Password");
  count = count + 1;
  if(count==3)
  {
    Serial.println("No more trials allowed");
    Serial.println("....System Locked...");
    while(1);
  }
}

}
