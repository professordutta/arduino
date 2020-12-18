#include <LiquidCrystal.h>
#include <Servo.h>

Servo myservo1;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo
int pos = 0;    // variable to store the servo position
int x,y,x1,y1;
int I=1;
int E=1;
int flag;
LiquidCrystal lcd(12,11,10,9,8,7);
void setup() {
  // put your setup code here, to run once:
  lcd.begin(20,4);
  lcd.print("ANSH 2.0");
  lcd.setCursor(0,1);
  lcd.print("Ventilator");
  myservo1.attach(5); //myservo1 is for servo motor 1 for fixing oxygen cylinder supply
  myservo2.attach(6); //myservo 2 is the final motor connected at the outlet 
  pinMode(A2,INPUT_PULLUP);
  pinMode(A3,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), start_vent, FALLING);
  attachInterrupt(digitalPinToInterrupt(3), stop_vent, FALLING);
  delay(1000);
}

void start_vent() 
{
  flag=1;
}

void stop_vent()
{
  flag=0;
  x = analogRead(A0);
  y = analogRead(A1);
  x1=map(x,0,1023,0,70);
  y1=map(y,0,1023,0,68);
}


void loop() {
  // put your main code here, to run repeatedly:
  if(flag==0)
  {

 x = analogRead(A0);
 y = analogRead(A1);
 x1=map(x,0,1023,0,70);
 y1=map(y,0,1023,0,70);
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Oxygen:");
 lcd.print(x1);
 lcd.setCursor(0,1);
 lcd.print("Final:");
 lcd.print(y1);
 if(digitalRead(A2)==LOW)
 {
  I = I+1;
  if(I>=4)
  {
    I=1;
  }
  while(digitalRead(A2)==LOW);
 }
 
 if(digitalRead(A3)==LOW)
 {
  E = E+1;
  if(E>=5)
  {
    E=1;
  }
  while(digitalRead(A3)==LOW);
 }
 lcd.setCursor(0,2);
 lcd.print("I/E:");
 lcd.print(I);
 lcd.print("/");
 lcd.print(E);
 delay(1000);
 }


  if(flag==1)
  {
    //print message on LCD
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("ANSH2.0 working");
    
    // rotate the motors as per the requirement

    //set servo1 to a particular angle the variable is x1

    myservo1.write(x1);

    // rotate servo2 using information contained in y1 and p

    // p is no. of times valve closing and opening per minute

    // servo rotation should be from 0 to y1
    while(flag==1)
    {
      myservo2.write(y1);
      delay(I*1000);
      myservo2.write(0);
      delay(E*1000);
    }
   }
    
   
}
