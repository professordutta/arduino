#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
#include<String.h>
SoftwareSerial mySerial(10,11);
LiquidCrystal lcd(22,23,24,25,26,27);
int op1=28;
int op2=29;
int op3=30;
int op4=31;

int m;
int count;
char temp_var;
char temp[13];
char temp1[13] = { '1','6','0','0','6','6','9','2','5','6','B','4','\0'};
char temp2[13] = { '1','1','0','0','0','0','E','7','D','A','2','C','\0'};
char temp3[13] = { '1','6','0','0','6','6','7','0','2','4','2','4','\0'};
char temp4[13] = { '1','6','0','0','6','5','C','A','D','5','6','C','\0'};
char temp5[13] = { '1','6','0','0','6','6','A','1','2','2','F','3','\0'};
char temp6[13] = { '1','6','0','0','6','5','E','3','8','D','1','D','\0'};

int i1 = 5;
int i2 = 10;
int i3 = 15;
int i4 = 20;
int i5 = 25;
int i6 = 30;
int c1,c2,c3,c4,c5,c6;
int t1,t2,t3,t4,t5,t6;
int total;



void setup()
{
  mySerial.begin(9600);
  Serial1.begin(9600);
  Serial.begin(9600);
  lcd.begin(20,4);
  lcd.print("Welcome User...");
  pinMode(3,INPUT);
  digitalWrite(3,HIGH);
  pinMode(op1,OUTPUT);
  pinMode(op2,OUTPUT);
  pinMode(op3,OUTPUT);
  pinMode(op4,OUTPUT);
  digitalWrite(op1,LOW);
  digitalWrite(op2,LOW);
  digitalWrite(op3,LOW);
  digitalWrite(op4,LOW);
 
}

void loop()
{
   for(m=0;m<12;m++)
  {
    while(!mySerial.available()&& !Serial1.available() && digitalRead(3)==HIGH);
    
    if(digitalRead(3)==LOW)
    {
      total = t1+t2+t3+t4+t5+t6;
      lcd.clear();
      lcd.print("Total:");
      lcd.print(total);
      lcd.setCursor(0,1);
      lcd.print("Thanks Please");
      lcd.setCursor(0,2);
      lcd.print("Visit Again");
      Serial.println("Bill Receipt");
      Serial.print("Total:");
      Serial.print(total);
      Serial.println(" Rs.");
      Serial.println("Thanks");
      Serial.println("Visit Again");
      Serial.println(".............");
      while(1);
    }
    
    if(mySerial.available()>0)
    {
      count = 1;
      temp[m]=mySerial.read();
      //Serial.print(temp[m]);
    }
    
    if(Serial1.available() > 0)
    {
      count = 2;
      temp_var = Serial1.read();
      m=12;
    }
  }

  if( count == 1)
  {
  
  temp[12]='\0';
  
  
  if(strcmp(temp,temp1)==0)
  {
    c1 = c1 + 1;
    t1 = c1*i1;
    delay(100);
  }
  
  if(strcmp(temp,temp2)==0)
  {
    c2 = c2 + 1;
    t2 = c2*i2;
    delay(100);
  }
  
  if(strcmp(temp,temp3)==0)
  {
    c3 = c3 + 1;
    t3 = c3*i3;
    delay(100);
  }
  
  if(strcmp(temp,temp4)==0)
  {
    c4 = c4 + 1;
    t4 = c4*i4;
    delay(100);
  }
  
  if(strcmp(temp,temp5)==0)
  {
    c5 = c5 + 1;
    t5 = c5*i5;
    delay(100);
  }
  
  if(strcmp(temp,temp6)==0)
  {
    c6 = c6 + 1;
    t6 = c6*i6;
    delay(100);
  }
  }
  
  
  
  
  if(count == 2)
  {
    if (temp_var == 'A')
    {
      digitalWrite(op1,HIGH);
      digitalWrite(op2,LOW);
      digitalWrite(op3,HIGH);
      digitalWrite(op4,LOW);
    }
    
    if (temp_var == 'B')
    {
      digitalWrite(op1,LOW);
      digitalWrite(op2,HIGH);
      digitalWrite(op3,LOW);
      digitalWrite(op4,HIGH);
    }
    
    if (temp_var == 'C')
    {
      digitalWrite(op1,HIGH);
      digitalWrite(op2,LOW);
      digitalWrite(op3,LOW);
      digitalWrite(op4,LOW);
    }
    
    if (temp_var == 'D')
    {
      digitalWrite(op1,LOW);
      digitalWrite(op2,LOW);
      digitalWrite(op3,HIGH);
      digitalWrite(op4,LOW);
    }
    
    if (temp_var == 'E')
    {
      digitalWrite(op1,LOW);
      digitalWrite(op2,LOW);
      digitalWrite(op3,LOW);
      digitalWrite(op4,LOW);
    }
    
    
    
    
  }
 
    
 


}
