#ifndef _SHIP_H_
#define _SHIP_H_

#include <iostream>
#include "vec2.h"
#include "color.h"
#include "constants.h"
#include "moving_object.h"
#include "env.h"
#include "ui.h"

class Ship: public MovingObject {
 public:
  Ship(Vec2 position, Color color, Vec2 velocity = Vec2(0, 0)); 

  void decrement_shield();
  void increment_shield();

  void die();

  void win();

  void render(Env *env);

  void update(Env *env);

 private:
  int shield;
};

extern bool shipCollided;

#endif
