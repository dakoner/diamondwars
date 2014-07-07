#ifndef _MOVING_OBJECT_H_
#define _MOVING_OBJECT_H_

#include "object.h"

class MovingObject: public Object {
  public:
    MovingObject(Vec2 position, Color color, Vec2 velocity): Object(position, color), _velocity(velocity) {
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
