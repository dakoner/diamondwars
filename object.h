#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "vec2.h"
#include "color.h"
#include "constants.h"
#include "ui.h"

class Env;

class Object {
 public:
  Object() {
  }
 Object(Vec2 position, Color color, int size=1): _position(position), _color(color), _size(size) {
  }
  virtual void render(Env *env) = 0;
  virtual void update(Env *env) = 0;

  void erase(Env *env) {
    ui->stroke(constants->backgroundColor.r(), constants->backgroundColor.g(), constants->backgroundColor.b());
    ui->fill(constants->backgroundColor.r(), constants->backgroundColor.g(), constants->backgroundColor.b());
    render(env);
  }

  void draw(Env *env) {
    ui->stroke(_color.r(), _color.g(), _color.b());
    ui->fill(_color.r(), _color.g(), _color.b());
    render(env);
  }

  const Vec2& position() {
    return _position;
  }
    
  Vec2* mutable_position() {
    return &_position;
  }

  int size() {
    return _size;
  }
    
 private:
  Vec2 _position;
  Color _color;
  int _size;
};

#endif
