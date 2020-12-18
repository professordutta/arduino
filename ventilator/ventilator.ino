/*
 MANAV RACHNA
 Emergency Ventilator Design
 for COVID-19 Patients  
 Code written by Dr.Umesh Dutta on 7th April 2020
 */
#include <LiquidCrystal.h>
LiquidCrystal lcd(A1,A2,A3,A4,A5,13);
int in1 = 12; // in1 of L298
int in2 = 11; // in2 of L298
int en1 = 10; // en1 of L298
int sw1 = 2; // this is for increasing the pressure applied on ambu bag
int sw2 = 3; // this is for decreasing the pressure applied on ambu bag

/*sw1 and sw2 are used 
 for controlling the tidal volume
 here interrupt based control mechanism is used
 to increase and decrease the pressure
 sw1 press increases the pressure value
 sw2 press decreases the pressure value
 */

int sw3 = 4; // this is used for clockwise rotation of motor

int sw4 = 5; // this is used for anticlockwise rotation of motor

int sw5 = 6; // this is start button for motor rotation

int x; // variable for storing pressure count value

int flag=0; // indicator for starting the operation

int temp; // variable for storing the speed setting value from potentiometer 

int pwm_value // variable for storing the pwm value for motor speed

int t3=3000; //time for high pressure
int t2=2000; //time for medum pressure
int t1=1000; //time for low pressure
//void increment_pressure()
//{
//  x = x+1;
//  if(x>3)
//  {
//    x=3;
//  }
//  Serial.println(x);
//}

//void decrement_pressure()
//{
//  x = x-1;
//  if(x<1)
//  {
//    x=1;
//  }
//  Serial.println(x);
//}

//routine for pump_in the air

void pump_in()
{
  analogWrite(en1,pwm_value) //setting the speed
  //rotating motor clockwise
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
}

//routine for pumping out the air

void pump_out()
{
 analogWrite(en1,pwm_value); //setting the speed
 //rotating motor anticlockwise
 digitalWrite(in1,LOW);
 digitalWrite(in2,HIGH); 
}

void my_delay()
{
  if(x==3)
  {
    delay(t3); //high pressure delay
  }
  if(x==2)
  {
    delay(t2); //medium pressure delay
  }
  if(x==1)
  {
    delay(t1); //low pressure delay
  }
}

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  Serial.begin(9600);
  pinMode(in1,OUTPUT); // motor 1 logic pin1
  pinMode(in2,OUTPUT); // motor 1 logic pin2
//  pinMode(en1,OUTPUT); // pwm pin to be used for speed control
  digitalWrite(in1,LOW); // default low
  digitalWrite(in2,LOW); //default low
  analogWrite(en1,255); // motor to run at full speed 
  pinMode(sw1,INPUT_PULLUP); //sw1 configured as i/p with pull up enabled
  pinMode(sw2,INPUT_PULLUP); // sw2 configured as i/p with pull up enabled
//  attachInterrupt(digitalPinToInterrupt(sw1),increment_pressure,FALLING); // interrupt on sw1
//  attachInterrupt(digitalPinToInterrupt(sw2),decrement_pressure,FALLING); // interrupt on sw2
  pinMode(sw3,INPUT_PULLUP);
  pinMode(sw4,INPUT_PULLUP);
  pinMode(sw5,INPUT_PULLUP);
  
  // now make the default state of all pins HIGH

//  digitalWrite(sw3,HIGH);
//  digitalWrite(sw4,HIGH);
//  digitalWrite(sw5,HIGH);

  //print the initial message on LCD display
  lcd.print("  Emergency");
  lcd.setCursor(0,1); // cursor on line 2
  lcd.print("  Ventilator");
}


void loop() {
  // put your main code here, to run repeatedly:

  temp = analogRead(A0); // read the speed setting 
  x=3;

  pwm_value = map(temp,0,1023,100,255); // map the speed in desired range of 100-255

  Serial.println(pwm_value);

  if(digitalRead(sw3)==LOW)
  {
    //clockwise rotation of motor to set the initial point
     Serial.println("I am here");
     analogWrite(en1,pwm_value);
     digitalWrite(in1,HIGH);
     digitalWrite(in2,LOW);
     while(digitalRead(sw3)==LOW);
     analogWrite(en1,0);
     digitalWrite(in1,LOW);
     digitalWrite(in2,LOW);
  }
  
  if(digitalRead(sw4)==LOW)
  {
    //anticlockwise rotation of motor to set the initial point
     analogWrite(en1,pwm_value);
     digitalWrite(in1,LOW);
     digitalWrite(in2,HIGH);
     while(digitalRead(sw4)==LOW);
     digitalWrite(in1,LOW);
     digitalWrite(in2,LOW);
  }

  if(digitalRead(sw3)==HIGH && digitalRead(sw4)==HIGH)
  {
    digitalWrite(in1,LOW); // default low
    digitalWrite(in2,LOW); //default low
  }

  if(digitalRead(sw5)==LOW)
  {
    flag=1;
    while(digitalRead(sw5)==LOW);
  }

  if(flag==1)
  {
    //start the air pumping operation
    pump_in(); //pump in O2
    my_delay(); //wait time for pressing the ambu bag
    pump_out(); //pump out CO2
    my_delay(); //wait time for releasing
  }
}
