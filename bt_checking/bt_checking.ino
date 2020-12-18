int m;
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  

}

void loop() {
  // put your main code here, to run repeatedly:

for(m=0;m<200;m++)
{
  Serial.print('*');
  Serial.print(m);
  Serial.print('#');
  Serial.println("");
  delay(1000);
}

}
