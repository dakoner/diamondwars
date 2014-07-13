#ifndef _ARDUINO_JOYSTICK_H_
#define _ARDUINO_JOYSTICK_H_

#include "joystick.h"

class EsploraJoystick: public Joystick {
 public:
  virtual bool readButton(unsigned char s);
  virtual float readJoystickX();
  virtual float readJoystickY();
};

#endif
