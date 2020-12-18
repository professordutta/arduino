int op1=2;
int op2=3;
int op3=4;
int op4=5;

char temp;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(op1,OUTPUT);
pinMode(op2,OUTPUT);
pinMode(op3,OUTPUT);
pinMode(op4,OUTPUT);

digitalWrite(op1,LOW);
digitalWrite(op2,LOW);
digitalWrite(op3,LOW);
digitalWrite(op4,LOW);

}

void loop() {
  // put your main code here, to run repeatedly:

while(!Serial.available());
if(Serial.available()>0)
{
  temp=Serial.read();
}

if(temp=='A')
{
 digitalWrite(op1,HIGH);
 digitalWrite(op2,LOW);
 digitalWrite(op3,HIGH);
 digitalWrite(op4,LOW);
}

if(temp=='B')
{
 digitalWrite(op1,LOW);
 digitalWrite(op2,HIGH);
 digitalWrite(op3,LOW);
 digitalWrite(op4,HIGH);
}

if(temp=='C')
{
 digitalWrite(op1,HIGH);
 digitalWrite(op2,LOW);
 digitalWrite(op3,LOW);
 digitalWrite(op4,HIGH);
}

if(temp=='D')
{
 digitalWrite(op1,LOW);
 digitalWrite(op2,HIGH);
 digitalWrite(op3,HIGH);
 digitalWrite(op4,LOW);
}

if(temp=='E')
{
 digitalWrite(op1,LOW);
 digitalWrite(op2,LOW);
 digitalWrite(op3,LOW);
 digitalWrite(op4,LOW);
}



}
