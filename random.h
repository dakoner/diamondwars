#ifndef _RANDOM_H_
#define _RANDOM_H_
#ifdef ARDUINO
#include <Arduino.h>
#else
long random(long max);

long random(long min, long max);
#endif

#endif
