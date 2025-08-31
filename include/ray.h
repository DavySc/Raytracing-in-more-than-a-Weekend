#ifndef RAY_H
#define RAY_H

#include "vec3.h"

struct Ray {
  Vec3 direction;
  Point3 origin;
};

Point3 ray_at(const Ray* r, double t) {
  return r->origin + t * r->direction;
}
#endif // !RAY_H
