#ifndef _QT_JOYSTICK_H_
#define _QT_JOYSTICK_H_

#include "joystick.h"
#include "qt_ui.h"

#include <Qt/qapplication.h>
#include <Qt/q3canvas.h>
#include <Qt3Support/Q3CanvasItem>

#include "constants.h"

#include <unistd.h>

class QtJoystick: public Joystick {
 public:
  bool readButton(unsigned char channel);
  float readJoystickX();
  float readJoystickY();
};


#endif
