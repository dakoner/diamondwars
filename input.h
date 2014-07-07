#ifndef _INPUT_H_
#define _INPUT_H_

#ifdef ARDUINO
#include <Arduino.h>
#include <Esplora.h>
#else
typedef enum {
     LOW  = 0,
     HIGH = 1,
} Digivalue;
const unsigned char SWITCH_1       = 1;
#endif

class Joystick {
 public:
  virtual bool readButton(unsigned char s) = 0;
  virtual int readJoystickX() = 0;
  virtual int readJoystickY() = 0;
};

extern Joystick* joystick;
#endif
