#ifndef ARDUINO
#include "constants.h"
#include "env.h"
#include "logging_gfx.h"
#include "input.h"


int main(void) {
  constants = new Constants();
  gfx = new LoggingGFX();
  env = new Env();
  joystick = new Joystick();
  while(true) {
    env->loop();
  }
 }
 #endif
