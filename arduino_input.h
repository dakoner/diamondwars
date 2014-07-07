#ifndef _ARDUINO_INPUT_H_
#define _ARDUINO_INPUT_H_

#include <Esplora.h>

#include "input.h"

class ArduinoJoystick: public Joystick {
  boolean readButton(unsigned char channel) {
    return Esplora.readButton(channel);
  }
  int readJoystickX() {
    return Esplora.readJoystickX();
  }

  int readJoystickY() {
    return Esplora.readJoystickY();
  }
};

#endif
