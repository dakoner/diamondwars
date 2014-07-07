#ifndef _WORLD_H_
#define _WORLD_H_

class World: public MovingObject {

 public:
 World(Vec2 position, Color color, Vec2 velocity = Vec2(-1, 0)): MovingObject(position, color, velocity) {
    int st[16] = {10, 10, 10, 10, 10, 30, 10, 10, 10, 10, 10, 30, 10, 10, 60, 10};
    int sm[16] = {10, 10, 30, 10, 10, 60, 10, 10, 10, 30, 10, 10, 10, 10, 10, 10};
    _stalagtites.assign(st, st+16);
    _stalagmites.assign(sm, sm+16);
  }

  void render(Env *env) {
    Vec2 q;
    for (int i = 0; i < _stalagtites.size() - 1; ++i) {
      Vec2 v(i * 20, _stalagtites[i]);
      Vec2 w((i + 1) * 20, _stalagtites[i + 1]);
      EsploraTFT.line(v.x() + position().x(), v.y(), w.x() + position().x(), w.y());
    }
    for (int i = 0; i < _stalagmites.size() - 1; ++i) {
      Vec2 v(i * 20 + position().x(), constants->myHeight - stalagmites()[i]);
      Vec2 w((i + 1) * 20 + position().x(), constants->myHeight - stalagmites()[i + 1]);
      EsploraTFT.line(i * 20 + position().x(), constants->myHeight - stalagmites()[i], (i + 1) * 20 + position().x(), constants->myHeight - stalagmites()[i + 1]);
    }
  }

  void update(Env *env) {
    mutable_position()->set_x(position().x() + velocity().x());

    if (position().x() < -20 * 16)
      mutable_position()->set_x(0);
  }

  const std::vector<int>& stalagtites() { return _stalagtites; }
  const std::vector<int>& stalagmites() { return _stalagmites; }

 private:
  // 16 items with width 20
  std::vector<int> _stalagtites;
  // 16 items with width 20
  std::vector<int> _stalagmites;

};

#endif
