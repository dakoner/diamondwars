#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "vec2.h"
#include "color.h"

class Object {
  public:
    Object() {
    }
    Object(Vec2 position, Color color): _position(position), _color(color) {
    }
    virtual void render() = 0;
    virtual void update() = 0;

    void erase() {
      EsploraTFT.stroke(backgroundColor.r(), backgroundColor.g(), backgroundColor.b());
      EsploraTFT.fill(backgroundColor.r(), backgroundColor.g(), backgroundColor.b());
      render();
    }

    void draw() {
      EsploraTFT.stroke(_color.r(), _color.g(), _color.b());
      EsploraTFT.fill(_color.r(), _color.g(), _color.b());
      render();
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
