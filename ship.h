#ifndef _SHIP_H_
#define _SHIP_H_

#include <iostream>
#include "vec2.h"
#include "color.h"
#include "constants.h"
#include "moving_object.h"

#include "ui.h"

#ifdef ARDUINO
#include <Arduino.h>
#endif

class Env;

class Ship: public MovingObject {
  public:
    Ship(Vec2 position, Color color, Vec2 velocity = Vec2(0, 0)): MovingObject(position, color, velocity) {
    }

    void render(Env *env) {
      int x = position().x();
      int y = position().y();
      ui->rect(x, y, 2, 3);
      ui->rect(x + 2, y, 2, 2);
      ui->rect(x + 4, y, 2, 1);
      ui->rect(x + 4, y - 1, 1, 1);
    }


    void update(Env *env) {
      Vec2 accel(ui->readJoystickX(),
                 ui->readJoystickY());

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

      if (position().x() < 0)
        mutable_position()->set_x(0);

      if (position().x() > ui->width()-5)
        mutable_position()->set_x(ui->width()-5);

      if (position().y() < 0)
        mutable_position()->set_y(0);

      if (position().y() > ui->height()-5)
        mutable_position()->set_y(ui->height()-5);

      std::cout << "A: " << accel.x() << " " << accel.x() << std::endl;
      /* std::cout << "V: " << velocity().x() << " " << velocity().x() << std::endl; */
      /* std::cout << "P: " << position().x() << " " << position().x() << std::endl; */
      /* mutable_velocity()->set_x(velocity().x() + accel.x()); */
      /* mutable_velocity()->set_y(velocity().y() + accel.y()); */
      /* mutable_position()->set_x(position().x() + velocity().x()); */
      /* mutable_position()->set_y(position().y() + velocity().y()); */
    }
};

#endif
