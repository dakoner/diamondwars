#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_
#include "color.h"

#ifdef ESPLORA
#include <Arduino.h>
#include <Esplora.h>
#else
typedef enum {
  PRESSED  = 0,
  NOT_PRESSED = 1,
} Digivalue;
const unsigned char SWITCH_1       = 1;
#endif



class Constants {
 public:

 Constants() :
  numStars(30), starSpeed(4), 
    numDiamonds(30),
    backgroundColor(0, 0, 0),
    shipColor(255, 0, 0),
    diamondColor(255, 0, 0),
    enemyColor(0, 0, 255),
    worldColor(255, 255, 255),
    starColor(127, 127, 0),
    bulletColor(0, 255, 0) {
  }

  int numStars;
  int starSpeed;
  int numDiamonds;

  Color backgroundColor;
  Color shipColor;
  Color diamondColor;
  Color enemyColor;
  Color worldColor;
  Color starColor;
  Color bulletColor;
};

extern Constants *constants;

#endif
