#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
  #include "SoftwareSerial.h"
  SoftwareSerial port(12,13);
#else // Arduino 0022 - use modified NewSoftSerial
  #include "WProgram.h"
  #include "NewSoftSerial.h"
  NewSoftSerial port(12,13);
#endif

#include "EasyVR.h"
EasyVR easyvr(port);

//Groups and Commands
enum Groups
{
  GROUP_0  = 0,
  GROUP_2  = 2,
};

enum Group0 
{
  G0_ARDUINO = 0,
};

enum Group2 
{
  G2_ONE = 0,
  G2_TWO = 1,
  G2_THREE = 2,
  G2_FOUR = 3,
  G2_FIVE = 4,
  G2_SIX = 5,
  G2_SEVEN = 6,
  G2_EIGHT = 7,
  G2_START = 8,
  G2_STOP = 9,
};


EasyVRBridge bridge;

int8_t group, idx;

void setup()
{
  // bridge mode?
  if (bridge.check())
  {
    cli();
    bridge.loop(0, 1, 12, 13);
  }
  // run normally
  Serial.begin(9600);
  port.begin(9600);

  if (!easyvr.detect())
  {
    Serial.println("EasyVR not detected!");
    for (;;);
  }

  easyvr.setPinOutput(EasyVR::IO1, LOW);
  Serial.println("EasyVR detected!");
  easyvr.setTimeout(5);
  easyvr.setLanguage(0);

  group = EasyVR::TRIGGER; //<-- start group (customize)
}

void action();

void loop()
{
  easyvr.setPinOutput(EasyVR::IO1, HIGH); // LED on (listening)

  Serial.print("Say a command in Group ");
  Serial.println(group);
  easyvr.recognizeCommand(group);

  do
  {
    // can do some processing while waiting for a spoken command
  }
  while (!easyvr.hasFinished());
  
  easyvr.setPinOutput(EasyVR::IO1, LOW); // LED off

  idx = easyvr.getWord();
  if (idx >= 0)
  {
    // built-in trigger (ROBOT)
    // group = GROUP_X; <-- jump to another group X
    return;
  }
  idx = easyvr.getCommand();
  if (idx >= 0)
  {
    // print debug message
    uint8_t train = 0;
    char name[32];
    Serial.print("Command: ");
    Serial.print(idx);
    if (easyvr.dumpCommand(group, idx, name, train))
    {
      Serial.print(" = ");
      Serial.println(name);
    }
    else
      Serial.println();
    easyvr.playSound(0, EasyVR::VOL_FULL);
    // perform some action
    action();
  }
  else // errors or timeout
  {
    if (easyvr.isTimeout())
      Serial.println("Timed out, try again...");
    int16_t err = easyvr.getError();
    if (err >= 0)
    {
      Serial.print("Error ");
      Serial.println(err, HEX);
    }
  }
}

void action()
{
    switch (group)
    {
    case GROUP_0:
      switch (idx)
      {
      case G0_ARDUINO:
        // write your action code here
        // group = GROUP_X; <-- or jump to another group X for composite commands
        break;
      }
      break;
    case GROUP_2:
      switch (idx)
      {
      case G2_ONE:
        // write your action code here
        // group = GROUP_X; <-- or jump to another group X for composite commands
        break;
      case G2_TWO:
        // write your action code here
        // group = GROUP_X; <-- or jump to another group X for composite commands
        break;
      case G2_THREE:
        // write your action code here
        // group = GROUP_X; <-- or jump to another group X for composite commands
        break;
      case G2_FOUR:
        // write your action code here
        // group = GROUP_X; <-- or jump to another group X for composite commands
        break;
      case G2_FIVE:
        // write your action code here
        // group = GROUP_X; <-- or jump to another group X for composite commands
        break;
      case G2_SIX:
        // write your action code here
        // group = GROUP_X; <-- or jump to another group X for composite commands
        break;
      case G2_SEVEN:
        // write your action code here
        // group = GROUP_X; <-- or jump to another group X for composite commands
        break;
      case G2_EIGHT:
        // write your action code here
        // group = GROUP_X; <-- or jump to another group X for composite commands
        break;
      case G2_START:
        // write your action code here
        // group = GROUP_X; <-- or jump to another group X for composite commands
        break;
      case G2_STOP:
        // write your action code here
        // group = GROUP_X; <-- or jump to another group X for composite commands
        break;
      }
      break;
    }
}
