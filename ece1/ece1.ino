//my first experiment with ece students

/*lecture 1 learning

led blinking code

time:9:35 am ----11/01/2018
*/

void setup() 
{
  
pinMode(13,OUTPUT);
digitalWrite(13,LOW);

}

void loop() 
{

  digitalWrite(13,HIGH);
  delay(1000);
  digitalWrite(13,LOW);
  delay(1000);
  
}
