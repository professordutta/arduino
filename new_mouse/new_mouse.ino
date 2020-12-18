int m ;
int flag1;
int flag2;
int x;
int y;
int temp[10];
char temp1;
int n;
void setup()
{
  Serial1.begin(9600);
}

void loop()
{
   do
    {
        while ( !Serial1.available() );    
    } while ( 'A' != Serial1.read() );
      
      do
    {
        while ( !Serial1.available() );
        temp[m] = Serial1.read();
        temp1 = temp[m];
        m = m+1;    
    } while ( ',' != temp1 );
    
    if(m==3) // indicating 2 digit value of x coordinate of pixel
    {
      flag1=1;
      Serial1.println("x is 2 digit");
      m=m-1;
      n=1;
    }
    
    if(m==4) // indicating 3 digit value of x coordinate of pixel
    {
      flag1=2;
      Serial1.println("x is 3 digit");
      m=m-1;
      temp[3] = 0;
      n=2;
    }
    
   
     do
    {
        while ( !Serial1.available() );
        temp[m] = Serial1.read();
        temp1 = temp[m];
        m = m+1;    
    } while ( 'Z' != temp1 );
    
    
     
    
    if(m==5 && n==1) // indicating 2 digit value of y coordinte of pixel
    {
      flag2 =1;
      Serial1.println("y is 2 digit");
      m=0; //for next cycle
    }
    
    if(m==6 && n==2) // indicating 3 digit value of y coordinate of pixel
    {
      flag2 = 1;
      m=0;
    }
    
    if(m==7)
    {
      Serial1.println("y is 3 digit");
      flag2=2;
    }
    
    if(m==7 && n==1)
    {
      Serial1.println("y is 3 digit");
      flag2=2;
    }
    
    
    if(flag1==1 && flag2==1) // both x and y are 2 digit numbers
    {
      /*
        x is stored in temp[0] and temp[1]
        y is stored in temp[2] and temp[3]
         x = 10*temp[0]+temp[1]
         y = 10*temp[2]+temp[3]
      */
      
      Serial1.println("I am in loop 1");
      x = (10*(temp[0]-48))+(temp[1]-48);
      y = (10*(temp[2]-48))+(temp[3]-48);
      Serial1.println(x);
      Serial1.println(y);
    }
    
    if(flag1==2 && flag2==1) // x is a 3 digit number while y is a 2 digit number
    {
      
      Serial1.println("I am in loop 2");
      
      /*
        x is stored in temp[0] , temp[1] and tem[2]
        y is stored in temp[3] and temp[4]
         x = (100*temp[0])+(10*temp[1])+temp[2]
         y = 10*temp[3]+temp[4]
      */
      x = (100*(temp[0]-48))+(10*(temp[1]-48))+(temp[2]-48);
      y = (10*(temp[3]-48))+(temp[4]-48);
      Serial1.println(x);
      Serial1.println(y);
      
    }
    
    if(flag1==1 && flag2==2) // x is a 2 digit number while y is a 3 digit number 
    {
      Serial1.println("I am in loop 3");
         /*
        x is stored in temp[0] and temp[1]
        y is stored in temp[2] , temp[3] and temp[4]
         x = 10*temp[0]+temp[1]
         y = (100*temp[2])+(10*temp[3])+temp[4]
      */
      x = (10*(temp[0]-48))+(temp[1]-48);
      y = (100*(temp[2]-48))+(10*(temp[3]-48))+(temp[4]-48);
      Serial1.println(x);
      Serial1.println(y);
      
    }
    
    if(flag1==2 && flag2==2) // both x and y are 3 digit numbers
    {
      Serial1.println("I am in loop 4");
      /*
        x is stored in temp[0], temp[1], temp[2]
        y is stored in temp[3] , temp[4] and temp[5]
         x = (100*temp[0])+(10*temp[1])+temp[2]
         y = (100*temp[3])+(10*temp[4])+temp[5]
      */
      
       
      
      x = (100*(temp[0]-48)) + (10*(temp[1]-48)) +(temp[2]-48);
      y = (100*(temp[3]-48))+(10*(temp[4]-48))+(temp[5]-48);
      Serial1.println(x);
      Serial1.println(y);
      
    }
    
    for(m = 0;m<10;m++)
    {
      temp[m] = 0;
    }
    m=0;
    
      
  
   
  
}
