#include <string.h>
#include <SoftwareSerial.h>

SoftwareSerial blSerial (8, 9);

void xyvalue(char *input);
void get_val();

char xvalue[6],yvalue[6];
char check,readstring[25];
char button_stat;
int xval =0, yval =0;
void setup() 
{
  Serial.begin(9600);
  pinMode(12,INPUT);
  pinMode(13,OUTPUT);
  
  //blSerial.begin(9600);
  Serial1.begin(9600);
  Mouse.begin();
  Keyboard.begin();
}

void loop() 
{
  if(Serial1.available() > 0)
  {
    get_val();
   if((xval > (-2)) && (xval < 2))
   {
     xval = 0;
   }
   if((yval > (-2)) && (yval < 2))
   {
     yval = 0;
   }
  Mouse.move(-xval,-yval);
  if(button_stat == 'l')
  {
    Mouse.click(MOUSE_LEFT);
    delay(2000);
  }
  else if(button_stat == 'r')
  {
    Mouse.click(MOUSE_RIGHT);
    delay(2000);
  } 
 }
  if(digitalRead(12) == HIGH)
  {
    Mouse.end();
  }
  

}


void xyvalue(char *input)
{
  int i,j,k;

  for(i=0;input[i]!=',';i++)
  {
    xvalue[i] = input[i]; 
  }
  xvalue[i] = '\0';
  xval = atoi(xvalue);
  for(j=0,i=i+1;input[i]!='@';j++,i++)
  {
    yvalue[j] = input[i];
  }
  yvalue[j] = '\0';
  yval = atoi(yvalue);
  button_stat = input[i+1];
}

void get_val()
{
    while((check = Serial1.read()) != '*');
    Serial1.readBytesUntil('#',readstring,25);
    
    xyvalue(readstring);
    delay(1);
        
}

