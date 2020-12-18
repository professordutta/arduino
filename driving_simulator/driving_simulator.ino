#include "Keyboard.h"
int temp,m;
void setup() {
  // put your setup code here, to run once:
  Keyboard.begin();
  pinMode(10,INPUT);
  digitalWrite(10,HIGH);
  pinMode(9,INPUT);
  digitalWrite(9,HIGH);
  pinMode(7,INPUT);
  digitalWrite(7,HIGH);
  pinMode(2,OUTPUT);
  digitalWrite(2,HIGH);
}


void steer()
{
  temp=analogRead(A0);
  if(temp>640 && temp<670)
{
  Keyboard.press('A');
  delay(3);
  Keyboard.release('A');
    
}

if(temp>680 && temp<750)
{
  Keyboard.press('D');
  delay(3);
  Keyboard.release('D');
}


if(temp>670 && temp<680)
{
 //AKeyboard.releaseAll();
 
  
  
}

}

void loop() {
  // put your main code here, to run repeatedly:

steer();
if(digitalRead(10)==LOW)
{
    Keyboard.press('W');
    steer();
  
}


if(digitalRead(10)==HIGH)
{
  Keyboard.release('W');
  steer();

}


if(digitalRead(9)==LOW)
{
  Keyboard.press('B');
  Keyboard.release('B');
}


if(digitalRead(7)==LOW)
{
  Keyboard.press('X');
  delayMicroseconds(100);
  m=1;
  
}

if(m==1 && digitalRead(7)==HIGH)
{
  Keyboard.release('X');
  m=0;
}
}
  



