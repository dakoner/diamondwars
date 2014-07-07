#ifndef _VEC2_H_
#define _VEC2_H_
class Vec2
{
  public:
    float _x;
    float _y;

    Vec2();

    Vec2(const Vec2 &v);

    Vec2( const float x, const float y );

    float x() const;

    float y() const;

    void set_x(const float x);

    void set_y(const float y);

    void set( const float x, const float y );

    Vec2 operator+( const Vec2 &v ) const;

    Vec2 operator-( const Vec2 &v ) const;

    Vec2 operator*( const float f ) const;

    float DistanceToSquared( const Vec2 p ) const;

    float DistanceTo( const Vec2 p ) const;

    float DotProduct( const Vec2 p ) const;

    Vec2 normal();
    void normalize() ;
};

// return minimum distance between line segment vw and point p, and the closest point on the line segment, q
float DistanceFromLineSegmentToPoint( const class Vec2 v, const class Vec2 w, const class Vec2 p, class Vec2 * const q );
#endif
