#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <TFT.h>

#include "vec2.h"
#include "color.h"
#include "constants.h"

class Env;

class Object {
 public:
  Object() {
  }
 Object(Vec2 position, Color color): _position(position), _color(color) {
  }
  virtual void render(Env *env) = 0;
  virtual void update(Env *env) = 0;

  void erase(Env *env) {
    EsploraTFT.stroke(constants->backgroundColor.r(), constants->backgroundColor.g(), constants->backgroundColor.b());
    EsploraTFT.fill(constants->backgroundColor.r(), constants->backgroundColor.g(), constants->backgroundColor.b());
    render(env);
  }

  void draw(Env *env) {
    EsploraTFT.stroke(_color.r(), _color.g(), _color.b());
    EsploraTFT.fill(_color.r(), _color.g(), _color.b());
    render(env);
  }

  const Vec2& position() {
    return _position;
  }
    
  Vec2* mutable_position() {
    return &_position;
  }
    
 private:
  Vec2 _position;
  Color _color;
};

#endif
