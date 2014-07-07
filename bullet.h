#ifndef _BULLET_H_
#define _BULLET_H_
#include "moving_object.h"
#include "killable.h"
#include "vec2.h"
#include "color.h"

class Bullet: public MovingObject, public Killable {
  public:
    Bullet(Vec2 position, Color color, Vec2 velocity = Vec2(4, 0)): MovingObject(position, color, velocity) {
    }

    void render() {
      int x = position().x();
      int y = position().y();
      EsploraTFT.rect(x - 1, y - 1, 2, 2);
    }

    void update() {
      mutable_position()->set_x(position().x() + velocity().x());

      if (position().x() > myWidth) {
        kill();
        // mark dead, remove from container
      }
    }
};

Ship *ship;
Enemy *enemy;
std::vector<Star> stars;
World *world;
std::vector<Bullet> bullets;


void shootBullet() {

  if (bullets.size() < 20) {

    int buttonState = Esplora.readButton(SWITCH_1);  // Esplora.readButton replaces digitalRead()
    if (buttonState == LOW) {
      Bullet b(Vec2(ship->position().x() + 6, ship->position().y()), bulletColor);
      bullets.push_back(b);
    }
  }
}

#endif
