int temp[10];
int m;

void setup()
{
  Serial1.begin(9600);
}

void loop()
{
  for(m=0;m<3;m++)
  {
  while(!Serial1.available());
  
  if(Serial1.available()>0)
  {
    temp[m] = Serial1.read();
    Mouse.begin();
    
  }
  }
  
  for(m=0;m<3;m++)
  {
  Serial1.print(temp[m]);
  }
  m=0;
  while(1);
  
}
