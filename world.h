#ifndef _WORLD_H_
#define _WORLD_H_

#include <iostream>

#include <vector>

#include "moving_object.h"
#include "enemy.h"
#include "vec2.h"
#include "color.h"
#include "collision.h"

#define NUM_HEIGHTS 48
#define SPACING 20

class World: public MovingObject {

 public:
  World(Vec2 position, Color color, Vec2 velocity = Vec2(0, 0));

  void render(Env *env);

  void update(Env *env);

  bool collide(const Vec2& a, const Vec2& b, MovingObject* object);

  const std::vector<int>& stalagtites();
  const std::vector<int>& stalagmites();

 private:
  // 16 items with width 20
  std::vector<int> _stalagtites;
  // 16 items with width 20
  std::vector<int> _stalagmites;

};

#endif
