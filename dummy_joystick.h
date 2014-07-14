#ifndef _DUMMY_JOYSTICK_H_
#define _DUMMY_JOYSTICK_H_

#include "joystick.h"

class DummyJoystick: public Joystick {
 public:
  virtual bool readButton(unsigned char s) { return false; }
  virtual float readJoystickX() { return 0; }
  virtual float readJoystickY() { return 0; }
};

#endif
