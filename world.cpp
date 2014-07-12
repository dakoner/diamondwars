#include "world.h"
#include "env.h"

#define NUM_HEIGHTS 32

World::World(Vec2 position, Color color, Vec2 velocity): MovingObject(position, color, velocity) {
  int st[NUM_HEIGHTS] = {10, 10, 10, 10, 10, 30, 10, 10, 10, 10, 10, 30, 10, 10, 60, 10, 20, 20, 30, 30, 40, 40, 50, 50, 40, 40, 30, 30, 20, 20, 10, 10};
  int sm[NUM_HEIGHTS] = {10, 10, 30, 10, 10, 60, 10, 10, 10, 30, 10, 10, 10, 10, 10, 10, 20, 20, 30, 30, 40, 40, 50, 50, 40, 40, 30, 30, 20, 20, 10, 10};
    _stalagtites.assign(st, st+NUM_HEIGHTS);
    _stalagmites.assign(sm, sm+NUM_HEIGHTS);
  }

void World::collide(const Vec2& a, const Vec2& b, MovingObject* object) {
  Vec2 offset = segment_circle(a, b, object->position());
  if (offset.x() != 0 && offset.y() != 0) {
    object->mutable_velocity()->set_x(
				     object->velocity().x() +
				     offset.x());
    object->mutable_velocity()->set_y(
				     object->velocity().y() +
				     offset.y());
#ifdef ARDUINO
    Serial.print("Collision.  offset: ");
    Serial.print(offset.x());
    Serial.println(offset.y());
#else
    // std::cout << "sm Collision. offset: " << offset.x() << " " << offset.y() << std::endl;
#endif
  }
}

  void World::render(Env *env) {
    Vec2 q;
    for (int i = 0; i < _stalagtites.size() - 1; ++i) {
      Vec2 v(i * 20 + position().x(), _stalagtites[i]);
      Vec2 w((i + 1) * 20 + position().x(), _stalagtites[i + 1]);
      ui->line(v.x(), v.y(), w.x(), w.y());
      collide(v, w, env->getEnemy());
    }
    
    {
      Vec2 v((NUM_HEIGHTS-1)*20 + position().x(), _stalagtites[_stalagtites.size()-1]);
      Vec2 w(NUM_HEIGHTS*20 + position().x(), _stalagtites[0]);
      ui->line(v.x(), v.y(), w.x(), w.y());
      collide(v, w, env->getEnemy());
    }

    for (int i = 0; i < _stalagtites.size() - 1; ++i) {
      Vec2 v(i * 20 + position().x() + (20*NUM_HEIGHTS), _stalagtites[i]);
      Vec2 w((i + 1) * 20 + position().x() + (20*NUM_HEIGHTS), _stalagtites[i + 1]);
      ui->line(v.x(), v.y(), w.x(), w.y());
      collide(v, w, env->getEnemy());
    }


    
    for (int i = 0; i < _stalagmites.size() - 1; ++i) {
      Vec2 v(i * 20 + position().x(), ui->height() - stalagmites()[i]);
      Vec2 w((i + 1) * 20 + position().x(), ui->height() - stalagmites()[i + 1]);
      ui->line(v.x(), v.y(), w.x(), w.y());
      collide(v, w, env->getEnemy());
    }
    {
      Vec2 v((NUM_HEIGHTS-1)*20 + position().x(), ui->height() - _stalagmites[_stalagmites.size()-1]);
      Vec2 w(NUM_HEIGHTS*20 + position().x(), ui->height() - _stalagmites[0]);
      ui->line(v.x(), v.y(), w.x(), w.y());
      collide(v, w, env->getEnemy());
    }

    for (int i = 0; i < _stalagmites.size() - 1; ++i) {
      Vec2 v(i * 20 + position().x() + (20*NUM_HEIGHTS), ui->height() -_stalagmites[i]);
      Vec2 w((i + 1) * 20 + position().x() + (20*NUM_HEIGHTS), ui->height() -_stalagmites[i + 1]);
      ui->line(v.x(),  v.y(), w.x(), w.y());
      collide(v, w, env->getEnemy()); 
    }
}

void World::update(Env *env) {
  mutable_position()->set_x(position().x() + velocity().x());

  if (position().x() < -20 * NUM_HEIGHTS)
    mutable_position()->set_x(0);
}

const std::vector<int>& World::stalagtites() { return _stalagtites; }
const std::vector<int>& World::stalagmites() { return _stalagmites; }
