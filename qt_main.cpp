#ifndef ARDUINO
#include <iostream>
#include "constants.h"
#include "env.h"
#include "qt_ui.h"
#include "qt_joystick.h"
#include "joystick.h"


int main(void) {
  constants = new Constants();
  ui = new QtUI();
  joystick = new QtJoystick();
  env = new Env();
  int i = 0;
  while(true) {
    env->loop();
    i++;
  }
}
#endif
