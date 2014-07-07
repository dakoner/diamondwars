#ifndef ARDUINO
#include <iostream>
#include "constants.h"
#include "env.h"
#include "dummy_gfx.h"
#include "dummy_input.h"


int main(void) {
  constants = new Constants();
  gfx = new DummyGFX();
  env = new Env();
  joystick = new DummyJoystick();
  int i = 0;
  while(true) {
    std::cout << "Step: " << i << std::endl;
    env->loop();
    i++;
  }
 }
 #endif
