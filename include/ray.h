#ifndef RAY_H
#define RAY_H

#include "vec3.h"

struct ray {
  vec3 direction;
  point3 origin;
};

point3 ray_at(const ray* r, double t) {
  return r->origin + t * r->direction;
}
#endif // !RAY_H
