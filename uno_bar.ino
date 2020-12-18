int m,b1,b2,b3,b4,b5,b6,b7,b8,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13,d14;
int t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14;
int z1,z2,z3,z4,z5,z6,z7,z8,z9,z10,z11,z12,z13,z14,z15,z16,z17,z18,z19,z20,z21,z22,z23,z24,z25,z26,z27,z28;
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
int op7=8;
int op8=9;
int op9=10;
int op10=11;
int op11=12;
int op12=13;
int op13=14;
int op14=15;


int red=16;
int yellow=17;

int var1=88;

int var21=86;

int var31=82;

int var41=88;

int var51=80;

int var61=93;

int var71=85;

int var81=83;

int var91=83;

int var10=84;

int var11=84;

int var12=83;

int var13=85;

int var14=86;

int a[][14]={
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0},      
                {2,3,4,5,6,7,8,9,10,11,12,13,14,15}       
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

void valve9_time()
{
    t9=var91*d9;
}

void valve10_time()
{
    t10=var10*d10;
}

void valve11_time()
{
    t11=var11*d11;
}

void valve12_time()
{
    t12=var12*d12;
}

void valve13_time()
{
    t13=var13*d13;
}

void valve14_time()
{
    t14=var14*d14;
}

void sort()
{
 int a[][14]={
                {t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14},      
                {2,3,4,5,6,7,8,9,10,11,12,13,14,15}       
                };
 
  
        int i, j, k,l, temp, temp1 ;

     for(j=1;j<14;j++)
     {
          for(i=0; i<13; i++)
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
 z9=a[0][8];
 z10=a[0][9];
 z11=a[0][10];
 z12=a[0][11];
 z13=a[0][12];
 z14=a[0][13];

 z15=a[1][0];
 z16=a[1][1];
 z17=a[1][2];
 z18=a[1][3];
 z19=a[1][4];
 z20=a[1][5];
 z21=a[1][6];
 z22=a[1][7];
 z23=a[1][8];
 z24=a[1][9];
 z25=a[1][10];
 z26=a[1][11];
 z27=a[1][12];
 z28=a[1][13];

}

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(14,OUTPUT);
  pinMode(15,OUTPUT);
  pinMode(16,OUTPUT);
  pinMode(17,OUTPUT);
 
  //mke all pins low initially
  
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  digitalWrite(14,LOW);
  digitalWrite(15,LOW);
  digitalWrite(16,LOW);
  digitalWrite(17,LOW);
  delay(1000);
}

void loop() 
{
  digitalWrite(red,HIGH);
  while(!Serial.available());
  if(Serial.available()>0)
  {
  Serial.readBytesUntil('\0',tp,100);

  for(m=0;m<56;m++)
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

  d9=(100*(temp[33]-48))+(10*(temp[34]-48))+(temp[35]-48);

  d10=(100*(temp[37]-48))+(10*(temp[38]-48))+(temp[39]-48);

  d11=(100*(temp[41]-48))+(10*(temp[42]-48))+(temp[43]-48);

  d12=(100*(temp[45]-48))+(10*(temp[46]-48))+(temp[47]-48);

  d13=(100*(temp[49]-48))+(10*(temp[50]-48))+(temp[51]-48);

  d14=(100*(temp[53]-48))+(10*(temp[54]-48))+(temp[55]-48);
  valve1_time();
  valve2_time();
  valve3_time();
  valve4_time();
  valve5_time();
  valve6_time();
  valve7_time();
  valve8_time();
  valve9_time();
  valve10_time();
  valve11_time();
  valve12_time();
  valve13_time();
  valve14_time();
  sort();
  digitalWrite(red,LOW);
  digitalWrite(yellow,HIGH);
  digitalWrite(z15,HIGH);
  digitalWrite(z16,HIGH);
  digitalWrite(z17,HIGH);
  digitalWrite(z18,HIGH);
  digitalWrite(z19,HIGH);
  digitalWrite(z20,HIGH);
  digitalWrite(z21,HIGH);
  digitalWrite(z22,HIGH);
  digitalWrite(z23,HIGH);
  digitalWrite(z24,HIGH);
  digitalWrite(z25,HIGH);
  digitalWrite(z26,HIGH);
  digitalWrite(z27,HIGH);
  digitalWrite(z28,HIGH);
  delay(z1);
  digitalWrite(z15,LOW);
  delay(z2-z1);
  digitalWrite(z16,LOW);
  delay(z3-z2);
  digitalWrite(z17,LOW);
  delay(z4-z3);
  digitalWrite(z18,LOW);
  delay(z5-z4);
  digitalWrite(z19,LOW);
  delay(z6-z5);
  digitalWrite(z20,LOW);
  delay(z7-z6);
  digitalWrite(z21,LOW);
  delay(z8-z7);
  digitalWrite(z22,LOW);
  delay(z9-z8);
  digitalWrite(z23,LOW);
  delay(z10-z9);
  digitalWrite(z24,LOW);
  delay(z11-z10);
  digitalWrite(z25,LOW);
  delay(z12-z11);
  digitalWrite(z26,LOW);
  delay(z13-z12);
  digitalWrite(z27,LOW);
  delay(z14-z13);
  digitalWrite(z28,LOW);
  delay(100);
  digitalWrite(yellow,LOW);
  z1=z2=z3=z4=z5=z6=z7=z8=z9=z10=z11=z12=z13=z14=0;
  d1=d2=d3=d4=d5=d6=d7=d8=d9=d10=d11=d12=d13=d14=0;
  Serial.flush();
  //delay(2000);
 // delay(500);
  for(m=0;m<56;m++)
  {
    temp[m]=0;
  }

}
 
}



