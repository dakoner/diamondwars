#include "vec2.h"

Vec2 closest_point_on_seg(Vec2 seg_a, Vec2 seg_b, Vec2 circ_pos) {
  Vec2 seg_v = seg_b - seg_a;
  Vec2 pt_v = circ_pos - seg_a;
  if (seg_v.length() <= 0) return Vec2(0, 0);
  Vec2 seg_v_unit = seg_v;
  seg_v_unit.normalize();
  float proj = pt_v.dot(seg_v_unit);
  if (proj <= 0) return seg_a;
  if (proj >= seg_v.length()) return seg_b;
  Vec2 proj_v = seg_v_unit * proj;
  Vec2 closest = proj_v + seg_a;
  return closest;
}

Vec2 segment_circle(Vec2 seg_a, Vec2 seg_b, Vec2 circ_pos) {
  int circ_rad = 5;
  Vec2 closest = closest_point_on_seg(seg_a, seg_b, circ_pos);
  Vec2 dist_v = circ_pos - closest;
  if (dist_v.length() > circ_rad) return Vec2(0, 0);
  if (dist_v.length() <= 0) return Vec2(0, 0);
  Vec2 offset = dist_v;
  offset.normalize();
  offset = offset * (circ_rad - dist_v.length());
  return offset;
}

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
