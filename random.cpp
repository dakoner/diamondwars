#include "random.h"

#ifndef ARDUINO
long random(long max) {
  return 42;
}

long random(long min, long max) {
  return 42;
}
#endif
