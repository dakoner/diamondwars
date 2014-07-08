#ifndef _ENV_H_
#define _ENV_H_

#include <iterator>
#include <vector>
#include "gfx.h"


#include "vec2.h"
#include "color.h"
#include "ship.h"
#include "enemy.h"
#include "world.h"
#include "star.h"
#include "bullet.h"
#include "input.h"

class Env {
 public:
  Env() {
    ship = new Ship(Vec2(gfx->width() / 2, gfx->height() / 2), constants->shipColor);
  
    enemy = new Enemy(Vec2(random(gfx->width()), random(gfx->height())), constants->enemyColor, Vec2(3, 2));
  
    world = new World(Vec2(0, 0), constants->worldColor);
  
    bullets.reserve(20);
    stars.reserve(constants->numStars);
  
    for (int i = 0; i < constants->numStars; ++i) {
      stars.push_back(Star(Vec2(random(gfx->width()), random(gfx->height())), constants->starColor));
    }
  }

  void loop() {
    gfx->clear();

#ifdef ARDUINO
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
#endif
    shootBullet();
    enemy->update(this);
    world->collide(enemy->position());
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
    
    gfx->draw();
  }

  void shootBullet() {

    if (bullets.size() < 20) {
      int buttonState = joystick->readButton(SWITCH_1);  // Esplora.readButton replaces digitalRead()
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
