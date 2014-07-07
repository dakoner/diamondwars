#ifndef _ENEMY_H_
#define _ENEMY_H_

class Enemy: public MovingObject {
  public:
    Enemy(Vec2 position, Color color, Vec2 velocity = Vec2(random(myWidth), random(myHeight))): MovingObject(position, color, velocity) {
    }

    void render() {
      int x = position().x();
      int y = position().y();
      EsploraTFT.rect(x, y, 5, 5);
    }

    void update() {
      mutable_position()->set_x(position().x() + velocity().x());
      mutable_position()->set_y(position().y() + velocity().y());

      if (position().x() < 0)
        mutable_velocity()->set_x(-velocity().x());

      if (position().x() > myWidth)
        mutable_velocity()->set_x(-velocity().x());

      if (position().y() < 0)
        mutable_velocity()->set_y(-velocity().y());

      if (position().y() > myHeight)
        mutable_velocity()->set_y(-velocity().y());
    }
};

#endif
