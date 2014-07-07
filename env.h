#ifndef _ENV_H_
#define _ENV_H_

#include <iterator>
#include <vector>
#include <Arduino.h>

#include "vec2.h"
#include "color.h"
#include "ship.h"
#include "enemy.h"
#include "world.h"
#include "star.h"
#include "bullet.h"

class Env {
 public:
  Env() {
    ship = new Ship(Vec2(constants->myWidth / 2, constants->myHeight / 2), constants->shipColor);
  
    enemy = new Enemy(Vec2(random(constants->myWidth), random(constants->myHeight)), constants->enemyColor, Vec2(4, 4));
  
    world = new World(Vec2(0, 0), constants->worldColor);
  
    bullets.reserve(20);
    stars.reserve(constants->numStars);
  
    for (int i = 0; i < constants->numStars; ++i) {
      stars.push_back(Star(Vec2(random(constants->myWidth), random(constants->myHeight)), constants->starColor));
    }
  }

  void loop() {
    for (std::vector<Bullet>::iterator it = bullets.begin(); it != bullets.end(); ++it) {
      it->erase(this);
    }
    enemy->erase(this);
    ship->erase(this);
    for (std::vector<Star>::iterator it = stars.begin(); it != stars.end(); ++it) {
      it->erase(this);
    }
    world->erase(this);
  
    for (std::vector<Bullet>::iterator it = bullets.begin(); it != bullets.end();) {
      it->update(this);
      if(it->dead()) bullets.erase(it);
      else it++;
    }
  
    shootBullet();
    enemy->update(this);
    ship->update(this);
    for (std::vector<Star>::iterator it = stars.begin(); it != stars.end(); ++it) {
      it->update(this);
    }
    world->update(this);


    world->draw(this);
    for (std::vector<Star>::iterator it = stars.begin(); it != stars.end(); ++it) {
      it->draw(this);
    }
    ship->draw(this);
    enemy->draw(this);
    for (std::vector<Bullet>::iterator it = bullets.begin(); it != bullets.end(); ++it) {
      it->draw(this);
    }
  }

  void shootBullet() {

    if (bullets.size() < 20) {
      int buttonState = Esplora.readButton(SWITCH_1);  // Esplora.readButton replaces digitalRead()
      if (buttonState == LOW) {
      	Bullet b(Vec2(ship->position().x() + 6, ship->position().y()), constants->bulletColor);
      	bullets.push_back(b);
      }
    }
  }

  Ship *ship;
  Enemy *enemy;
  std::vector<Star> stars;
  World *world;
  std::vector<Bullet> bullets;
};

extern Env *env;

#endif
