
#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

SoftwareSerial mySerial(10, 11); // RX, TX
LiquidCrystal lcd(13, 12, 6, 5, 4, 3);





int r1=A5;
int r2=A4;
int r3=A3;
int r4=A2;

int c1=A1;
int c2=A0;
int c3=7;
int c4=8;

int amount;
int x;

char temp[12];
int m;

int n,v,s;

int sw;

void gsm_init()
{
  Serial.begin(9600);  //Baud rate of the GSM/GPRS Module 
  Serial.print("\r");
  delay(1000);                  
  Serial.print("AT+CMGF=1\r");    
  delay(1000);
  Serial.print("AT+CMGS=\"+919873804937\"\r");    //Number to which you want to send the sms
  delay(1000); 
}

void sent()
{
  delay(1000);
  Serial.write(0x1A);
  delay(1000); 
}



void scan_choice()
{

 //setting the columns as high initially
  digitalWrite(c1,HIGH);
  digitalWrite(c2,HIGH);
  digitalWrite(c3,HIGH);
  digitalWrite(c4,HIGH);
  
  
  while(digitalRead(c1)==HIGH && digitalRead(c2)==HIGH && digitalRead(c3)==HIGH && digitalRead(c4)==HIGH);
  
  
  //checking everything one by one
  //case 1: col1 =0 while other col as 1
  digitalWrite(r1,LOW);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,HIGH);
  //checking each column for row1 one by one
  if(digitalRead(c1)==LOW)
  {
    x='1';
    Serial.println(x);
    delay(100);
  }
  else if(digitalRead(c2)==LOW)
  {
    x='2';
    Serial.println(x);
    delay(100);
  }
  else if(digitalRead(c3)==LOW)
  {
    x='3';
    Serial.println(x);
    delay(100);
  }
  else if(digitalRead(c4)==LOW)
  {
   x='A';
   Serial.println(x);
    delay(100);
  }
  
  //case 2: col2 =0 while other col as 1
  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,HIGH);
  //checking each column for row1 one by one
  if(digitalRead(c1)==LOW)
  {
    x='4';
    Serial.println(x);
    delay(100);
  }
  else if(digitalRead(c2)==LOW)
  {
    x='5';
    Serial.println(x);
    delay(100);
  }
  else if(digitalRead(c3)==LOW)
  {
    x='6';
    Serial.println(x);
    delay(100);
  }
  else if(digitalRead(c4)==LOW)
  {
    x='B';
    Serial.println(x);
    delay(100);
  }
  
  //case 3: col3 =0 while other col as 1
  digitalWrite(r1,HIGH);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,LOW);
  digitalWrite(r4,HIGH);
  //checking each column for row1 one by one
  if(digitalRead(c1)==LOW)
  {
    x='7';
    Serial.println(x);
    delay(100);
  }
  else if(digitalRead(c2)==LOW)
  {
    x='8';
    Serial.println(x);
    delay(100);
  }
  else if(digitalRead(c3)==LOW)
  {
   x='9';
   Serial.println(x);
    delay(100);
  }
  else if(digitalRead(c4)==LOW)
  {
   x='c';
   Serial.println(x);
    delay(100);
  }
  
  //case 1: col1 =0 while other col as 1
  digitalWrite(r1,HIGH);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,LOW);
  //checking each column for row1 one by one
  if(digitalRead(c1)==LOW)
  {
    x='F';
    Serial.println(x);
    delay(100);
  }
  else if(digitalRead(c2)==LOW)
  {
    x='0';
    Serial.println(x);
    delay(100);
  }
  else if(digitalRead(c3)==LOW)
  {
   x='E';
   Serial.println(x);
    delay(100);
  }
  else if(digitalRead(c4)==LOW)
  {
    x='D';
    Serial.println(x);
    delay(100);
  }
  //giving delay between keypress
  delay(200);
 }




void setup()  
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  lcd.begin(20,4);
  lcd.print("Welcome");
  pinMode(9,INPUT);
  pinMode(8,INPUT);
  
  mySerial.begin(9600);
  
  pinMode(r1,OUTPUT);
  pinMode(r2,OUTPUT);
  pinMode(r3,OUTPUT);
  pinMode(r4,OUTPUT);

  pinMode(c1,INPUT);
  pinMode(c2,INPUT);
  pinMode(c3,INPUT);
  pinMode(c4,INPUT);
  
  Serial.println("OM");
 }

void loop() // run over and over
{
  sw=digitalRead(9);
  if(sw==LOW)
  {
    
  for(m=0;m<12;m++)
  {
  while(!mySerial.available());
  if (mySerial.available())
  {
  temp[m]=mySerial.read();
  Serial.write(temp[m]);
  }
  }
  
  if(temp[11]=='E')
  {
    lcd.setCursor(0,1);
    lcd.print("UMESH DUTTA");
    delay(2000);
    lcd.setCursor(0,1);
    lcd.print("           ");
    n=1;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Enter the qty:");
    
    scan_choice();
    
    Serial.println(x);
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Total Amount is:");
    lcd.setCursor(0,1);
    
    
    // use the formula for the price calculation here
    
    amount=10*(x-48);
    lcd.print(amount);
    lcd.print("Rs.");
    
    delay(3000);
    
    
    
    
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Thanks for shopping");
    lcd.setCursor(0,1);
    lcd.print("Please Visit Again");
    
    delay(3000);
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Welcome");
    
    
    
    
    
    
  }
  
  if(temp[11]=='6')
  {
    lcd.setCursor(0,1);
    lcd.print("MIKE");
    delay(2000);
    lcd.setCursor(0,1);
    lcd.print("    ");
    n=1;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Enter the qty:");
    
    scan_choice();
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Total Amount is:");
    lcd.setCursor(0,1);
    
    
    // use the formula for the price calculation here
    
    amount=10*(x-48);
    lcd.print(amount);
    lcd.print("Rs.");
    
    delay(3000);
    
    
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Thanks for shopping");
    lcd.setCursor(0,1);
    lcd.print("Please Visit Again");
    
    delay(3000);
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Welcome");
    
    
  }
  
  }
  
  if(sw==HIGH)
  {
    
    
      gsm_init();
      Serial.print("Refill Required at MRIU vending machine");
      sent();
      lcd.setCursor(0,1);
      lcd.print("SMS Sent.....");
      while(1);
      
    }
    
    }
    
    
    
    
    
    
    


