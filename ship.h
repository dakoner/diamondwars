#ifndef _SHIP_H_
#define _SHIP_H_

#include "vec2.h"
#include "color.h"
#include "constants.h"
#include "moving_object.h"
#include "input.h"
#include "gfx.h"

#ifdef ARDUINO
#include <Arduino.h>
#endif

class Env;

class Ship: public MovingObject {
  public:
    Ship(Vec2 position, Color color, Vec2 velocity = Vec2(0, 0)): MovingObject(position, color, velocity) {
    }

    void render(Env *env) {
      int x = position().x();
      int y = position().y();
      gfx->rect(x, y, 2, 3);
      gfx->rect(x + 2, y, 2, 2);
      gfx->rect(x + 4, y, 2, 1);
      gfx->rect(x + 4, y - 1, 1, 1);
    }


    void update(Env *env) {
      #ifdef ARDUINO
      Vec2 accel(map(joystick->readJoystickX(), 512, -512, -2, 2),
                 map(joystick->readJoystickY(), -512, 512, -2, 2));
      #else
      Vec2 accel(0, 0);
      #endif
      mutable_velocity()->set_x(velocity().x() + accel.x());
      mutable_velocity()->set_y(velocity().y() + accel.y());

      if (velocity().x() > 3)
        mutable_velocity()->set_x(3);

      if (velocity().y() > 3)
        mutable_velocity()->set_y(3);

      mutable_position()->set_x(position().x() + velocity().x());
      mutable_position()->set_y(position().y() + velocity().y());

      if (position().x() < 0)
        mutable_position()->set_x(0);

      if (position().x() > gfx->width())
        mutable_position()->set_x(gfx->width());

      if (position().y() < 0)
        mutable_position()->set_y(0);

      if (position().y() > gfx->height())
        mutable_position()->set_y(gfx->height());
    }
};

#endif
