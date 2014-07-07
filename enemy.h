#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "moving_object.h"
#include "color.h"
#include "vec2.h"
#include <Arduino.h>

class Env;

class Enemy: public MovingObject {
 public:
 Enemy(Vec2 position, Color color, Vec2 velocity = Vec2(random(constants->myWidth), random(constants->myHeight))): MovingObject(position, color, velocity) {
  }

  void render(Env *env);

  void update(Env *env) {
    mutable_position()->set_x(position().x() + velocity().x());
    mutable_position()->set_y(position().y() + velocity().y());

    if (position().x() < 0)
      mutable_velocity()->set_x(-velocity().x());

    if (position().x() > constants->myWidth)
      mutable_velocity()->set_x(-velocity().x());

    if (position().y() < 0)
      mutable_velocity()->set_y(-velocity().y());

    if (position().y() > constants->myHeight)
      mutable_velocity()->set_y(-velocity().y());
  }


    
};

#endif
