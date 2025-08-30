#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

#include <iostream>
#include <iterator>

using Color = Vec3;
void write_color(std::ostream& out, const Color& pixel_color) {
  auto red = pixel_color.x();
  auto green = pixel_color.y();
  auto blue = pixel_color.z();
  
  int redbyte = int(255.999 * red);
  int greenbyte = int(255.999 * green);
  int bluebyte = int(255.999 * blue);
  
  out << redbyte << ' ' << greenbyte << ' ' << bluebyte << '\n';
}

#endif 
