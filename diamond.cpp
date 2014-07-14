#include "diamond.h"

Diamond::Diamond(Vec2 position, Color color, Vec2 velocity): MovingObject(position, color, velocity, DIAMOND_SIZE) {
}

void Diamond::render(Env *env) {
  int x = position().x();
  int y = position().y();
  ui->point(x, y-2);
  ui->point(x-1, y-1);
  ui->point(x, y);
  ui->point(x+1, y+1);
  ui->point(x, y+2);
}

void Diamond::update(Env *env) {
  if (position().x() < 0)
    mutable_position()->set_x(ui->width());
  if (position().x() > SPACING * NUM_HEIGHTS)
    mutable_position()->set_x(0);

  mutable_position()->set_x(position().x() + velocity().x());
  mutable_position()->set_y(position().y() + velocity().y());
}
