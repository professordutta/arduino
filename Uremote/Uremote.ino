/*
 * IRremote: IRsendDemo - demonstrates sending IR codes with IRsend
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>
char cmd;
IRsend irsend;

void setup()
{
  Serial.begin(9600);
}

void loop() {
   if (Serial.available() >0) 
   {
      cmd = Serial.read();
      if(cmd == 'A')
      {
        irsend.sendPanasonic(0x4004,0x100BCBD);
        cmd = 0;
      }
      else if(cmd == 'B')
      {
        irsend.sendPanasonic(0x4004,0x1002C2D);
        cmd = 0;
      }
      else if(cmd == 'C')
      {
     irsend.sendPanasonic(0x4004,0x100ACAD);
     cmd = 0;
      }
      else if(cmd == 'D')
      {
   irsend.sendPanasonic(0x4004,0x1008485);
   cmd = 0;
      }
      else if(cmd == 'E')
      {
irsend.sendPanasonic(0x4004,0x1000405);
cmd = 0;
      }
      else if(cmd == 'F')
      {
irsend.sendPanasonic(0x4004,0x1004A4B);
cmd = 0;
      }
      else if(cmd == 'G')
      {
irsend.sendPanasonic(0x4004,0x1004C4D);
cmd = 0;
      }
    else if(cmd == 'H')
      {
        irsend.sendPanasonic(0x4004,0x1009C9D);
        cmd = 0;
      }
      else if(cmd == 'I')
      {irsend.sendPanasonic(0x4004,0x100A0A1);
        cmd = 0;
      }
      else if(cmd == 'J')
      {irsend.sendPanasonic(0x4004,0x1000809);
        cmd = 0;
      }
      else if(cmd == 'K')
      {irsend.sendPanasonic(0x4004,0x1008889);
        cmd = 0;
      }
      else if(cmd == 'L')
      {irsend.sendPanasonic(0x4004,0x1004849);
        cmd = 0;
      }
      else if(cmd == 'M')
      {irsend.sendPanasonic(0x4004,0x100C8C9);
        cmd = 0;
      }
      else if(cmd == 'N')
      {
irsend.sendPanasonic(0x4004,0x1002829);        cmd = 0;
      }
      else if(cmd == 'O')
      {irsend.sendPanasonic(0x4004,0x100A8A9);
        cmd = 0;
      }
      /*else if(cmd == 'P')
      {irsend.sendPanasonic(0x4004,0x1006869);
        cmd = 0;
      }
      else if(cmd == 'Q')
      {irsend.sendPanasonic(0x4004,0x100E8E9);
        cmd = 0;
      }
      else if(cmd == 'R')
      {irsend.sendPanasonic(0x4004,0x1001819);
        cmd = 0;
      }
      
      
      else if(cmd == 'S')
      {irsend.sendPanasonic(0x4004,0x1009899);
        cmd = 0;
      }
      
      else if(cmd == 'T')
      {irsend.sendPanasonic(0x4004,0x100ECED);
        cmd = 0;
      }
      
      else if(cmd == 'U')
      {irsend.sendPanasonic(0x4004,0x9004049);
        cmd = 0;
      }
      */
      else if(cmd == 'V')
      {irsend.sendPanasonic(0x4004,0x900C0C9);
        cmd = 0;
      }
      
      else if(cmd == 'W')
      {irsend.sendPanasonic(0x4004,0x9006069);
        cmd = 0;
      }
      
      else if(cmd == 'X')
      {irsend.sendPanasonic(0x4004,0x9000009);
        cmd = 0;
      }
      
      else if(cmd == 'Y')
      {irsend.sendPanasonic(0x4004,0x9001019);
        cmd = 0;
      }
      
      else if(cmd == 'Z')
      {irsend.sendPanasonic(0x4004,0x9006C65);
        cmd = 0;
      }
      
      else if(cmd == 'P')
      {irsend.sendPanasonic(0x4004,0x900ACA5);
        cmd = 0;
      }
      
      else if(cmd == 'Q')
      {irsend.sendPanasonic(0x4004,0x9002C25);
        cmd = 0;
      }
      
      else if(cmd == 'R')
      {irsend.sendPanasonic(0x4004,0x1405110);
        cmd = 0;
      }
      
      else if(cmd == 'S')
      {irsend.sendPanasonic(0x4004,0x1402362);
        cmd = 0;
      }
      
      else if(cmd == 'T')
      {irsend.sendPanasonic(0x4004,0x1406322);
        cmd = 0;
      }
      
      else if(cmd == 'U')
      {irsend.sendPanasonic(0x4004,0x140A3E2);
        cmd = 0;
      }
   }
}
