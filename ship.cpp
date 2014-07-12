#include "ship.h"
#include "joystick.h"

Ship::Ship(Vec2 position, Color color, Vec2 velocity): MovingObject(position, color, velocity) {
}

void Ship::render(Env *env) {
  int x = position().x();
  int y = position().y();
  ui->rect(x, y, 2, 3);
  ui->rect(x + 2, y, 2, 2);
  ui->rect(x + 4, y, 2, 1);
  ui->rect(x + 4, y - 1, 1, 1);
}


void Ship::update(Env *env) {
  Vec2 accel(joystick->readJoystickX(),
	     joystick->readJoystickY());

  if (velocity().x() > 0.01) {
    mutable_velocity()->set_x(0.01);
  }
  if (velocity().x() < -0.01) {
    mutable_velocity()->set_x(-0.01);
  }
  if (velocity().y() > 0.01) {
    mutable_velocity()->set_y(0.01);
  }
  if (velocity().y() < -0.01) {
    mutable_velocity()->set_y(-0.01);
  }

  env->getWorld()->mutable_velocity()->set_x(-accel.x());
  std::vector<Star>* stars = env->getStars();
  for (std::vector<Star>::iterator star = stars->begin(); star != stars->end(); ++star) {
    star->mutable_velocity()->set_x(-accel.x()*2);
  }

  if (position().x() <= 0) {
    mutable_position()->set_x(0);
    mutable_velocity()->set_x(-velocity().x());
  }

  if (position().x() >= ui->width()-5) {
    mutable_position()->set_x(ui->width()-5);
    mutable_velocity()->set_x(-velocity().x());
  }

  if (position().y() < 0) {
    mutable_position()->set_y(0);
    mutable_velocity()->set_y(-velocity().y());
  }

  if (position().y() > ui->height()-5) {
    mutable_position()->set_y(ui->height()-5);
    mutable_velocity()->set_y(-velocity().y());
  }

  // mutable_velocity()->set_x(velocity().x() + accel.x());
  mutable_velocity()->set_y(velocity().y() + accel.y());
  // mutable_position()->set_x(position().x() + velocity().x());
  mutable_position()->set_y(position().y() + velocity().y());
}
