#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "moving_object.h"
#include "color.h"
#include "vec2.h"
#include "ui.h"
#include "random.h"

class Env;

#define ENEMY_SIZE 12

class Enemy: public MovingObject {
 public:
   Enemy(Vec2 position, Color color, Vec2 velocity);

  void render(Env *env);

  void update(Env *env);
    
};

#endif
