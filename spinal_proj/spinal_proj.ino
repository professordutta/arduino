int x;
int m;
char largest,temp,dat,marks_var;
unsigned long timemsec;
unsigned long timesec;

int buzzer=11;

int gp,pb,mb,eb;

char findstatus()
{
  
  largest=gp;
  
  if (largest<pb)
  {
    largest=pb;
  }
  
  if (largest<mb)
  {
    largest=mb;
  }
  
  if (largest<eb)
  {
    largest=eb;
  }
  
  if(largest==gp)
  {
    marks_var='A';
  }
  
  if(largest==pb)
  {
    marks_var='B';
  }
  
  if(largest==mb)
  {
    marks_var='C';
  }
  
  if(largest==eb)
  {
    marks_var='D';
  }
  
  gp=pb=mb=eb=0;//clear the variables
  
  return marks_var;
}



void setup()
{
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  digitalWrite(buzzer,LOW);
  
}


void loop()
{
 
  if (m==0)
  {
    while(!Serial.available());
    temp = Serial.read();
    if(temp=='A')
    {
      m=1;
      timemsec=millis(); //stores time in msec
      timesec =timemsec/1000;// stores time in seconds
    }
  
    if(temp=='E')
    {
      m=2;
    }
  }
  
  
    if(m==1)
    {
      x=analogRead(A0);
    
    if(x>=340 && x<=352)
    {
      //Condition for good posture 
      //gp is variable for good posture
      
      gp=gp+1;
      delay(200);
      
    }
    
    
    if(x>=330 && x<=340)
    {
      //Condition for parial bend of L3
     //pb is variable for partial bend
    
      pb=pb+1;
      delay(200); 
    }
    
    if(x>=320 && x<=330)
    {
      //Condition for medium bend of L3
      //mb is variable for medium bend
      
      mb=mb+1;
      delay(200);
    }
    
    if(x>=310 && x<=320)
    {
      //Condition for extreme bend of L3
      //eb is variable for extreme bend
      eb=eb+1;
      delay(200);
      
      
    }
     timemsec=millis(); //stores time in msec
     timesec =timemsec/1000;
    
    
    if(timesec%20==0)
    {
      //send report online after every 5 seconds
      //check the trend of posture and take decision on the marks
      
      dat=findstatus();
      
      if (dat=='A') //good posture
      {
        Serial.println('A');
        delay(200);
        
      }
      if (dat=='B') //partial bend
      {
        Serial.println('B');
        digitalWrite(buzzer,HIGH);
        delay(200);
        digitalWrite(buzzer,LOW);
        delay(800);
      }
      
      if (dat=='C') //medium bend
      {
        Serial.println('C');
        digitalWrite(buzzer,HIGH);
        delay(500);
        digitalWrite(buzzer,LOW);
        delay(500);
      }
      
      if (dat=='D') //extreme bend
      {
        Serial.println('D');
        digitalWrite(buzzer,HIGH);
        delay(1000);
        digitalWrite(buzzer,LOW);
        delay(1000);
      }
    }
  
  }
  
    if(m==2) //measurement stops here
    {
      // clear all the variables to 0
      
       gp=pb=mb=eb=0;//clear the variables
       m=0; // reset variable m to 0
       
       temp=0;
       
       
    
    }
 
 
}
