#include "world.h"

World::World(Vec2 position, Color color, Vec2 velocity): MovingObject(position, color, velocity) {
    int st[16] = {10, 10, 10, 10, 10, 30, 10, 10, 10, 10, 10, 30, 10, 10, 60, 10};
    int sm[16] = {10, 10, 30, 10, 10, 60, 10, 10, 10, 30, 10, 10, 10, 10, 10, 10};
    _stalagtites.assign(st, st+16);
    _stalagmites.assign(sm, sm+16);
  }

  void World::render(Env *env) {
    Vec2 q;
    for (int i = 0; i < _stalagtites.size() - 1; ++i) {
      Vec2 v(i * 20, _stalagtites[i]);
      Vec2 w((i + 1) * 20, _stalagtites[i + 1]);
      gfx->line(v.x() + position().x(), v.y(), w.x() + position().x(), w.y());
    }
    
    {
      Vec2 v(15*20, _stalagtites[_stalagtites.size()-1]);
      Vec2 w(16*20, _stalagtites[0]);
      gfx->line(v.x() + position().x(), v.y(), w.x() + position().x(), w.y());
    }

    for (int i = 0; i < _stalagtites.size() - 1; ++i) {
      Vec2 v(i * 20, _stalagtites[i]);
      Vec2 w((i + 1) * 20, _stalagtites[i + 1]);
      gfx->line(v.x() + position().x() + (20*16), v.y(), w.x() + position().x() + (20*16), w.y());
    }


    
    for (int i = 0; i < _stalagmites.size() - 1; ++i) {
      Vec2 v(i * 20, gfx->height() - stalagmites()[i]);
      Vec2 w((i + 1) * 20, gfx->height() - stalagmites()[i + 1]);
      gfx->line(v.x() + position().x(), v.y(), w.x() + position().x(), w.y());
    }
    {
      Vec2 v(15*20, gfx->height() - _stalagmites[_stalagmites.size()-1]);
      Vec2 w(16*20, gfx->height() - _stalagmites[0]);
      gfx->line(v.x() + position().x(), v.y(), w.x() + position().x(), w.y());
    }

    for (int i = 0; i < _stalagmites.size() - 1; ++i) {
      Vec2 v(i * 20, _stalagtites[i]);
      Vec2 w((i + 1) * 20, _stalagtites[i + 1]);
      gfx->line(i * 20 + position().x() + (20*16), gfx->height() - stalagmites()[i], (i + 1) * 20 + position().x() + (20*16), gfx->height() - stalagmites()[i + 1]);
    }
}

void World::update(Env *env) {
  mutable_position()->set_x(position().x() + velocity().x());

  if (position().x() < -20 * 16)
    mutable_position()->set_x(0);
}

void World::collide(Enemy& enemy) {
  for (int i = 0; i < _stalagtites.size() - 1; ++i) {
    Vec2 a(i * 20, _stalagtites[i]);
    Vec2 b((i + 1) * 20, _stalagtites[i + 1]);
    Vec2 offset = segment_circle(a, b, circle);
    if (offset.x() != 0 && offset.y() != 0) {
      mutable_velocity()->set_x(velocity().x() + offset.x());
      mutable_velocity()->set_y(velocity().y() + offset.y());
#ifdef ARDUINO
      Serial.print("Collision.  offset: ");
      Serial.print(offset.x());
      Serial.println(offset.y());
#else
      std::cout << "Collision. offset: " << offset.x() << " " << offset.y() << std::endl;
#endif
    }
  }
}

const std::vector<int>& World::stalagtites() { return _stalagtites; }
const std::vector<int>& World::stalagmites() { return _stalagmites; }
