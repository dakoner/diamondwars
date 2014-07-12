#ifndef ARDUINO
#include <iostream>
#include "constants.h"
#include "env.h"
#include "qt_ui.h"


int main(void) {
  constants = new Constants();
  ui = new QtUI();
  env = new Env();
  int i = 0;
  while(true) {
    env->loop();
    i++;
  }
 }
 #endif
