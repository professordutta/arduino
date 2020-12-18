int r1=2;
int r2=3;
int r3=4;
int r4=5;

int c1=6;
int c2=7;
int c3=8;
int c4=9;

int n=200;

int m=0;
int k=0;
int sw1;
int x,y;
char temp[10];
int inByte;



char pos[45];


void check_col1()
{
  digitalWrite(r1,LOW);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,HIGH);
  if(digitalRead(c1)==LOW)
  {
   Serial.print('1');
   temp[m]='1';
   delay(n);
   digitalWrite(r1,HIGH); 
  }
  
  digitalWrite(r2,LOW);
  if(digitalRead(c1)==LOW)
  {
   Serial.print('4');
   temp[m]='4';
   delay(n);
   digitalWrite(r2,HIGH); 
  }
  
  
  digitalWrite(r3,LOW);
  if(digitalRead(c1)==LOW)
  {
   Serial.print('7');
   temp[m]='7';
   delay(n);
   digitalWrite(r3,HIGH); 
  }
  
  
  digitalWrite(r4,LOW);
  if(digitalRead(c1)==LOW)
  {
   Serial.print('*');
   temp[m]='*';
   delay(n);
   digitalWrite(r4,HIGH); 
  }
  
}




void check_col2()
{
  
  digitalWrite(r1,LOW);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,HIGH);
  if(digitalRead(c2)==LOW)
  {
   Serial.print('2');
   temp[m]='2';
   delay(n);
   digitalWrite(r1,HIGH); 
  }
  
  digitalWrite(r2,LOW);
  if(digitalRead(c2)==LOW)
  {
   Serial.print('5');
   temp[m]='5';
   delay(n);
   digitalWrite(r2,HIGH); 
  }
  
  
  digitalWrite(r3,LOW);
  if(digitalRead(c2)==LOW)
  {
   Serial.print('8');
   temp[m]='8';
   delay(n);
   digitalWrite(r3,HIGH); 
  }
  
  
  digitalWrite(r4,LOW);
  if(digitalRead(c2)==LOW)
  {
   Serial.print('0');
   temp[m]='0';
   delay(n);
   digitalWrite(r4,HIGH); 
  }
  
}



void check_col3()
{
  digitalWrite(r1,LOW);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,HIGH);
  if(digitalRead(c3)==LOW)
  {
   Serial.print('3');
   temp[m]='3';
   delay(n);
   digitalWrite(r1,HIGH); 
  }
  
  digitalWrite(r2,LOW);
  if(digitalRead(c3)==LOW)
  {
   Serial.print('6');
   temp[m]='6';
   delay(n);
   digitalWrite(r2,HIGH); 
  }
  
  
  digitalWrite(r3,LOW);
  if(digitalRead(c3)==LOW)
  {
   Serial.print('9');
   temp[m]='9';
   delay(n);
   digitalWrite(r3,HIGH); 
  }
  
  
  digitalWrite(r4,LOW);
  if(digitalRead(c3)==LOW)
  {
   Serial.print('#');
   temp[m]='#';
   delay(n);
   digitalWrite(r4,HIGH); 
  }
  
}




void check_col4()
{
  digitalWrite(r1,LOW);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,HIGH);
  if(digitalRead(c4)==LOW)
  {
   Serial.print('A');
   temp[m]='A';
   delay(n);
   digitalWrite(r1,HIGH); 
  }
  
  digitalWrite(r2,LOW);
  if(digitalRead(c4)==LOW)
  {
   Serial.print('B');
   temp[m]='B';
   delay(n);
   digitalWrite(r2,HIGH); 
  }
  
  
  digitalWrite(r3,LOW);
  if(digitalRead(c4)==LOW)
  {
   Serial.print('C');
   temp[m]='C';
   delay(n);
   digitalWrite(r3,HIGH); 
  }
  
  
  digitalWrite(r4,LOW);
  if(digitalRead(c4)==LOW)
  {
   Serial.print('D');
   temp[m]='D';
   delay(n);
   digitalWrite(r4,HIGH); 
  }
  
}


void setup()
{
  pinMode(c1,INPUT);
  pinMode(c2,INPUT);
  pinMode(c3,INPUT);
  pinMode(c4,INPUT);
  pinMode(r1,OUTPUT);
  pinMode(r2,OUTPUT);
  pinMode(r3,OUTPUT);
  pinMode(r4,OUTPUT);
  
  pinMode(10,INPUT);
  digitalWrite(10,HIGH);
  
  pinMode(11,OUTPUT);
  digitalWrite(11,LOW);
  
  
  Serial.begin(9600);
  
  
  temp[0]='9';
  temp[1]='8';
  temp[2]='7';
  temp[3]='3';
  temp[4]='8';
  temp[5]='0';
  temp[6]='4';
  temp[7]='9';
  temp[8]='3';
  temp[9]='7';

  
  Serial.print("AT+CMGF=1\r");
  delay(500);
  Serial.print("AT+CNMI=2,2,0,0,0\r");
  delay(2000);
  
  
  
  
  
}


void loop()
{
  
  digitalWrite(r1,LOW);
  digitalWrite(r2,LOW);
  digitalWrite(r3,LOW);
  digitalWrite(r4,LOW);
  
  digitalWrite(c1,HIGH);
  digitalWrite(c2,HIGH);
  digitalWrite(c3,HIGH);
  digitalWrite(c4,HIGH);
  
  sw1=digitalRead(10);
  
  if(sw1==HIGH)
  {
   Serial.println("code for receiving sms"); 
   delay(1000);
   
  k=0;
  for(k=0;k<45;k++)
  {   
   pos[k]=0;
  }
  
  do
    {
        while ( !Serial.available() );    
    } while ( '"' != Serial.read() );
  
  for(k=0;k<44;k++)
      {
        while ( !Serial.available() ); 
        inByte = Serial.read();
        pos[k]=inByte;
        
      }
  
  Serial.println("check");
  
  if(pos[0]=='+' && pos[1]=='9' && pos[2]=='1' && pos[3]==temp[0] && pos[4]==temp[1] && pos[5]==temp[2] && pos[6]==temp[3] && pos[7]==temp[4] && pos[8]==temp[5] && pos[9]==temp[6] && pos[10]==temp[7] && pos[11]==temp[8] && pos[12]==temp[9])
      {
        
        digitalWrite(11,HIGH);
        y=(10*(temp[42]-48))+(temp[43]-48);
        
       
        Serial.println(y);
        for(x=0;x<y;x++)
        {
        delay(30000);
        delay(30000);
        }
        
        digitalWrite(11,LOW);
        
   
  }
  
  }
  
  
  
  if(sw1==LOW)
  {
  
  Serial.println("Number change request");
  
  Serial.println("Enter the new number:");
  
  
  for(m=0;m<10;m++)
  {
  digitalWrite(r1,LOW);
  digitalWrite(r2,LOW);
  digitalWrite(r3,LOW);
  digitalWrite(r4,LOW);
  
  digitalWrite(c1,HIGH);
  digitalWrite(c2,HIGH);
  digitalWrite(c3,HIGH);
  digitalWrite(c4,HIGH);
  
  
  
  while(digitalRead(c1)==HIGH && digitalRead(c2)==HIGH && digitalRead(c3)==HIGH && digitalRead(c4)==HIGH); 
  
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
  
  if(digitalRead(c4)==LOW)
  {
    check_col4();
  }
  delay(200);
}

Serial.println("number changed");

while(digitalRead(10)==LOW);


}
}
