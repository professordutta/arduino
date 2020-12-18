char temp[50];
String x = "";
String y = "";
float mouseX;
float mouseY;
int m;
void setup()
{
  Serial1.begin(9600);
}


void loop()
{
  while(!Serial1.available());
  if(Serial1.available()>0)
  {
    temp[m] = Serial1.read();
    m= m+1;
    if(temp[m]=='A')
    {
      m=0;
      while(temp[m]!=',')
      {
        x+=temp[m];
        m++;
      }
      m++;
      while(temp[m]!='A')
      {
        y+=temp[m];
        m++;
      }
      m=0;
      
      char floatbuf[32]; // make this at least big enough for the whole string
      x.toCharArray(floatbuf, sizeof(floatbuf));
      mouseX = atof(floatbuf);
      
      y.toCharArray(floatbuf, sizeof(floatbuf));
      mouseY = atof(floatbuf);
 
 
     x="";
     y="";

    Mouse.begin();
    Mouse.move(mouseX,mouseY);
    Mouse.end();
    
    Serial1.println(mouseX);
    Serial1.println(mouseY);
      //Serial1.print(x.toFloat());
      
    }
    
  }
}
