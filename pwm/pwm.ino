int led=9;
int count=50;
 
void setup() {
  // put your setup code here, to run once:
  
pinMode(led,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

analogWrite(led,count);
}
