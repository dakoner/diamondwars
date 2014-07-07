#ifndef _SHIP_H_
#define _SHIP_H_

#include "moving_object.h"
#include "vec2.h"
#include "color.h"

class Ship: public MovingObject {
  public:
    Ship(Vec2 position, Color color, Vec2 velocity = Vec2(0, 0)): MovingObject(position, color, velocity) {
    }

    void render() {
      int x = position().x();
      int y = position().y();
      EsploraTFT.rect(x, y, 2, 3);
      EsploraTFT.rect(x + 2, y, 2, 2);
      EsploraTFT.rect(x + 4, y, 2, 1);
      EsploraTFT.rect(x + 4, y - 1, 1, 1);
    }


    void update() {
      Vec2 accel(map(Esplora.readJoystickX(), 512, -512, -2, 2),
                 map(Esplora.readJoystickY(), -512, 512, -2, 2));

      mutable_velocity()->set_x(velocity().x() + accel.x());
      mutable_velocity()->set_y(velocity().y() + accel.y());

      if (velocity().x() > 3)
        mutable_velocity()->set_x(3);

      if (velocity().y() > 3)
        mutable_velocity()->set_y(3);

      mutable_position()->set_x(position().x() + velocity().x());
      mutable_position()->set_y(position().y() + velocity().y());

      if (position().x() < 0)
        mutable_position()->set_x(0);

      if (position().x() > myWidth)
        mutable_position()->set_x(myWidth);

      if (position().y() < 0)
        mutable_position()->set_y(0);

      if (position().y() > myHeight)
        mutable_position()->set_y(myHeight);
    }
};

#endif
