#ifndef _DIAMOND_H_
#define _DIAMOND_H_

#include "world.h"

#define DIAMOND_SIZE 2

class Diamond: public MovingObject {
public:
  Diamond(Vec2 position, Color color, Vec2 velocity = Vec2(0, 0));

  void render(Env *env);

  void update(Env *env);
};

#endif
