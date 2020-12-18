int out1=2;
int out2=3;
int out3=4;
int out4=5;
int left=6; //left sensor
int centre=7;// middle sensor
int right=8;//right sensor

void setup()
{
  pinMode(left,INPUT);
  pinMode(centre,INPUT);
  pinMode(right,INPUT);
  pinMode(out1,OUTPUT);
  pinMode(out2,OUTPUT);
  pinMode(out3,OUTPUT);
  pinMode(out4,OUTPUT);
  digitalWrite(out1,LOW);
  digitalWrite(out2,LOW);
  digitalWrite(out3,LOW);
  digitalWrite(out4,LOW);
  

}


void loop()
{
  
  
  //condition for forward motion
  
  if(digitalRead(left)==HIGH && digitalRead(centre)==LOW && digitalRead(right)==HIGH)
  {
    //out1 and out2 are connected to motor M1 (left motor), out3 and out4 connected to M2 (right motor)
    digitalWrite(out1,HIGH);
    digitalWrite(out2,LOW);
    digitalWrite(out3,HIGH);
    digitalWrite(out4,LOW); 
  }
  
  
  //right turn
  if(digitalRead(left)==HIGH && digitalRead(centre)==LOW && digitalRead(right)==LOW)
  {
    //out1 and out2 are connected to motor M1 (left motor), out3 and out4 connected to M2 (right motor)
    digitalWrite(out1,HIGH);
    digitalWrite(out2,LOW);
    digitalWrite(out3,LOW);
    digitalWrite(out4,LOW); 
  }
  
  
  //left turn
  
  if(digitalRead(left)==LOW && digitalRead(centre)==LOW && digitalRead(right)==HIGH)
  {
    //out1 and out2 are connected to motor M1 (left motor), out3 and out4 connected to M2 (right motor)
    digitalWrite(out1,LOW);
    digitalWrite(out2,LOW);
    digitalWrite(out3,HIGH);
    digitalWrite(out4,LOW); 
  }
  
  //left low and right low so not sure and so left
  
  if(digitalRead(left)==LOW && digitalRead(centre)==HIGH && digitalRead(right)==LOW)
  {
    //out1 and out2 are connected to motor M1 (left motor), out3 and out4 connected to M2 (right motor)
    digitalWrite(out1,HIGH);
    digitalWrite(out2,LOW);
    digitalWrite(out3,LOW);
    digitalWrite(out4,LOW); 
  }
  
  
  
  //path is in the left so turn left
  if(digitalRead(left)==LOW && digitalRead(centre)==HIGH && digitalRead(right)==HIGH)
  {
    //out1 and out2 are connected to motor M1 (left motor), out3 and out4 connected to M2 (right motor)
    digitalWrite(out1,LOW);
    digitalWrite(out2,LOW);
    digitalWrite(out3,HIGH);
    digitalWrite(out4,LOW); 
  }
  
  
  
  //path is in the right so turn right
  if(digitalRead(left)==HIGH && digitalRead(centre)==HIGH && digitalRead(right)==LOW)
  {
    //out1 and out2 are connected to motor M1 (left motor), out3 and out4 connected to M2 (right motor)
    digitalWrite(out1,HIGH);
    digitalWrite(out2,LOW);
    digitalWrite(out3,LOW);
    digitalWrite(out4,LOW); 
  }
  
  // turn left default when there is no path
  if(digitalRead(left)==HIGH && digitalRead(centre)==HIGH && digitalRead(right)==HIGH)
  {
    //out1 and out2 are connected to motor M1 (left motor), out3 and out4 connected to M2 (right motor)
    digitalWrite(out1,HIGH);
    digitalWrite(out2,LOW);
    digitalWrite(out3,LOW);
    digitalWrite(out4,LOW); 
  }
  
  //again left be careful path everywhere condition
  
  if(digitalRead(left)==LOW && digitalRead(centre)==LOW && digitalRead(right)==LOW)
  {
    //out1 and out2 are connected to motor M1 (left motor), out3 and out4 connected to M2 (right motor)
    digitalWrite(out1,HIGH);
    digitalWrite(out2,LOW);
    digitalWrite(out3,LOW);
    digitalWrite(out4,LOW); 
  }
  
  
}
