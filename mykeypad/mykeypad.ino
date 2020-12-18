#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);



int m1;
int m2;

int pos;
int row;

int r1=A0;
int r2=A1;
int r3=A2;
int r4=A3;

int c1=6;
int c2=7;
int c3=8;

void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
  
  pinMode(r1,OUTPUT);
  pinMode(r2,OUTPUT);
  pinMode(r3,OUTPUT);
  pinMode(r4,OUTPUT);

  pinMode(c1,INPUT);
  pinMode(c2,INPUT);
  pinMode(c3,INPUT);
  
}




void check_col1()
{
  digitalWrite(r1,LOW);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,HIGH);
  if(digitalRead(c1)==LOW)
  {
    lcd.setCursor(0,1);
    lcd.print(millis()/100);
    m1=m1+1;
    
    if(m1==5)
    {
     m1=1; 
    }
    
    if(m1==1)
    {
      lcd.setCursor(pos,row);
      lcd.print('1');
      
    }
    if(m1==2)
    {
      lcd.setCursor(pos,row);
      lcd.print('a');
    }
    
    if(m1==3)
    {
      lcd.setCursor(pos,row);
      lcd.print('b');
    }
    
    if(m1==4)
    {
      lcd.setCursor(pos,row);
      lcd.print('c');
    }
    
    
    delay(100);
  }
  
  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,HIGH);
  if(digitalRead(c1)==LOW)
  {
     m2=m2+1;
    
    if(m2==5)
    {
     m2=1; 
    }
    
    if(m2==1)
    {
      lcd.setCursor(pos,row);
      lcd.print('4');
      
    }
    if(m2==2)
    {
      lcd.setCursor(pos,row);
      lcd.print('j');
    }
    
    if(m2==3)
    {
      lcd.setCursor(pos,row);
      lcd.print('k');
    }
    
    if(m2==4)
    {
      lcd.setCursor(pos,row);
      lcd.print('l');
    }
    
    
    delay(100);
  }
  
  digitalWrite(r1,HIGH);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,LOW);
  digitalWrite(r4,HIGH);
  if(digitalRead(c1)==LOW)
  {
    
  }
  
  digitalWrite(r1,HIGH);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,LOW);
  if(digitalRead(c1)==LOW)
  {
    
  }
  
  digitalWrite(r1,HIGH);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,HIGH);
  
  
  
 
}





void check_col2()
{
  digitalWrite(r1,LOW);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,HIGH);
  if(digitalRead(c2)==LOW)
  {
    
  }
  
  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,HIGH);
  if(digitalRead(c2)==LOW)
  {
    
  }
  
  digitalWrite(r1,HIGH);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,LOW);
  digitalWrite(r4,HIGH);
  if(digitalRead(c2)==LOW)
  {
    
  }
  
  digitalWrite(r1,HIGH);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,LOW);
  if(digitalRead(c2)==LOW)
  {
    
  }
  
  digitalWrite(r1,HIGH);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,HIGH);
  
  
  
 
}


void check_col3()
{
  digitalWrite(r1,LOW);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,HIGH);
  if(digitalRead(c3)==LOW)
  {
    
  }
  
  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,HIGH);
  if(digitalRead(c3)==LOW)
  {
    
  }
  
  digitalWrite(r1,HIGH);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,LOW);
  digitalWrite(r4,HIGH);
  if(digitalRead(c3)==LOW)
  {
    
  }
  
  digitalWrite(r1,HIGH);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,LOW);
  if(digitalRead(c3)==LOW)
  {
    
  }
  
  digitalWrite(r1,HIGH);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,HIGH);
  
  
  
 
}








void loop()
{
  int val;
  //setting the columns as high initially
  digitalWrite(c1,HIGH);
  digitalWrite(c2,HIGH);
  digitalWrite(c3,HIGH);
  
  digitalWrite(r1,LOW);
  digitalWrite(r2,LOW);
  digitalWrite(r3,LOW);
  digitalWrite(r4,LOW);
  
  
  
  while(1)
  {
  
    
  digitalWrite(c1,HIGH);
  digitalWrite(c2,HIGH);
  digitalWrite(c3,HIGH);
 
  
  
  digitalWrite(r1,LOW);
  digitalWrite(r2,LOW);
  digitalWrite(r3,LOW);
  digitalWrite(r4,LOW);
  
  while(digitalRead(c1)==HIGH && digitalRead(c2)==HIGH && digitalRead(c3)==HIGH);
  
  
  row=0;
 
 pos=pos-1;
 
  if(digitalRead(c1)==0)
  {
    pos=pos+1;
  
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
  
}
}
