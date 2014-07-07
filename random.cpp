#include "random.h"

#ifndef ARDUINO
long random(long max) {
  return 2;
}

long random(long min, long max) {
  return 2;
}
#endif
