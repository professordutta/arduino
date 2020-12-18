int temp[5];
int m;
char temp1;

char start;

int x;
int y;

int xprev;
int yprev;

int h=0;


void keyboard()
{
  do
  {
    while(!Serial1.available());
    start = Serial1.read();
    if(start!='~')
    {
    Keyboard.begin();
    Keyboard.print(start);
    Keyboard.end();
    }
  }while(start!='~');
}


void setup()
{
  Serial1.begin(9600);
  pinMode(13,OUTPUT);
}

void loop()
{
  do
  {
    while(!Serial1.available());
    start = Serial1.read();
    if(start == 'B')
  {
    digitalWrite(13,HIGH);
    Mouse.begin();
    Mouse.click(MOUSE_LEFT);
    Mouse.end();

  }
  
  if(start == '~')
  {
    keyboard();
  }
  
   if(start == 'R')
  {
    Mouse.begin();
    Mouse.click(MOUSE_RIGHT);
    Mouse.end();

  }
  
    if(start == 'C')
  {
   h=0; 
  }
  }while('A'!=start);
  
  
  
  
  do
  {
    while(!Serial1.available());
    temp[m] = Serial1.read();
    temp1 = temp[m];
    m = m+1;
  }while(','!= temp1);
  
  if (m == 3) // for 2 digit x
 {
   x = (10*(temp[0]-48)) + (temp[1]-48);
   m=0;
 } 
 
 if (m == 4) // for 3 digit x
{
  x = (100 * (temp[0]-48)) + (10 * (temp[1]-48)) + (temp[2]-48);
  m=0;
} 

if (m == 2) // for 1 digit x
{
  x = temp[0]-48;
  m = 0;
}

do
{
  while(!Serial1.available());
  temp[m] = Serial1.read();
  temp1 = temp[m];
  m = m+1;
}while('Z'!= temp1);

if (m == 3) // for 2 digit y
 {
   y = (10*(temp[0]-48)) + (temp[1]-48);
   m=0;
 } 
 
 if (m == 4) // for 3 digit y
{
  y = (100 * (temp[0]-48)) + (10 * (temp[1]-48)) + (temp[2]-48);
  m=0;
} 

if (m == 2) // for 1 digit y
{
  y = temp[0]-48;
  m = 0;
}

Mouse.begin();

if(h==0)
{
xprev=x;
yprev=y;
h=1; 
}

else
{
Mouse.move((x-xprev),(y-yprev));
xprev=x;
yprev=y;
}

Mouse.end();


}
