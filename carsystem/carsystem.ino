


//Useful hints for the problem statement
//*********************************************************************************************************
// in this code we need to control the relay through alcohol sensor o/p which is analog value

//the system must be bypassed by entering correct password in the bypass procedure

//16*2 lcd display is used as o/p for user interaction through keypad

//flag monitoring by o/p of comparator can be one option

// the other option is to digitize the alcohol sensor o/p and set the digital threshold for the comparision

// 8 pins will be used for keypad interfacing

// 6 pins will be used for the lcd interface

// 1 pin will be the i/p to arduino from alcohol sensor

// 1 pin will be the o/p pin to control the relay which will further control the start of the car

//************************************************************************************************************




#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 7, 6, 5, 4);

const int ainput = A0;     // i/p from sensor
const int relay =  3; 
int value = 0;
int r1=A5;
int r2=A4;
int r3=A3;
int r4=A2;

int c1=11;
int c2=10;
int c3=9;
int c4=8;

char temp[4];
int m;





void setup()
{
  pinMode(2,INPUT);
  pinMode(3,OUTPUT);
  
  digitalWrite(3,LOW);
  lcd.begin(16, 2); 
  lcd.setCursor(0, 0);
  pinMode(r1,OUTPUT);
  pinMode(r2,OUTPUT);
  pinMode(r3,OUTPUT);
  pinMode(r4,OUTPUT);

  pinMode(c1,INPUT);
  pinMode(c2,INPUT);
  pinMode(c3,INPUT);
  pinMode(c4,INPUT);
  
}



void check_col1()
{
  digitalWrite(r1,HIGH);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,HIGH);
  
  digitalWrite(r1,LOW);
  if(digitalRead(c1)==0)
  {
    lcd.print("1");
    temp[m]='1';
    delay(100);
    digitalWrite(r1,HIGH);
  }
  
  digitalWrite(r2,LOW);
  if(digitalRead(c1)==0)
  {
    lcd.print("4");
    temp[m]='4';
    delay(100);
    digitalWrite(r2,HIGH);
  }
  
  digitalWrite(r3,LOW);
  if(digitalRead(c1)==0)
  {
    lcd.print("7");
    temp[m]='7';
    delay(100);
    digitalWrite(r3,HIGH);
  }
  
  
  digitalWrite(r4,LOW);
  if(digitalRead(c1)==0)
  {
    lcd.print("*");
    temp[m]='*';
    delay(100);
    digitalWrite(r4,HIGH);
  }
  delay(200);
}

void check_col2()
{
  digitalWrite(r1,HIGH);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,HIGH);
  
  digitalWrite(r1,LOW);
  if(digitalRead(c2)==0)
  {
    lcd.print("2");
    temp[m]='2';
    delay(100);
    digitalWrite(r1,HIGH);
  }
  
  digitalWrite(r2,LOW);
  if(digitalRead(c2)==0)
  {
    lcd.print("5");
    temp[m]='5';
    delay(100);
    digitalWrite(r2,HIGH);
  }
  
  digitalWrite(r3,LOW);
  if(digitalRead(c2)==0)
  {
    lcd.print("8");
    temp[m]='8';
    delay(100);
    digitalWrite(r3,HIGH);
  }
  
  
  digitalWrite(r4,LOW);
  if(digitalRead(c2)==0)
  {
    lcd.print("0");
    temp[m]='0';
    delay(100);
    digitalWrite(r4,HIGH);
  }
  delay(200);
}


void check_col3()
{
  digitalWrite(r1,HIGH);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,HIGH);
  
  digitalWrite(r1,LOW);
  if(digitalRead(c3)==0)
  {
    lcd.print("3");
    temp[m]='3';
    delay(100);
    digitalWrite(r1,HIGH);
  }
  
  digitalWrite(r2,LOW);
  if(digitalRead(c3)==0)
  {
    lcd.print("6");
    temp[m]='6';
    delay(100);
    digitalWrite(r2,HIGH);
  }
  
  digitalWrite(r3,LOW);
  if(digitalRead(c3)==0)
  {
    lcd.print("9");
    temp[m]='9';
    delay(100);
    digitalWrite(r3,HIGH);
  }
  
  
  digitalWrite(r4,LOW);
  if(digitalRead(c3)==0)
  {
    lcd.print("#");
    temp[m]='#';
    delay(100);
    digitalWrite(r4,HIGH);
  }
  delay(200); 
}

