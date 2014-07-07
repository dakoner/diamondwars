#ifndef _WORLD_H_
#define _WORLD_H_

class World: public MovingObject {
  public:
    World(Vec2 position, Color color, Vec2 velocity = Vec2(-1, 0)): MovingObject(position, color, velocity) {
    }

    void render() {
      Vec2 q;
      for (int i = 0; i < stalagtites.size() - 1; ++i) {
        Vec2 v(i * 20, stalagtites[i]);
        Vec2 w((i + 1) * 20 , stalagtites[i + 1]);
        EsploraTFT.line(v.x() + position().x(), v.y(), w.x() + position().x(), w.y());
      }
      for (int i = 0; i < stalagmites.size() - 1; ++i) {
        Vec2 v(i * 20 + position().x(), myHeight - stalagmites[i]);
        Vec2 w((i + 1) * 20 + position().x(), myHeight - stalagmites[i + 1]);
        EsploraTFT.line(i * 20 + position().x(), myHeight - stalagmites[i], (i + 1) * 20 + position().x(), myHeight - stalagmites[i + 1]);
      }
    }

    void update() {
      mutable_position()->set_x(position().x() + velocity().x());

      if (position().x() < -20 * 16)
        mutable_position()->set_x(0);
    }
};

#endif
