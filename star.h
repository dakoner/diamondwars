#ifndef _STAR_H_
#define _STAR_H_

#include "world.h"
#include "env.h"

#define STAR_SIZE 12
class Star: public MovingObject {
  public:
  Star(Vec2 position, Color color, Vec2 velocity = Vec2(0, 0));
  void render(Env *env);
  void update(Env *env);
};

#endif
