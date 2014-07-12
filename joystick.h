#ifndef _JOYSTICK_H_
#define _JOYSTICK_H_

class Joystick {
 public:
  virtual bool readButton(unsigned char s) = 0;
  virtual float readJoystickX() = 0;
  virtual float readJoystickY() = 0;
};

extern Joystick *joystick;
#endif
