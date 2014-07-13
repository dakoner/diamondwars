#include "random.h"
#include <stdlib.h>

// Adapt arduino random() function to libc random.
#ifndef ARDUINO
long random(long max) {
  return long(random() / float(RAND_MAX) * max);
}

long random(long min, long max) {
  long delta = max - min;
  return long(random() / float(RAND_MAX) * delta + min);
}
#endif
