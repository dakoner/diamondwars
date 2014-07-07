#ifndef ARDUINO
#include "constants.h"
#include "env.h"

extern long random(long max) {
  return 42;
}

extern long random(long min, long max) {
  return 42;
}

int main(void) {
  constants = new Constants(256, 256);
  env = new Env();
  env->loop();
 }
 #endif
