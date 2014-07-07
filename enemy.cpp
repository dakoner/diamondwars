#include "enemy.h"
#include "env.h"

void Enemy::render(Env *env) {
  int x = position().x();
  int y = position().y();
  gfx->rect(x, y, 5, 5);

  Vec2 q;
  for (int i = 0; i < env->world->stalagtites().size() - 1; ++i) {
    Vec2 v(i * 20 + position().x(), env->world->stalagtites()[i]);
    Vec2 w((i + 1) * 20 + position().x(), env->world->stalagtites()[i + 1]);
    float d = DistanceFromLineSegmentToPoint(v, w, position(), &q);
    if (d < 50) {
	  
    }
  }
}
