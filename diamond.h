#ifndef _DIAMOND_H_
#define _DIAMOND_H_

#include "world.h"

#define DIAMOND_SIZE 2

class Diamond: public MovingObject {
  public:
  Diamond(Vec2 position, Color color, Vec2 velocity = Vec2(0, 0)): MovingObject(position, color, velocity, DIAMOND_SIZE) {
    }

    void render(Env *env) {
      int x = position().x();
      int y = position().y();
      ui->point(x, y-2);
      ui->point(x-1, y-1);
      ui->point(x, y);
      ui->point(x+1, y+1);
      ui->point(x, y+2);
    }

    void update(Env *env) {
      if (position().x() < 0)
        mutable_position()->set_x(ui->width());
      if (position().x() > SPACING * NUM_HEIGHTS)
        mutable_position()->set_x(0);

      mutable_position()->set_x(position().x() + velocity().x());
      mutable_position()->set_y(position().y() + velocity().y());
    }
};

#endif
