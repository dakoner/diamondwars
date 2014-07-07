#ifndef _VEC2_H_
#define _VEC2_H_
#include <math.h>

class Vec2
{
 public:
  float _x;
  float _y;

  Vec2()
    {
      _x = 0;
      _y = 0;
    }

  Vec2(const Vec2 &v) {
    _x = v.x();
    _y = v.y();
  }

  Vec2( const float x, const float y )
    {
      _x = x;
      _y = y;
    }

  float x() const {
    return _x;
  }

  float y() const {
    return _y;
  }

  void set_x(const float x) {
    _x = x;
  }

  void set_y(const float y) {
    _y = y;
  }

  void set( const float x, const float y )
  {
    _x = x;
    _y = y;
  }

  Vec2 operator+( const Vec2 &v ) const
  {
    return Vec2( this->_x + v._x, this->_y + v._y );
  }

  Vec2 operator-( const Vec2 &v ) const
  {
    return Vec2( this->_x - v._x, this->_y - v._y );
  }

  Vec2 operator*( const float f ) const
    {
      return Vec2( this->_x * f, this->_y * f );
    }

  float DistanceToSquared( const Vec2 p ) const
  {
    const float dX = p._x - this->_x;
    const float dY = p._y - this->_y;

    return dX * dX + dY * dY;
  }

  float DistanceTo( const Vec2 p ) const
  {
    return sqrt( this->DistanceToSquared( p ) );
  }

  float dot( const Vec2 p ) const
  {
    return this->_x * p._x + this->_y * p._y;
  }

  float length() {
    return sqrt(_x * _x + _y * _y);
  }

  Vec2 normal() {
    Vec2 tmp(-_y, _x);
    return tmp;
  }
  void normalize() {
    float f = length();
    _y = _y/f;
    _x = _x/f;
  }
};


// return minimum distance between line segment vw and point p, and the closest point on the line segment, q
float DistanceFromLineSegmentToPoint( const class Vec2 v, const class Vec2 w, const class Vec2 p, class Vec2 * const q );
#endif
