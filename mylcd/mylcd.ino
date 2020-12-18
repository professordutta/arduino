
int rs = 8;
int en = 9;
int del = 10;
int inc = 11;

void lcd_cmd(unsigned char value)
{
  PORTD = value;
  digitalWrite(rs,LOW);
  digitalWrite(en,HIGH);
  delay(2);
  digitalWrite(en,LOW);
}

void lcd_dat(unsigned char value)
{
  PORTD = value;
  digitalWrite(rs,HIGH);
  digitalWrite(en,HIGH);
  delay(2);
  digitalWrite(en,LOW);
}


void cmd(unsigned char value)
{
  unsigned char value1;
  value1 = value & 0xF0;
  lcd_cmd(value1);
  delay(1);
  value1 = value<<4;
  value1= value1 & 0xF0;
  lcd_cmd(value1);
  
}


void dat(unsigned char value)
{
  unsigned char value1;
  value1 = value & 0xF0;
  lcd_dat(value1);
  delay(1);
  value1 = value<<4;
  value1 = value1 & 0xF0;
  lcd_dat(value1);
}




void lcd_init()
{
  cmd(0x02);
  delay(2);
  cmd(0x28);
  delay(2);
  cmd(0x0E);
  cmd(0x01);
  cmd(0x06);
  cmd(0x80);
}

void str(char *disp)
{
  int x;
  while(disp[x]!='\0')
  {
    dat(disp[x]);
    x = x+1;
  }
  x=0;
}

void setup()
{
  pinMode(rs,OUTPUT);
  pinMode(en,OUTPUT);
  pinMode(del,INPUT);
  pinMode(inc,INPUT);
  digitalWrite(inc,HIGH);
  digitalWrite(del,HIGH); // default high status
  DDRD = 0xF0;
  lcd_init();
  str("UMESH DUTTA");
}


void loop()
{
  
  if(digitalRead(del) == LOW)
  {
    cmd(0x10);
    dat(' ');
    cmd(0x10);
    delay(200);
  }
  
  if(digitalRead(inc) == LOW)
  {
    cmd(0x14);
    delay(200);
  }
  
  
 
}
