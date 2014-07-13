#ifndef _QT_JOYSTICK_H_
#define _QT_JOYSTICK_H_

#include "joystick.h"
#include "qt_ui.h"

#include "constants.h"

#include <unistd.h>

class QtJoystick: public Joystick {
 public:
  bool readButton(unsigned char channel);
  float readJoystickX();
  float readJoystickY();
};


#endif
