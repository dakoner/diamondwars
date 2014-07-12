#ifndef _STAR_H_
#define _STAR_H_
class Star: public MovingObject {
  public:
    Star(Vec2 position, Color color, Vec2 velocity = Vec2(0, 0)): MovingObject(position, color, velocity) {
    }

    void render(Env *env) {
      int x = position().x();
      int y = position().y();
      ui->point(x, y);

    }
    void update(Env *env) {
      if (position().x() < 0)
        mutable_position()->set_x(ui->width());
      if (position().x() > ui->width())
        mutable_position()->set_x(0);

      mutable_position()->set_x(position().x() + velocity().x());
      mutable_position()->set_y(position().y() + velocity().y());
    }
};

#endif
