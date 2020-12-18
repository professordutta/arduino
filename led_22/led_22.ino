double _ABVAR_1_temp = 0.0 ;

void setup()
{
  Serial.begin(9600);
  pinMode( 13 , OUTPUT);
  _ABVAR_1_temp = 1.0 ;

}

void loop()
{
  _ABVAR_1_temp = Serial.parseInt() ;
  if (( ( _ABVAR_1_temp ) == ( 1.0 ) ))
  {
    digitalWrite( 13 , HIGH );
  }
  if (( ( _ABVAR_1_temp ) == ( 2.0 ) ))
  {
    digitalWrite( 13 , LOW );
  }
}


