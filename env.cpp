#include "env.h"

Env* env = NULL;


Env::Env() {
  ship = new Ship(Vec2(gfx->width() / 2, gfx->height() / 2), constants->shipColor);
  
  enemy = new Enemy(Vec2(random(gfx->width()), random(gfx->height())), constants->enemyColor, Vec2(3, 2));
  
  world = new World(Vec2(0, 0), constants->worldColor);
  
  bullets.reserve(20);
  stars.reserve(constants->numStars);
  
  for (int i = 0; i < constants->numStars; ++i) {
    stars.push_back(Star(Vec2(random(gfx->width()), random(gfx->height())), constants->starColor));
  }
}

void Env::loop() {
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
#endif
  
  for (std::vector<Bullet>::iterator it = bullets.begin(); it != bullets.end();) {
    it->update(this);
    if(it->dead()) bullets.erase(it); 
    else it++;
  }
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

void Env::shootBullet() {

  if (bullets.size() < 20) {
    int buttonState = joystick->readButton(SWITCH_1);
    if (buttonState == LOW) {
      Bullet *b = new Bullet(Vec2(ship->position().x() + 6, ship->position().y()), constants->bulletColor);
      bullets.push_back(*b);
    }
  }
}
