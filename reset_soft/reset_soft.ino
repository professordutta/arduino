void setup() {
  // put your setup code here, to run once:

}
void(* resetFunc) (void) = 0;//declare reset function at address 0

void loop() {
  // put your main code here, to run repeatedly:
 resetFunc(); //call reset
}
