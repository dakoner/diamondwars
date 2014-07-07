#ifndef _DUMMY_INPUT_H_
#define _DUMMY_INPUT_H_

#include "input.h"

class DummyJoystick: public Joystick {
  bool readButton(unsigned char channel) {
    return false;
  }
  int readJoystickX() {
    return 0;
  }

  int readJoystickY() {
    return 0;
  }
};

#endif
