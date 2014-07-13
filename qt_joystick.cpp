#ifndef ARDUINO
#include "qt_joystick.h"

bool QtJoystick::readButton(unsigned char channel) {
  return !(QApplication::mouseButtons() & Qt::LeftButton);
}

float QtJoystick::readJoystickX() {
  QPoint point = QCursor::pos();
    QtUI *qtui = (QtUI *)ui;
    QPoint mapped = qtui->getGraphicsView()->mapFromGlobal(QCursor::pos());
  return (mapped.x() - ui->width()/2) / float(ui->width())/64.;
}

float QtJoystick::readJoystickY() {
  QPoint point = QCursor::pos();
    QtUI *qtui = (QtUI *)ui;
    QPoint mapped = qtui->getGraphicsView()->mapFromGlobal(QCursor::pos());
  return (mapped.y() - ui->height()/2) / float(ui->height())/64.;
}


#endif
