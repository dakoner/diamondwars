#ifndef _BULLET_H_
#define _BULLET_H_
#include "moving_object.h"
#include "killable.h"
#include "vec2.h"
#include "color.h"
#include "constants.h"
#include "gfx.h"

class Bullet: public MovingObject, public Killable {
  public:
    Bullet(Vec2 position, Color color, Vec2 velocity = Vec2(4, 0)): MovingObject(position, color, velocity) {
    }

    void render(Env *env) {
      int x = position().x();
      int y = position().y();
      gfx->rect(x - 1, y - 1, 2, 2);
    }

    void update(Env *env) {
      mutable_position()->set_x(position().x() + velocity().x());
      if (position().x() > gfx->width()) {
        kill();
        // mark dead, remove from container
      }
    }
};

#endif
