#ifndef _QT_INPUT_H_
#define _QT_INPUT_H_


#include <QtGui/QCursor>

class QtJoystick: public Joystick {
  bool readButton(unsigned char channel) {
    return !(QApplication::mouseButtons() & Qt::LeftButton);
  }
  int readJoystickX() {
    QPoint point = QCursor::pos();
    return int((point.x() - ui->width()/2) / float(ui->width()));
  }

  int readJoystickY() {
    QPoint point = QCursor::pos();
    return int((point.y() - ui->height()/2) / float(ui->height()));
  }
};

#endif
