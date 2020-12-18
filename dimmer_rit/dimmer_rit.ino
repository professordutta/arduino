int n,m;
int z;
char temp,temp2;
char temp1[4];

void setPwmFrequency(int pin, int divisor) {
  byte mode;
  if(pin == 5 || pin == 6 || pin == 9 || pin == 10) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 64: mode = 0x03; break;
      case 256: mode = 0x04; break;
      case 1024: mode = 0x05; break;
      default: return;
    }
    if(pin == 5 || pin == 6) {
      TCCR0B = TCCR0B & 0b11111000 | mode;
    } else {
      TCCR1B = TCCR1B & 0b11111000 | mode;
    }
  } else if(pin == 3 || pin == 11) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 32: mode = 0x03; break;
      case 64: mode = 0x04; break;
      case 128: mode = 0x05; break;
      case 256: mode = 0x06; break;
      case 1024: mode = 0x07; break;
      default: return;
    }
    TCCR2B = TCCR2B & 0b11111000 | mode;
  }
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(6,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  setPwmFrequency(6,64);

  do
  {
    while(!Serial.available());
    if(Serial.available()>0)
    {
      temp=Serial.read();
    }
  }while(temp!='*');

  do
  {
    while(!Serial.available());
    if(Serial.available()>0)
    {
      temp1[m]=Serial.read();
      temp2=temp1[m];
      m=m+1;
    }
  }while(temp2!='#');

  //for(n=0;n<(m-1);n++)
  //{
    //Serial.print(temp1[n]);
  //}

  temp1[m]='\0';

  z=atoi(temp1);

  Serial.print(z);
  Serial.println("");
  analogWrite(6,z);

  n=0;
  m=0;

  
  

}
