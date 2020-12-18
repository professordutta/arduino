#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 7, 12, 11, 10, 9);

int next=24;
int place=25;
int amount;

int r1=3;
int r2=2;
int r3=22;
int r4=23;

int c1=6;
int c2=5;
int c3=4;

char temp;

int x;

float famt,tamt;
int q1,q2,q3,q4;

void setup() {
   q1=q2=q3=q4=48;
  // set up the LCD's number of columns and rows: 
  
  lcd.begin(20, 4);
  // Print a message to the LCD.
  lcd.print("    WELCOME TO");
  lcd.setCursor(0,1);
  lcd.print("  ROBO RESTAURANT  ");
  delay(2000);
  lcd.clear();
  
  pinMode(24,INPUT);
  pinMode(25,INPUT);
  
  digitalWrite(24,HIGH);
  digitalWrite(25,HIGH);
  
  
  pinMode(r1,OUTPUT);
  pinMode(r2,OUTPUT);
  pinMode(r3,OUTPUT);
  pinMode(r4,OUTPUT);

  pinMode(c1,INPUT);
  pinMode(c2,INPUT);
  pinMode(c3,INPUT);
  
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
  
  pinMode(14,INPUT);
  digitalWrite(14,HIGH);
  
  
  
  lcd.setCursor(0, 0);
  lcd.print("Place Your Order");
  delay(1000);
  lcd.clear();
  lcd.print("Enter Code...");
  
}


void check_col1()
{
  digitalWrite(r1,LOW);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,HIGH);
  if(digitalRead(c1)==LOW)
  {
    temp='1';
    lcd.print(temp);
    delay(50);
  }
  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW);
  if(digitalRead(c1)==LOW)
  {
    temp='4';
    lcd.print(temp);
    delay(50);
  }
  digitalWrite(r2,HIGH);
  digitalWrite(r3,LOW);
  if(digitalRead(c1)==LOW)
  {
    temp='7';
    lcd.print(temp);
    delay(50);
  }
  digitalWrite(r3,HIGH);
  digitalWrite(r4,LOW);
  if(digitalRead(c1)==LOW)
  {
    temp='*';
    lcd.print(temp);
    delay(50);
  }
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
    temp='2';
    lcd.print(temp);
    delay(50);
  }
  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW);
  if(digitalRead(c2)==LOW)
  {
    temp='5';
    lcd.print(temp);
    delay(50);
  }
  digitalWrite(r2,HIGH);
  digitalWrite(r3,LOW);
  if(digitalRead(c2)==LOW)
  {
    temp='8';
    lcd.print(temp);
    delay(50);
  }
  digitalWrite(r3,HIGH);
  digitalWrite(r4,LOW);
  if(digitalRead(c2)==LOW)
  {
    temp='0';
    lcd.print(temp);
    delay(50);
  }
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
    temp='3';
    lcd.print(temp);
    delay(50);
  }
  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW);
  if(digitalRead(c3)==LOW)
  {
    temp='6';
    lcd.print(temp);
    delay(50);
  }
  digitalWrite(r2,HIGH);
  digitalWrite(r3,LOW);
  if(digitalRead(c3)==LOW)
  {
    temp='9';
    lcd.print(temp);
    delay(50);
  }
  digitalWrite(r3,HIGH);
  digitalWrite(r4,LOW);
  if(digitalRead(c3)==LOW)
  {
    temp='#';
    lcd.print(temp);
    delay(50);
  }
  digitalWrite(r4,HIGH);

}

void check_key()
{
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

void kinit()
{
  digitalWrite(c1,HIGH);
  digitalWrite(c2,HIGH);
  digitalWrite(c3,HIGH);
  
  digitalWrite(r1,LOW);
  digitalWrite(r2,LOW);
  digitalWrite(r3,LOW);
  digitalWrite(r4,LOW);
   
}


void test()
{
    while(digitalRead(24)==HIGH && digitalRead(25)==HIGH && digitalRead(14)==HIGH);
   
    if(digitalRead(25)==LOW)
    {
      lcd.clear();
      
      delay(500);
      digitalWrite(13,LOW);
      amount=(25*(q1-48)) + (80*(q2-48)) + (100*(q3-48)) + (40*(q4-48));
      famt=0.125*amount;
      tamt=famt+amount;
      
      lcd.setCursor(0,0);
      lcd.print("AMOUNT- Rs.");
      lcd.print(amount);
      lcd.setCursor(0,1);
      lcd.print("VAT 12.5%-Rs.");
      lcd.print(famt,2);
      lcd.setCursor(0,2);
      lcd.print("TOTAL-Rs.");
      lcd.print(tamt,2);
      delay(3000);
      lcd.clear();
      lcd.setCursor(0,1);
      lcd.print("     Thanks     ");
      lcd.setCursor(0,2);
      lcd.print("Please Visit Again");
      delay(1500);
     
     
     
      
    }
    
    
    if(digitalRead(24)==LOW)
    {
    
    lcd.clear();
    lcd.print("Enter next Code..");
    }
    
    
    if(digitalRead(14)==LOW)
  {
    lcd.clear();
    lcd.print("Burger: ");
    lcd.print(q1-48);
    lcd.setCursor(0,1);
    lcd.print("Pizza: ");
    lcd.print(q2-48);
    lcd.setCursor(0,2);
    lcd.print("Pasta: ");
    lcd.print(q3-48);
    lcd.setCursor(0,3);
    lcd.print("Pepsi: ");
    lcd.print(q4-48);
    delay(1000);
    
    //while(digitalRead(25)==HIGH);
    
    
    
  }
    
    

}

void loop() 
{
 
  digitalWrite(c1,HIGH);
  digitalWrite(c2,HIGH);
  digitalWrite(c3,HIGH);
  
  digitalWrite(r1,LOW);
  digitalWrite(r2,LOW);
  digitalWrite(r3,LOW);
  digitalWrite(r4,LOW);
  
  
  
  kinit();
  check_key();
  
  if(digitalRead(14)==HIGH)
  {
    
  
  
  if(temp=='1')
  {
    lcd.clear();
    lcd.print("Item Name: BURGER");
    lcd.setCursor(0,1);
    lcd.print("Enter Qty:");
    delay(200);
    kinit();
    check_key();
    
    x=temp;
    q1=x;
    temp='0';
  }
  
  
  
  if(temp=='2')
  {
    lcd.clear();
    lcd.print("Item Name: Pizza");
    lcd.setCursor(0,1);
    lcd.print("Enter Qty:");
    delay(200);
    kinit();
    check_key();
    
    x=temp;
    q2=x;
    temp='0';
    
  }
  
  
  if(temp=='3')
  {
    lcd.clear();
    lcd.print("Item Name: Pasta");
    lcd.setCursor(0,1);
    lcd.print("Enter Qty:");
    delay(200);
    kinit();
    check_key();
    
    x=temp;
    q3=x;
    temp='0';
  
  }
  
  
  if(temp=='4')
  {
    lcd.clear();
    lcd.print("Item Name: Pepsi");
    lcd.setCursor(0,1);
    lcd.print("Enter Qty:");
    delay(200);
    kinit();
    check_key();
    
    x=temp;
    q4=x;
    
    temp='0';
  
  }
  
  test();
  
  
  
  
  
 
 
  
  }
  
}
