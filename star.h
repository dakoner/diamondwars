#ifndef _STAR_H_
#define _STAR_H_
class Star: public MovingObject {
  public:
    Star(Vec2 position, Color color, Vec2 velocity = Vec2(-2, 0)): MovingObject(position, color, velocity) {
    }

    void render(Env *env) {
      int x = position().x();
      int y = position().y();
      gfx->point(x, y);

    }
    void update(Env *env) {
      mutable_position()->set_x(position().x() + velocity().x());
      mutable_position()->set_y(position().y() + velocity().y());

      if (position().x() < 0)
        mutable_position()->set_x(gfx->width());
    }
};

#endif
