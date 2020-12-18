#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
int x;
int y;
int temp;
float v;
float v1;
float d = 1000.0;

float time;

//speed of the projectile will be calculated using distance formula....

/* distance = speed * time

  so   speed =  distance/time
 
 formula to calculate speed is   v  =  d/time 

 
*/

void setup()
{
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  Serial.begin(9600);
  lcd.begin(20, 4);
  
}

void loop()
{
  x=digitalRead(4);
  y=digitalRead(5);
  
  if(x==LOW && y==LOW)
  {
    
    lcd.setCursor(0,0);
    lcd.print("no projectile detected");
    Serial.println("no projectile detected");
    delay(10);
  }
  
  if(x==HIGH)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    y=digitalRead(5);
    while(y==LOW)
    {
      temp=temp+1;
      lcd.setCursor(0,0);
      lcd.print(temp);
      Serial.println(temp);
      delay(100);
      y=digitalRead(5);
    
  }
  
  lcd.setCursor(0,1);
  lcd.print("Out of loop");
  Serial.println("Out of loop");
  
  time = temp*0.1;
  
  v = d/time;
  
  v1=v*3.6;
  
  delay(300);
  
  
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("Time taken:");
  
  Serial.println("Time taken to cross is: ");
  lcd.print(time);
  
  Serial.print(time);
  
  lcd.setCursor(15,0);
  lcd.print("sec");
  Serial.print(" sec");
  
  lcd.setCursor(0,1);
  lcd.print("speed is:");
  Serial.println("Speed of the projectile crossed is:");
  lcd.print(v);
  Serial.print(v);
  lcd.setCursor(14,1);
  lcd.print("m/s");
  Serial.print(" m/s");
  
  lcd.setCursor(0,2);
  
  lcd.print("speed is:");
  Serial.println("Speed of the projectile crossed is:");
  lcd.print(v*3.6);
  Serial.print(v*3.6);
  
  lcd.setCursor(15,2);
  lcd.print("Km/hr");
  Serial.print(" Km/hr");
  
  delay(1000);
  
  if(v1>70.0)
  {
    lcd.setCursor(0,3);
    lcd.print("speed limit exceeded");
    Serial.println(".....Warning......");
    Serial.println("Speed Limit exceeded...");
    v1=0.0;
  }
  delay(10000);
  temp=0;
  
  
  
  
  
  
  
}

}
