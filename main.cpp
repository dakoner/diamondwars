#ifndef ARDUINO
#include "constants.h"
#include "env.h"
#include "logging_gfx.h"
#include "dummy_input.h"


int main(void) {
  constants = new Constants();
  gfx = new LoggingGFX();
  env = new Env();
  joystick = new DummyJoystick();
  while(true) {
    env->loop();
  }
 }
 #endif
