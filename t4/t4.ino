int temp;
void setup ()
{
  Serial.begin(9600);
}
void loop ()
{
  temp=analogRead(A0);
  temp=temp*(5);
  temp=temp/10;
  Serial.println(temp);
  delay(1000);
  // record the maximum sensor value
    if (temp > 35){
      Serial.println("fire");
    }

    // record the minimum sensor value
    else
    {
    Serial.println("safe");
  }
}

