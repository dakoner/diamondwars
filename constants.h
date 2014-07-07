#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_
#include "color.h"

class Constants {
  public:

 Constants(int width, int height) :
  myWidth(width), myHeight(height), 
  numStars(30), starSpeed(4), 
  backgroundColor(0, 0, 0),
  shipColor(255, 0, 0),
  enemyColor(0, 0, 255),
  worldColor(255, 255, 255),
  starColor(127, 127, 0),
  bulletColor(0, 255, 0) {
}
  int myWidth;
  int myHeight;

  int numStars;
  int starSpeed;

  Color backgroundColor;
  Color shipColor;
  Color enemyColor;
  Color worldColor;
  Color starColor;
  Color bulletColor;
};

extern Constants *constants;

#endif
