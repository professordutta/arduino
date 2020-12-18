

void setup()
{
  Serial.begin(9600);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  
}


void loop()
{
  //if(digitalRead(3)==LOW)
  //{
    Serial.println("A");
    delay(1000);
  //}
  
  
 // if(digitalRead(4)==LOW)
 //   Serial.println("B");
   // delay(500);
  //}
  
  
  
  
}
