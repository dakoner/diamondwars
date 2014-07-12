#include "env.h"
#include "joystick.h"

Env* env = NULL;


Env::Env() {
  ship = new Ship(Vec2(ui->width() / 2, ui->height() / 2), constants->shipColor);
  
  enemy = new Enemy(Vec2(120,60), constants->enemyColor, Vec2(0.1, 0.1));
  
  world = new World(Vec2(0, 0), constants->worldColor);
  
  bullets.reserve(20);
  stars.reserve(constants->numStars);
  
  for (int i = 0; i < constants->numStars; ++i) {
    int x= random(ui->width());
    int y= random(ui->height());
    std::cout << "x: " << x << " " << y << std::endl;
    stars.push_back(Star(Vec2(x, y), constants->starColor));
  }
}

void Env::loop() {
  ui->clear();

  #ifdef ARDUINO
    for (std::vector<Bullet>::iterator it = bullets.begin(); it != bullets.end(); ++it) {
      it->erase(this);
    }
    world->erase(this);
    enemy->erase(this);
  ship->erase(this);
  for (std::vector<Star>::iterator it = stars.begin(); it != stars.end(); ++it) {
    it->erase(this);
  }
  #endif
  
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


  ship->draw(this);
  enemy->draw(this);
  world->draw(this);
  for (std::vector<Star>::iterator it = stars.begin(); it != stars.end(); ++it) {
    it->draw(this);
  }
  for (std::vector<Bullet>::iterator it = bullets.begin(); it != bullets.end(); ++it) {
    it->draw(this);
  }
    
  ui->draw();
}

void Env::shootBullet() {

  if (bullets.size() < 20) {
    int buttonState = joystick->readButton(SWITCH_1);
    if (buttonState == PRESSED) {
      Bullet *b = new Bullet(Vec2(ship->position().x() + 6, ship->position().y()), constants->bulletColor);
      bullets.push_back(*b);
    }
  }
}

Enemy* Env::getEnemy() { return enemy; }
Ship* Env::getShip() { return ship; }
World* Env::getWorld() { return world; }
std::vector<Star>* Env::getStars() { return &stars; }
