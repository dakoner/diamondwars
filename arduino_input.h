#ifndef _ARDUINO_INPUT_H_
#define _ARDUINO_INPUT_H_

#include <Esplora.h>

#include "input.h"

class ArduinoJoystick: public Joystick {
  boolean readButton(unsigned char channel) {
    return Esplora.readButton(channel);
  }
  int readJoystickX() {
    return map(Esplora.readJoystickX(), 512, -512, -2, 2);
  }

  int readJoystickY() {
    return map(Esplora.readJoystickX(), -512, 512, -2, 2);
  }
};

#endif
