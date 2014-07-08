#ifndef _ENV_H_
#define _ENV_H_

#include <iterator>
#include <vector>
#include "gfx.h"


#include "vec2.h"
#include "color.h"
#include "ship.h"
#include "enemy.h"
#include "world.h"
#include "star.h"
#include "bullet.h"
#include "input.h"

class Env {
 public:
  Env();
  void shootBullet();
  void loop();

  Ship *ship;
  Enemy *enemy;
  std::vector<Star> stars;
  World *world;
  std::vector<Bullet> bullets;
};

extern Env *env;

#endif
