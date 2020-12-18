////////////////////////////Accelerometer////////////////////
const int a0 = A1;  // Analog input pin that the potentiometer is attached to
const int a1 = A2;
const int a2 = A3;

int x = 0;
int y = 0;
int z = 0;

////////////////////////////Buzzer & Vibrator////////////////
//const int buzzer=9;
//const int vibrator=10;
//const int buzzer=9;
const int vibrator=6;
const int led=7;
//const int led1=8;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
pinMode(a0,INPUT);
pinMode(a1,INPUT);
pinMode(a2,INPUT);
 //pinMode(buzzer,OUTPUT);

pinMode(led,OUTPUT);
pinMode(vibrator,OUTPUT);
 
 digitalWrite(led,LOW);
 }


void loop() {
  // read the analog in value:
 x= analogRead(A1);
 y=analogRead(A2);
 z=analogRead(A3);

/*  
  Serial.print("\n x = " );                       
  Serial.print(x);
  Serial.print("\t y = " );                       
  Serial.print(y);      
  Serial.print("\t z = " );                       
  Serial.print(z);   
  delay(500);
  */
  ///////////////////////////// STAND////////////////////////////////
if((x>=375)&&(x<=405)&&(z>=465)&&(z<=495))
    {
      digitalWrite(vibrator,LOW);
       Serial.println("b");
            delay(500);
   Serial.flush();

  //delay(10000); 
      }
///////////////////////////////bend fwd stand///////////////////////////////////  
else if((x>=408)&&(x<=430)&&(z>=405)&&(z<=430)){
  digitalWrite(vibrator,HIGH);
//digitalWrite(buzzer,HIGH);
  
  Serial.println("a");
         delay(500);
   Serial.flush();

  //delay(10000);
     // delay(2000);
}
//////////////////////////sit///////////////////////////////
/*else if((x>=445)&&(x<=470)&&(z>=456)&&(z<=474)){
  digitalWrite(vibrator,LOW);  
  Serial.println("x");
    
         delay(500);
   Serial.flush();

}*/
//////////////////////////bend fwd sit/////////////////////
else if((x>=440)&&(x<=500)&&(z>=410)&&(z<=440)){
digitalWrite(vibrator,HIGH);
//digitalWrite(buzzer,HIGH);  
  Serial.println("y");
         delay(500);
   Serial.flush();
}
else{
digitalWrite(vibrator,HIGH);
}
}
