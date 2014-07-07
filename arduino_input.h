#ifndef _ARDUINO_INPUT_H_
#define _ARDUINO_INPUT_H_

#include <Esplora.h>

#include "input.h"

class ArduinoJoystick: public Joystick {
  int readButton(int s) {
    return Esplora.readButton(s);
  }
  int readJoystickX() {
    return Esplora.readJoystickX();
  }

  int readJoystickY() {
    return Esplora.readJoystickY();
  }
};

#endif
