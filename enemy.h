#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "moving_object.h"
#include "color.h"
#include "vec2.h"
#include "gfx.h"
#include "random.h"

class Env;

class Enemy: public MovingObject {
 public:
  Enemy(Vec2 position, Color color, Vec2 velocity = Vec2(random(gfx->width()), random(gfx->height()))): MovingObject(position, color, velocity) {
  }

  void render(Env *env);

  void update(Env *env) {
    mutable_position()->set_x(position().x() + velocity().x());
    mutable_position()->set_y(position().y() + velocity().y());

    if (position().x() < 0)
      mutable_velocity()->set_x(-velocity().x());

    if (position().x() > gfx->width())
      mutable_velocity()->set_x(-velocity().x());

    if (position().y() < 0)
      mutable_velocity()->set_y(-velocity().y());

    if (position().y() > gfx->height())
      mutable_velocity()->set_y(-velocity().y());
  }


    
};

#endif
