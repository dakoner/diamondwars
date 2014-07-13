#ifndef _ENV_H_
#define _ENV_H_

#include <iterator>
#include <vector>
#include "ui.h"


#include "vec2.h"
#include "color.h"
#include "ship.h"
#include "enemy.h"
#include "world.h"
#include "star.h"
#include "bullet.h"
#include "diamond.h"

class Ship;

class Env {
 public:
  Env();
  void shootBullet();
  void erase();
  void update();
  void draw();
  void loop();
  Enemy* getEnemy();
  Ship* getShip();
  World* getWorld();
  std::vector<Star>* getStars();
  std::vector<Diamond>* getDiamonds();

  Ship* ship;
  Enemy* enemy;
  std::vector<Star> stars;
  World* world;
  std::vector<Bullet> bullets;
  std::vector<Diamond> diamonds;
};

extern Env *env;

#endif
