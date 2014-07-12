#include "enemy.h"
#include "env.h"

void Enemy::render(Env *env) {
  int x = position().x();
  int y = position().y();
  ui->rect(x -2.5, y-2.5, 5, 5);

}

void Enemy::update(Env *env) {
  if (velocity().x() > 0.25) {
    mutable_velocity()->set_x(0.25);
  }
  if (velocity().x() < -0.25) {
    mutable_velocity()->set_x(-0.25);
  }
  if (velocity().y() > 0.25) {
    mutable_velocity()->set_y(0.25);
  }
  if (velocity().y() < -0.25) {
    mutable_velocity()->set_y(-0.25);
  }

  if (position().x() <= 0) {
    mutable_position()->set_x(0);
    mutable_velocity()->set_x(-velocity().x());
  }

  if (position().x() >= ui->width() - 2.5) {
    mutable_position()->set_x(ui->width() - 2.5);
    mutable_velocity()->set_x(-velocity().x());
  }

  if (position().y() <= 0) {
    mutable_position()->set_y(0);
    mutable_velocity()->set_y(-velocity().y());
  }

  if (position().y() >= ui->height() - 2.5) {
    mutable_position()->set_y(ui->height() - 2.5);
    mutable_velocity()->set_y(-velocity().y());
  }
  mutable_position()->set_x(position().x() + velocity().x());
  mutable_position()->set_y(position().y() + velocity().y());
}

