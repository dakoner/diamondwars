#include "vec2.h"

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

  const float t = ( p - v ).dot( w - v ) / distSq;
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

