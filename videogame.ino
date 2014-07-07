#include <stdio.h>
#include <math.h>
#include <iterator>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <Esplora.h>
#include <TFT.h>            // Arduino LCD library
#include <SPI.h>
#include <pnew.cpp>


#include "vec2.h"
#include "color.h"
#include "ship.h"
#include "enemy.h"
#include "world.h"
#include "star.h"
#include "bullet.h"

Color backgroundColor(0, 0, 0);

Color shipColor(255, 0, 0);

Color enemyColor(0, 0, 255);

Color worldColor(255, 255, 255);

Color starColor(127, 127, 0);

Color bulletColor(0, 255, 0);

int myWidth = 0;
int myHeight = 0;

int numStars = 30;
int starSpeed = 4;

// 16 items with width 20
int st[16] = {10, 10, 10, 10, 10, 30, 10, 10, 10, 10, 10, 30, 10, 10, 60, 10};
std::vector<int> stalagtites(&st[0], &st[0] + 16);


// 16 items with width 20
int sm[16] = {10, 10, 30, 10, 10, 60, 10, 10, 10, 30, 10, 10, 10, 10, 10, 10};
std::vector<int> stalagmites(&sm[0], &sm[0] + 16);



// Vec2 q;
// for (int i = 0; i < stalagtites.size() - 1; ++i) {
//   Vec2 v(i * 20 + position().x(), stalagtites[i]);
//   Vec2 w((i + 1) * 20 + position().x(), stalagtites[i + 1]);
//   float d = DistanceFromLineSegmentToPoint(v, w, enemy, &q);
//   if (d < 50) {
//     Vec2 tmp(w-v);
//     Vec2 n(tmp.normal());
//     n.normalize();
//     EsploraTFT.stroke(255, 0, 0);

//     EsploraTFT.line(q.x(), q.y(), q.x() + n.x() * 10, q.y() + n.y() * 10);
//     EsploraTFT.stroke(0, 255, 0);

//     EsploraTFT.line(enemy.x(), enemy.y(), q.x(), q.y());
//   }
//  }

/*
   Vec2 tmp(w-v);
   Vec2 n(tmp.normal());

   float x = v.x() + tmp.x()/2.;
   float y = v.y() + tmp.y()/2.;
   float nx = x + n.x();
   float ny = y + n.y();
   EsploraTFT.line(x + position().x(), y , nx + position().x(), ny);
*/

void setup() {
  myWidth = EsploraTFT.width();
  myHeight = EsploraTFT.height();

  ship = new Ship(Vec2(myWidth / 2, myHeight / 2), shipColor);
  
  enemy = new Enemy(Vec2(random(160), random(128)), enemyColor, Vec2(random(-2, 2), random(-2, 2)));
  
  world = new World(Vec2(0, 0), worldColor);
  
  bullets.reserve(20);
  stars.reserve(numStars);
  
  for (int i = 0; i < numStars; ++i) {
    stars.push_back(Star(Vec2(random(myWidth), random(myHeight)), starColor));
  }

  // initialize the display
  EsploraTFT.begin();
  // set the background.  Should be something like "background.setBackground()"

  EsploraTFT.background(backgroundColor.r(), backgroundColor.g(), backgroundColor.b());
}


void loop() {

  for (std::vector<Bullet>::iterator it = bullets.begin(); it != bullets.end(); ++it) {
    it->erase();
  }
  enemy->erase();
  ship->erase();
  for (std::vector<Star>::iterator it = stars.begin(); it != stars.end(); ++it) {
    it->erase();
  }
  world->erase();
  
  for (std::vector<Bullet>::iterator it = bullets.begin(); it != bullets.end();) {
    it->update();
    if(it->dead()) bullets.erase(it);
    else it++;
  }
  
  shootBullet();
  enemy->update();
  ship->update();
  for (std::vector<Star>::iterator it = stars.begin(); it != stars.end(); ++it) {
    it->update();
  }
  world->update();


  world->draw();
  for (std::vector<Star>::iterator it = stars.begin(); it != stars.end(); ++it) {
    it->draw();
  }
  ship->draw();
  enemy->draw();
  for (std::vector<Bullet>::iterator it = bullets.begin(); it != bullets.end(); ++it) {
    it->draw();
  }
  delay(50);
}
