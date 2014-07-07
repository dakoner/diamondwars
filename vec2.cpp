#include <math.h>
#include "vec2.h"

Vec2::Vec2()
{
  _x = 0;
  _y = 0;
}

Vec2::Vec2(const Vec2 &v) {
  _x = v.x();
  _y = v.y();
}

Vec2::Vec2( const float x, const float y )
{
  _x = x;
  _y = y;
}

float Vec2::x() const {
  return _x;
}

float Vec2::y() const {
  return _y;
}

void Vec2::set_x(const float x) {
  _x = x;
}

void Vec2::set_y(const float y) {
  _y = y;
}

void Vec2::set( const float x, const float y )
{
  _x = x;
  _y = y;
}

Vec2 Vec2::operator+( const Vec2 &v ) const
{
  return Vec2( this->_x + v._x, this->_y + v._y );
}

Vec2 Vec2::operator-( const Vec2 &v ) const
{
  return Vec2( this->_x - v._x, this->_y - v._y );
}

Vec2 Vec2::operator*( const float f ) const
{
  return Vec2( this->_x * f, this->_y * f );
}

float Vec2::DistanceToSquared( const Vec2 p ) const
{
  const float dX = p._x - this->_x;
  const float dY = p._y - this->_y;

  return dX * dX + dY * dY;
}

float Vec2::DistanceTo( const Vec2 p ) const
{
  return sqrt( this->DistanceToSquared( p ) );
}

float Vec2::DotProduct( const Vec2 p ) const
{
  return this->_x * p._x + this->_y * p._y;
}

Vec2 Vec2::normal() {
  Vec2 tmp(-_y, _x);
  return tmp;
}
void Vec2::normalize() {
  float f = sqrt(_x * _x + _y * _y);
  _y = _y/f;
  _x = _x/f;
}


// return minimum distance between line segment vw and point p, and the closest point on the line segment, q
float DistanceFromLineSegmentToPoint( const class Vec2 v, const class Vec2 w, const class Vec2 p, class Vec2 * const q )
{
  const float distSq = v.DistanceToSquared( w ); // i.e. |w-v|^2 ... avoid a sqrt
  if ( distSq == 0.0 )
    {
      // v == w case
      (*q) = v;

      return v.DistanceTo( p );
    }

  // consider the line extending the segment, parameterized as v + t (w - v)
  // we find projection of point p onto the line
  // it falls where t = [(p-v) . (w-v)] / |w-v|^2

  const float t = ( p - v ).DotProduct( w - v ) / distSq;
  if ( t < 0.0 )
    {
      // beyond the v end of the segment
      (*q) = v;

      return v.DistanceTo( p );
    }
  else if ( t > 1.0 )
    {
      // beyond the w end of the segment
      (*q) = w;

      return w.DistanceTo( p );
    }

  // projection falls on the segment
  const Vec2 projection = v + ( ( w - v ) * t );

  (*q) = projection;

  return p.DistanceTo( projection );
}
