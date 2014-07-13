#include "world.h"
#include "env.h"
#include "collision.h"

World::World(Vec2 position, Color color, Vec2 velocity): MovingObject(position, color, velocity, 0) {
  int st[NUM_HEIGHTS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10, 10, 10, 30, 10, 10, 10, 10, 10, 30, 10, 10, 60, 10, 20, 20, 30, 30, 40, 40, 50, 50, 40, 40, 30, 30, 20, 20, 10, 10, 10, 70, 70, 10, 10};
  int sm[NUM_HEIGHTS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 30, 10, 10, 60, 10, 10, 10, 30, 10, 10, 10, 10, 10, 10, 20, 20, 30, 30, 40, 40, 50, 50, 40, 40, 30, 30, 20, 20, 10, 10, 10, 10, 10, 10, 70};
    _stalagtites.assign(st, st+NUM_HEIGHTS);
    _stalagmites.assign(sm, sm+NUM_HEIGHTS);
  }

  void World::render(Env *env) {
    Vec2 q;
    Enemy *enemy = env->getEnemy();
    Ship *ship = env->getShip();
    for (int i = 0; i < _stalagtites.size() - 1; ++i) {
      Vec2 v(i * SPACING + position().x() - (SPACING*NUM_HEIGHTS), _stalagtites[i]);
      Vec2 w((i + 1) * SPACING + position().x() - (SPACING*NUM_HEIGHTS), _stalagtites[i + 1]);
      ui->line(v.x(), v.y(), w.x(), w.y());
      ::collide(v, w, enemy);
      if (::collide(v, w, ship)) ship->decrement_shield();
    }

    {
      Vec2 v((NUM_HEIGHTS-1)*SPACING + position().x() - (SPACING*NUM_HEIGHTS), _stalagtites[_stalagtites.size()-1]);
      Vec2 w(NUM_HEIGHTS*SPACING + position().x() - (SPACING*NUM_HEIGHTS), _stalagtites[0]);
      ui->line(v.x(), v.y(), w.x(), w.y());
      ::collide(v, w, enemy);
      if (::collide(v, w, ship)) ship->decrement_shield();
    }

    for (int i = 0; i < _stalagtites.size() - 1; ++i) {
      Vec2 v(i * SPACING + position().x(), _stalagtites[i]);
      Vec2 w((i + 1) * SPACING + position().x(), _stalagtites[i + 1]);
      ui->line(v.x(), v.y(), w.x(), w.y());
      ::collide(v, w, enemy);
      if (::collide(v, w, ship)) ship->decrement_shield();
    }
    
    {
      Vec2 v((NUM_HEIGHTS-1)*SPACING + position().x(), _stalagtites[_stalagtites.size()-1]);
      Vec2 w(NUM_HEIGHTS*SPACING + position().x(), _stalagtites[0]);
      ui->line(v.x(), v.y(), w.x(), w.y());
      ::collide(v, w, enemy);
      if (::collide(v, w, ship)) ship->decrement_shield();
    }

    for (int i = 0; i < _stalagtites.size() - 1; ++i) {
      Vec2 v(i * SPACING + position().x() + (SPACING*NUM_HEIGHTS), _stalagtites[i]);
      Vec2 w((i + 1) * SPACING + position().x() + (SPACING*NUM_HEIGHTS), _stalagtites[i + 1]);
      ui->line(v.x(), v.y(), w.x(), w.y());
      ::collide(v, w, enemy);
      if (::collide(v, w, ship)) ship->decrement_shield();
    }


    
    for (int i = 0; i < _stalagmites.size() - 1; ++i) {
      Vec2 v(i * SPACING + position().x() - (SPACING*NUM_HEIGHTS), ui->height() -_stalagmites[i]);
      Vec2 w((i + 1) * SPACING + position().x() - (SPACING*NUM_HEIGHTS), ui->height() -_stalagmites[i + 1]);
      ui->line(v.x(),  v.y(), w.x(), w.y());
      ::collide(v, w, enemy); 
      if (::collide(v, w, ship)) ship->decrement_shield();
    }
    {
      Vec2 v((NUM_HEIGHTS-1)*SPACING + position().x() - (SPACING*NUM_HEIGHTS), ui->height() - _stalagmites[_stalagmites.size()-1]);
      Vec2 w(NUM_HEIGHTS*SPACING + position().x() - (SPACING*NUM_HEIGHTS), ui->height() - _stalagmites[0]);
      ui->line(v.x(), v.y(), w.x(), w.y());
      ::collide(v, w, enemy);
      if (::collide(v, w, ship)) ship->decrement_shield();
    }
    for (int i = 0; i < _stalagmites.size() - 1; ++i) {
      Vec2 v(i * SPACING + position().x(), ui->height() - stalagmites()[i]);
      Vec2 w((i + 1) * SPACING + position().x(), ui->height() - stalagmites()[i + 1]);
      ui->line(v.x(), v.y(), w.x(), w.y());
      ::collide(v, w, enemy);
      if (::collide(v, w, ship)) ship->decrement_shield();
    }
    {
      Vec2 v((NUM_HEIGHTS-1)*SPACING + position().x(), ui->height() - _stalagmites[_stalagmites.size()-1]);
      Vec2 w(NUM_HEIGHTS*SPACING + position().x(), ui->height() - _stalagmites[0]);
      ui->line(v.x(), v.y(), w.x(), w.y());
      ::collide(v, w, enemy);
      if (::collide(v, w, ship)) ship->decrement_shield();
    }
    for (int i = 0; i < _stalagmites.size() - 1; ++i) {
      Vec2 v(i * SPACING + position().x() + (SPACING*NUM_HEIGHTS), ui->height() -_stalagmites[i]);
      Vec2 w((i + 1) * SPACING + position().x() + (SPACING*NUM_HEIGHTS), ui->height() -_stalagmites[i + 1]);
      ui->line(v.x(),  v.y(), w.x(), w.y());
      ::collide(v, w, enemy); 
      if (::collide(v, w, ship)) ship->decrement_shield();
    }
}

void World::update(Env *env) {
  mutable_position()->set_x(position().x() + velocity().x());

  if (position().x() < -SPACING * NUM_HEIGHTS) {
    mutable_position()->set_x(0);
  }
  if (position().x() > SPACING * NUM_HEIGHTS) {
    mutable_position()->set_x(0);
  }
}

const std::vector<int>& World::stalagtites() { return _stalagtites; }
const std::vector<int>& World::stalagmites() { return _stalagmites; }
