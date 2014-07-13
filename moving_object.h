#ifndef _MOVING_OBJECT_H_
#define _MOVING_OBJECT_H_

#include "object.h"
#include "vec2.h"
#include "color.h"

class MovingObject: public Object {
public:
  MovingObject(Vec2 position, Color color, Vec2 velocity, int size): Object(position, color, size), _velocity(velocity) {
  }
  void render(Env *env) {
  }
  void update(Env *env) {
    mutable_position()->set_x(position().x() + velocity().x());
    mutable_position()->set_y(position().y() + velocity().y());
  }

  const Vec2& velocity() {
    return _velocity;
  }
  Vec2* mutable_velocity() {
    return &_velocity;
  }
private:
  Vec2 _velocity;
};

#endif
