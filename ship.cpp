#include <stdio.h>

#include "ship.h"
#include "joystick.h"

const int shipSize = 6;

Ship::Ship(Vec2 position, Color color, Vec2 velocity): MovingObject(position, color, velocity, shipSize), shield(10) {
}

void Ship::render(Env *env) {
  int x = position().x();
  int y = position().y();
  ui->rect(x, y, 2, 3);
  ui->rect(x + 2, y, 2, 2);
  ui->rect(x + 4, y, 2, 1);
  ui->rect(x + 4, y - 1, 1, 1);
  char score[32];
  snprintf(score, 32, "Shield: %d", shield);
  ui->text(35, 0, score);
}


void Ship::update(Env *env) {
  Vec2 vj(joystick->readJoystickX(),
	  joystick->readJoystickY());
  accel.set_x(vj.x()*0.5);
  accel.set_y(vj.y()*0.5);

  bool collided = false;
  const std::vector<std::pair<Vec2, Vec2> >& lines = env->getWorld()->getLines();
  for (std::vector<std::pair<Vec2, Vec2> >::const_iterator it = lines.begin(); it != lines.end(); ++it) {
    const Vec2& v = it->first;
    const Vec2& w = it->second;
    if (::collide(v, w, this)) {
      collided = true;
      decrement_shield();
    }
  }

  env->getWorld()->mutable_velocity()->set_x(-velocity().x()*2);
  std::vector<Star>* stars = env->getStars();
  for (std::vector<Star>::iterator star = stars->begin(); star != stars->end(); ++star) {
    star->mutable_velocity()->set_x(-velocity().x());
  }

  std::vector<Diamond>* diamonds = env->getDiamonds();
  for (std::vector<Diamond>::iterator diamond = diamonds->begin(); diamond != diamonds->end(); ++diamond) {
      diamond->mutable_velocity()->set_x(-velocity().x()*2);
  }

  for (std::vector<Diamond>::iterator diamond = diamonds->begin(); diamond != diamonds->end();) {
    if (collide(this, &*diamond)) {
      diamond = diamonds->erase(diamond);
      if (diamonds->size() == 0)
	win();
      else
	shield++;
    }
    else {
      ++diamond;
    }
  }

  if (collide(this, env->getEnemy())) {
    shield--;
  }

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

  if (accel.x() > 0.25) {
    accel.set_x(0.25);
  }
  if (accel.x() < -0.25) {
    accel.set_x(-0.25);
  }
  if (accel.y() > 0.25) {
    accel.set_y(0.25);
  }
  if (accel.y() < -0.25) {
    accel.set_y(-0.25);
  }

  if (position().x() <= ui->width()/4.) {
    mutable_position()->set_x(ui->width()/4.);
  }

  if (position().x() >= ui->width()*3/4.) {
    mutable_position()->set_x(ui->width()*3/4.);
  }

  if (position().y() < 0) {
    mutable_position()->set_y(0);
  }

  if (position().y() > ui->height()-2.5) {
    mutable_position()->set_y(ui->height()-2.5);
  }


  mutable_velocity()->set_x(velocity().x() + accel.x());
  mutable_velocity()->set_y(velocity().y() + accel.y());
  mutable_position()->set_x(position().x() + velocity().x());
  mutable_position()->set_y(position().y() + velocity().y());

  if (shield <= 0) {
    die();
  }

}

void Ship::decrement_shield() {
  shield--;
}
void Ship::increment_shield() {
  shield++;
}

void Ship::die() {
  std::cout << "You died." << std::endl;
}

void Ship::win() {
  std::cout << "You won!" << std::endl;
}
