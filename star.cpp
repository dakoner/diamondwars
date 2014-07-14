#include "star.h"
#include "world.h"
#include "env.h"

Star::Star(Vec2 position, Color color, Vec2 velocity): MovingObject(position, color, velocity, STAR_SIZE) {
}

void Star::render(Env *env) {
  int x = position().x();
  int y = position().y();
  World *world = env->getWorld();
  ui->point(x+world->position().x(), y);
}
void Star::update(Env *env) {
  if (position().x() < 0)
    mutable_position()->set_x(ui->width());
  if (position().x() > ui->width())
    mutable_position()->set_x(0);

  mutable_position()->set_x(position().x() + velocity().x());
  mutable_position()->set_y(position().y() + velocity().y());
}
