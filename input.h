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
  int readButton(unsigned char s) {
    return 0;
  }
  int readJoystickX() {
    return 0;
  }

  int readJoystickY() {
    return 0;
  }
};

extern Joystick* joystick;
#endif
