int temp[5];
int m;
char temp1;

char start;

char mclick;
int x;
int y;

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
    Mouse.press(MOUSE_LEFT);
    Mouse.release();
    Mouse.end();

  }
  }while('A'!=start);
  
  
  
  //while('A'!=Serial1.read());
  
  //while('A'!=start || 'B'!=start);
  
//  if (start == 'A')
//  {
  //  Mouse.release();
  
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


//movement of mouse

if(x>150)  // move mouse right
  {    
    Mouse.move((x-150),0);
  }
  if(x<130)   // move mouse left
  {
    Mouse.move(-(130-x),0);
  }
   if(y>150)  // move mouse up
   {
     Mouse.move(0,((y-150)/2));    
   }
   
   if(y<130)  // move mouse right
   {
        Mouse.move(0,-((130-y)/2));
   }

Mouse.end();

//}


/*
  if ( start == 'B')
{
  
  while(!Serial1.available());
  if(Serial1.available()>0)
  {
    mclick  = Serial1.read();
    if(mclick == 'L')
    {
      Mouse.press(MOUSE_LEFT);
      Mouse.release();

    }
    
    if(mclick == 'R')
    {
      Mouse.press(MOUSE_RIGHT);
      
    }
  }
  
}

*/

}