void check_col4()
{
  digitalWrite(r1,HIGH);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,HIGH);
  
  digitalWrite(r1,LOW);
  if(digitalRead(c4)==0)
  {
    lcd.print("A");
    temp[m]='A';
    delay(100);
    digitalWrite(r1,HIGH);
  }
  
  digitalWrite(r2,LOW);
  if(digitalRead(c4)==0)
  {
    lcd.print("B");
    temp[m]='B';
    delay(100);
    digitalWrite(r2,HIGH);
  }
  
  digitalWrite(r3,LOW);
  if(digitalRead(c4)==0)
  {
    lcd.print("C");
    temp[m]='C';
    delay(100);
    digitalWrite(r3,HIGH);
  }
  
  
  digitalWrite(r4,LOW);
  if(digitalRead(c4)==0)
  {
    lcd.print("D");
    temp[m]='D';
    delay(100);
    digitalWrite(r4,HIGH);
  }
  delay(200); 
}


void scan()
{
  digitalWrite(c1,HIGH);
  digitalWrite(c2,HIGH);
  digitalWrite(c3,HIGH);
  digitalWrite(c4,HIGH);
  
  digitalWrite(r1,LOW);
  digitalWrite(r2,LOW);
  digitalWrite(r3,LOW);
  digitalWrite(r4,LOW);
  
  while(digitalRead(c1)==1 && digitalRead(c2)==1 && digitalRead(c3)==1 && digitalRead(c4)==1);
  digitalWrite(r1,LOW);
  digitalWrite(r2,LOW);
  digitalWrite(r3,LOW);
  digitalWrite(r4,LOW);
  
  
  if(digitalRead(c1)==0)
  {
    check_col1();
  }
  
  if(digitalRead(c2)==0)
  {
    check_col2();
  }
  
  if(digitalRead(c3)==0)
  {
    check_col3();
  }
  
  if(digitalRead(c4)==0)
  {
    check_col4();
  }
  
}




void bypass()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Enter Password:");
  lcd.setCursor(0,1);
  for(m=0;m<4;m++)
  {
    scan();
  }
  
  if(temp[0]=='0' && temp[1]=='7' && temp[2]=='8' && temp[3]=='6')
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("MATCHED...");
    delay(2000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Successfuly");
    lcd.setCursor(0,1);
    lcd.print("bypassed....");
    delay(2000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("start the car..");
    digitalWrite(3,HIGH);
    
  }
  
  else
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("NOT MATCHED...");
    delay(2000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("System");
    lcd.setCursor(0,1);
    lcd.print("Locked...");
    digitalWrite(3,LOW);
  }
  }



void alcohol_test()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("test now...");
  
  delay(200);
  lcd.clear();
  lcd.print("OUT:");
  
  for(m=0;m<20;m++)
  {
  
  value=analogRead(A0);
  
  lcd.setCursor(0,4);
  
  lcd.print(value);
  delay(500);
  }
  
  if(value<190 && value>150)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Test Passed");
    digitalWrite(3,HIGH);
    
  }
  
  if(value>200)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Test Failed");
    digitalWrite(3,LOW);
  }
  
  if(value<150)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Try Again..");
    digitalWrite(3,LOW);
  }
}
void loop()
{
  
  
  
  lcd.print("WELCOME....");
  lcd.setCursor(0,5);
  lcd.print("DRIVER...");
  
  delay(2000);
  
  lcd.clear();
  
  lcd.setCursor(0,0);
  
  lcd.print("1:Alcohol Test");
  lcd.setCursor(0,1);
  lcd.print("2:Bypass System");
  
  
  //setting the columns as high initially
  digitalWrite(c1,HIGH);
  digitalWrite(c2,HIGH);
  digitalWrite(c3,HIGH);
  digitalWrite(c4,HIGH);
  
  /*digitalWrite(r1,LOW);
  digitalWrite(r2,LOW);
  digitalWrite(r3,LOW);
  digitalWrite(r4,LOW);
 */
  
  while(1)
  {
    for(m=0;m<1;m++)
    {
    scan();
    }
    if(temp[0]=='1')
    {
      alcohol_test();
    }
    
    if(temp[0]=='2')
    {
      bypass();
    }
    
  
  }
  
}
  
  




