#include "env.h"
#include "constants.h"
#include "joystick.h"

Env* env = NULL;


Env::Env() {
  ship = new Ship(Vec2(ui->width() / 2, ui->height() / 2), constants->shipColor, Vec2(0.1, 0.1));
  
  enemy = new Enemy(Vec2(120,60), constants->enemyColor, Vec2(0.1, 0.1));
  
  world = new World(Vec2(0, 0), constants->worldColor, Vec2(0.05, 0));
  
  bullets.reserve(20);
  stars.reserve(constants->numStars);
  
  for (int i = 0; i < constants->numStars; ++i) {
    int x= random(ui->width());
    int y= random(ui->height());
    stars.push_back(Star(Vec2(x, y), constants->starColor));
  }

  for (int i = 0; i < constants->numDiamonds; ++i) {
    int x= random(SPACING*NUM_HEIGHTS);
    int y= random(ui->height());
    diamonds.push_back(Diamond(Vec2(x, y), constants->diamondColor));
  }
}

void Env::erase() {
  ui->clear();
  for (std::vector<Bullet>::iterator it = bullets.begin(); it != bullets.end(); ++it) {
    it->erase(this);
  }
  world->erase(this);
    enemy->erase(this);
  ship->erase(this);
  for (std::vector<Star>::iterator it = stars.begin(); it != stars.end(); ++it) {
    it->erase(this);
  }
  for (std::vector<Diamond>::iterator it = diamonds.begin(); it != diamonds.end(); ++it) {
    it->erase(this);
  }
}

void Env::update() {
  for (std::vector<Bullet>::iterator it = bullets.begin(); it != bullets.end();) {
    it->update(this);
    if(it->dead()) bullets.erase(it); 
    else it++;
  }
  shootBullet();
  world->update(this);
  enemy->update(this);

  ship->update(this);
  for (std::vector<Star>::iterator it = stars.begin(); it != stars.end(); ++it) {
    it->update(this);
  }
  for (std::vector<Diamond>::iterator it = diamonds.begin(); it != diamonds.end(); ++it) {
    it->update(this);
  }
}

void Env::draw() {
  ship->draw(this);
  enemy->draw(this);
  world->draw(this);
  for (std::vector<Star>::iterator it = stars.begin(); it != stars.end(); ++it) {
    it->draw(this);
  }
  for (std::vector<Diamond>::iterator it = diamonds.begin(); it != diamonds.end(); ++it) {
    it->draw(this);
  }
  for (std::vector<Bullet>::iterator it = bullets.begin(); it != bullets.end(); ++it) {
    it->draw(this);
  }
  ui->draw();
}

void Env::loop() {
  #ifdef ARDUINO
  erase();
  #endif
  update();
  draw();
}

void Env::shootBullet() {
  if (bullets.size() < 20) {
    int buttonState = joystick->readButton(SWITCH_1);
    if (buttonState == PRESSED) {
      Vec2 p;
      Vec2 v;
      if (ship->velocity().x() < 0) {
	p.set_x(ship->position().x() - 6);
	p.set_y(ship->position().y());
	v.set_x(ship->position().x() - 4);
	v.set_y(ship->position().y());
      } else {
	p.set_x(ship->position().x() + 6);
	p.set_y(ship->position().y());
	v.set_x(ship->position().x() + 4);
	v.set_y(ship->position().y());
      }

      Bullet *b = new Bullet(p, constants->bulletColor, v);
      bullets.push_back(*b);
    }
  }
}

Enemy* Env::getEnemy() { return enemy; }
Ship* Env::getShip() { return ship; }
World* Env::getWorld() { return world; }
std::vector<Star>* Env::getStars() { return &stars; }
std::vector<Diamond>* Env::getDiamonds() { return &diamonds; }
