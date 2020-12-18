int op1=4;
int op2=5;
int op3=6;
int op4=7;
char temp;

void setup()
{
  Serial.begin(9600);
  pinMode(op1,OUTPUT);
  pinMode(op2,OUTPUT);
  pinMode(op3,OUTPUT);
  pinMode(op4,OUTPUT);
  
  
}


void loop()
{
 
  while(!Serial.available());
    temp=Serial.read();
    if(temp=='1') //forward
    {
     
     digitalWrite(op1,HIGH);
     digitalWrite(op2,LOW);
     digitalWrite(op3,HIGH);
     digitalWrite(op4,LOW);
   
    }
    
    if(temp=='3') //stop
    {
     digitalWrite(op1,LOW);
     digitalWrite(op2,LOW);
     digitalWrite(op3,LOW);
     digitalWrite(op4,LOW);
    }
    
    if(temp=='5') //backward
    {
     digitalWrite(op1,LOW);
     digitalWrite(op2,HIGH);
     digitalWrite(op3,LOW);
     digitalWrite(op4,HIGH);
    }
    
    if(temp=='2') //left
    {
     digitalWrite(op1,HIGH);
     digitalWrite(op2,LOW);
     digitalWrite(op3,LOW);
     digitalWrite(op4,LOW);
    }
    
    if(temp=='4') //right
    {
     digitalWrite(op1,LOW);
     digitalWrite(op2,LOW);
     digitalWrite(op3,HIGH);
     digitalWrite(op4,LOW);
    }
    
    if(temp=='6') //stop
    {
     digitalWrite(op1,LOW);
     digitalWrite(op2,LOW);
     digitalWrite(op3,LOW);
     digitalWrite(op4,LOW);
    }
  }

