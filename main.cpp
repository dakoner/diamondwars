#ifndef ARDUINO
#include <iostream>
#include "constants.h"
#include "env.h"
#include "sdl_gfx.h"
#include "dummy_input.h"


int main(void) {
  constants = new Constants();
  gfx = new SDLGFX();
  env = new Env();
  joystick = new DummyJoystick();
  int i = 0;
  while(true) {
    env->loop();
    i++;
  }
 }
 #endif
