#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
int m,b1,b2,b3,b4,b5,b6,b7,b8,d1,d2,d3,d4,d5,d6,d7,d8;
int t1,t2,t3,t4,t5,t6,t7,t8;
int z1,z2,z3,z4,z5,z6,z7,z8,z9,z10,z11,z12,z13,z14,z15,z16;
char temp[100];
char tp[100];
char temp1;

//first control pins
int op1=2;
int op2=3;
int op3=4;
int op4=5;
int op5=6;
int op6=7;
int op7=22;
int op8=23;

//second control pins

int sp1=24;
int sp2=25;
int sp3=26;
int sp4=27;
int sp5=28;
int sp6=29;


int red=30;
int green=31;
int yellow=50;

int var1=115;

int var21=115;


int var31=110;

int var41=116;

int var51=82;

int var61=82;

int var71=80;

int var81=86;

int a[][8]={
                {0,0,0,0,0,0,0,0},      
                {2,3,4,5,6,7,22,23}       
                };
 

void valve1_time()
{
    t1=var1*d1; 
}

void valve2_time()
{
    t2=var21*d2;
}

void valve3_time()
{
    t3=var31*d3;
}


void valve4_time()
{
  
    t4=var41*d4;
}
  

void valve5_time()
{  
    t5=var51*d5;
}

void valve6_time()
{
    t6=var61*d6;
}

void valve7_time()
{
    t7=var71*d7;
}
void valve8_time()
{
    t8=var81*d8;
}

void sort()
{
 int a[][8]={
                {t1,t2,t3,t4,t5,t6,t7,t8},      
                {2,3,4,5,6,7,22,23}       
                };
 
  
        int i, j, k,l, temp, temp1 ;



     for(j=1;j<8;j++)
     {
          for(i=0; i<7; i++)
          {
                if(a[0][i]>a[0][i+1])
                {
                    temp=a[0][i];
                    a[0][i]=a[0][i+1];
                    a[0][i+1]=temp;

                    temp1 = a[1][i];
                    a[1][i] = a[1][i+1];
                    a[1][i+1]=temp1;
                }
          }
     }
     
     
 z1=a[0][0];
 z2=a[0][1];
 z3=a[0][2];
 z4=a[0][3];
 z5=a[0][4];
 z6=a[0][5];
 z7=a[0][6];
 z8=a[0][7];
 
 z9=a[1][0];
 z10=a[1][1];
 z11=a[1][2];
 z12=a[1][3];
 z13=a[1][4];
 z14=a[1][5];
 z15=a[1][6];
 z16=a[1][7];
 
}

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  lcd.begin(20,4);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(22,OUTPUT);
  pinMode(23,OUTPUT);
  pinMode(24,OUTPUT);
  pinMode(25,OUTPUT);
  pinMode(26,OUTPUT);
  pinMode(27,OUTPUT);
  pinMode(28,OUTPUT);
  pinMode(29,OUTPUT);
  pinMode(30,OUTPUT);
  pinMode(31,OUTPUT);
  pinMode(50,OUTPUT);

  //mke all pins low initially
  
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(22,LOW);
  digitalWrite(23,LOW);
  digitalWrite(24,LOW);
  digitalWrite(25,LOW);
  digitalWrite(26,LOW);
  digitalWrite(27,LOW);
  digitalWrite(28,LOW);
  digitalWrite(29,LOW);
  digitalWrite(30,LOW);
  digitalWrite(31,LOW);
  digitalWrite(50,LOW);
  
  lcd.print("     Welcome to");
  lcd.setCursor(0,1);
  lcd.print("      Detox Bar");
  delay(3500);
}

void loop() 
{
  lcd.clear();
  lcd.setCursor(0,0);
  digitalWrite(red,HIGH);
  lcd.print("     Select Your");
  lcd.setCursor(0,1);
  lcd.print("        Drink    ");
  while(!Serial.available());
  if(Serial.available()>0)
  {
  Serial.readBytesUntil('\0',tp,100);

  for(m=0;m<32;m++)
  {
    temp[m]=tp[m+1];
  }

  d1=(100*(temp[1]-48))+(10*(temp[2]-48))+(temp[3]-48);

  d2=(100*(temp[5]-48))+(10*(temp[6]-48))+(temp[7]-48);

  d3=(100*(temp[9]-48))+(10*(temp[10]-48))+(temp[11]-48);

  d4=(100*(temp[13]-48))+(10*(temp[14]-48))+(temp[15]-48);

  d5=(100*(temp[17]-48))+(10*(temp[18]-48))+(temp[19]-48);

  d6=(100*(temp[21]-48))+(10*(temp[22]-48))+(temp[23]-48);

  d7=(100*(temp[25]-48))+(10*(temp[26]-48))+(temp[27]-48);

  d8=(100*(temp[29]-48))+(10*(temp[30]-48))+(temp[31]-48);

  
  valve1_time();
  valve2_time();
  valve3_time();
  valve4_time();
  valve5_time();
  valve6_time();
  valve7_time();
  valve8_time();

  sort();

  lcd.clear(); 
  lcd.setCursor(0,0);
  delay(100);
  digitalWrite(red,LOW);
  digitalWrite(yellow,HIGH);
  lcd.print("Please Wait...");
  lcd.setCursor(0,1);
  lcd.print("Dispensing.... ");

  digitalWrite(2,LOW);
  digitalWrite(24,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(25,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(26,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(27,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(28,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(29,HIGH);
  delay(2500);
  digitalWrite(24,LOW);
  digitalWrite(25,LOW);
  digitalWrite(26,LOW);
  digitalWrite(27,LOW);
  digitalWrite(28,LOW);
  digitalWrite(29,LOW);
  delay(1000);

  digitalWrite(z9,HIGH);
  digitalWrite(z10,HIGH);
  digitalWrite(z11,HIGH);
  digitalWrite(z12,HIGH);
  digitalWrite(z13,HIGH);
  digitalWrite(z14,HIGH);
  digitalWrite(z15,HIGH);
  digitalWrite(z16,HIGH);
  delay(z1);
  digitalWrite(z9,LOW);
  delay(z2-z1);
  digitalWrite(z10,LOW);
  delay(z3-z2);
  digitalWrite(z11,LOW);
  delay(z4-z3);
  digitalWrite(z12,LOW);
  delay(z5-z4);
  digitalWrite(z13,LOW);
  delay(z6-z5);
  digitalWrite(z14,LOW);
  delay(z7-z6);
  digitalWrite(z15,LOW);
  delay(z8-z7);
  digitalWrite(z16,LOW);
  delay(1500);
  lcd.begin(20,4);
  delay(100);
  lcd.clear();
  lcd.setCursor(0,0);
  digitalWrite(yellow,LOW);
  digitalWrite(green,HIGH);
  lcd.print("  Your drink is");
  lcd.setCursor(0,1);
  lcd.print("       ready!");
  z1=z2=z3=z4=z5=z6=z7=z8=0;
  d1=d2=d3=d4=d5=d6=d7=d8=0;
  Serial.flush();
  delay(1500);
  lcd.clear();
  delay(500);
  lcd.begin(16,2);
  for(m=0;m<32;m++)
  {
    temp[m]=0;
  }
  digitalWrite(green,LOW);

}
 
}



