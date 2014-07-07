#ifndef _COLLISION_H_
#define _COLLISION_H_

Vec2 closest_point_on_seg(Vec2 seg_a, Vec2 seg_b, Vec2 circ_pos);

Vec2 segment_circle(Vec2 seg_a, Vec2 seg_b, Vec2 circ_pos);

#endif

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
