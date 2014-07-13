#include <utility>
#include <vector>

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
    
  std::vector<std::pair<Vec2, Vec2> > lines;

  for (int i = 0; i < _stalagtites.size() - 1; ++i) {
    Vec2 v(i * SPACING - (SPACING*NUM_HEIGHTS), _stalagtites[i]);
    Vec2 w((i + 1) * SPACING - (SPACING*NUM_HEIGHTS), _stalagtites[i + 1]);
    lines.push_back(std::make_pair(v, w));
  }

  {
    Vec2 v((NUM_HEIGHTS-1)*SPACING - (SPACING*NUM_HEIGHTS), _stalagtites[_stalagtites.size()-1]);
    Vec2 w(NUM_HEIGHTS*SPACING - (SPACING*NUM_HEIGHTS), _stalagtites[0]);
    lines.push_back(std::make_pair(v, w));
  }

  for (int i = 0; i < _stalagtites.size() - 1; ++i) {
    Vec2 v(i * SPACING, _stalagtites[i]);
    Vec2 w((i + 1) * SPACING, _stalagtites[i + 1]);
    lines.push_back(std::make_pair(v, w));
  }
    
  {
    Vec2 v((NUM_HEIGHTS-1)*SPACING, _stalagtites[_stalagtites.size()-1]);
    Vec2 w(NUM_HEIGHTS*SPACING, _stalagtites[0]);
    lines.push_back(std::make_pair(v, w));
  }

  for (int i = 0; i < _stalagtites.size() - 1; ++i) {
    Vec2 v(i * SPACING + (SPACING*NUM_HEIGHTS), _stalagtites[i]);
    Vec2 w((i + 1) * SPACING + (SPACING*NUM_HEIGHTS), _stalagtites[i + 1]);
    lines.push_back(std::make_pair(v, w));
  }


    
  for (int i = 0; i < _stalagmites.size() - 1; ++i) {
    Vec2 v(i * SPACING - (SPACING*NUM_HEIGHTS), ui->height() -_stalagmites[i]);
    Vec2 w((i + 1) * SPACING - (SPACING*NUM_HEIGHTS), ui->height() -_stalagmites[i + 1]);
    lines.push_back(std::make_pair(v, w));
  }
  {
    Vec2 v((NUM_HEIGHTS-1)*SPACING - (SPACING*NUM_HEIGHTS), ui->height() - _stalagmites[_stalagmites.size()-1]);
    Vec2 w(NUM_HEIGHTS*SPACING - (SPACING*NUM_HEIGHTS), ui->height() - _stalagmites[0]);
    lines.push_back(std::make_pair(v, w));
  }
  for (int i = 0; i < _stalagmites.size() - 1; ++i) {
    Vec2 v(i * SPACING, ui->height() - stalagmites()[i]);
    Vec2 w((i + 1) * SPACING, ui->height() - stalagmites()[i + 1]);
    lines.push_back(std::make_pair(v, w));
  }
  {
    Vec2 v((NUM_HEIGHTS-1)*SPACING, ui->height() - _stalagmites[_stalagmites.size()-1]);
    Vec2 w(NUM_HEIGHTS*SPACING, ui->height() - _stalagmites[0]);
    lines.push_back(std::make_pair(v, w));
  }
  for (int i = 0; i < _stalagmites.size() - 1; ++i) {
    Vec2 v(i * SPACING + (SPACING*NUM_HEIGHTS), ui->height() -_stalagmites[i]);
    Vec2 w((i + 1) * SPACING + (SPACING*NUM_HEIGHTS), ui->height() -_stalagmites[i + 1]);
    lines.push_back(std::make_pair(v, w));
  }
  for (std::vector<std::pair<Vec2, Vec2> >::iterator it = lines.begin(); it != lines.end(); ++it) {
    const Vec2& v = it->first;
    const Vec2& w = it->second;
    const Vec2& vp = Vec2(v.x() + position().x(), v.y());
    const Vec2& wp = Vec2(w.x() + position().x(), w.y());
    ui->line(vp.x(),  vp.y(), wp.x(), wp.y());
    ::collide(vp, wp, enemy); 
    if (::collide(vp, wp, ship)) ship->decrement_shield();
   
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
