#ifndef _QT_INPUT_H_
#define _QT_INPUT_H_

#include "input.h"
#include <QtGui/QCursor>

class QtJoystick: public Joystick {
  bool readButton(unsigned char channel) {
    return !(QApplication::mouseButtons() & Qt::LeftButton);
  }
  int readJoystickX() {
    return int((QCursor::pos().x() - gfx->width()/2) / float(gfx->width()) * 25);
  }

  int readJoystickY() {
    return int((QCursor::pos().y() - gfx->height()/2) / float(gfx->height()) * 25);
  }
};

#endif
