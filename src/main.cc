#include "color.h"
#include "core.h"
#include "ray.h"
#include "vec3.h"
#include <iostream>

Color ray_color(const Ray &r) {
  Vec3 unit_direction = unit_vector(r);
  return Color(0, 0, 0);
}

int main () {
  U32 image_width {400};
  F32 aspect_ratio = 16.0/9.0;

  // Calculate the image height and ensure it is at least 1
  U32 image_height = U32(image_width/aspect_ratio);
  image_height = (image_height < 1) ? 1 : image_height;


  F32 focal_length = 1.0;
  F32 viewport_height = 2.0;
  F32 viewport_width = viewport_height * (F32(image_width)/image_height);
  Point3 camera_center = Point3(0,0,0);

  Vec3 viewport_u = Vec3(viewport_width, 0, 0);
  Vec3 viewport_v = Vec3(0, -viewport_height, 0);

  // Pixel deltas are normalized viewport vectors
  Vec3 pixel_delta_u = viewport_u/viewport_width; 
  Vec3 pixel_delta_v = viewport_v/viewport_height;

  Vec3 viewport_upper_left = camera_center - Vec3(0, 0, focal_length) - (0.5 * (viewport_u + viewport_v));
  Vec3 pixel00_location = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

  std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
 
  for (U32 j = 0; j < image_height; j++) {
    for (U32 i = 0; i < image_width; i++) {
      Point3 pixel_center = pixel00_location + (i * pixel_delta_u) + (j * pixel_delta_v);
      Vec3 ray_direction = pixel_center - camera_center;
      Ray r(camera_center, ray_direction);
      Color pixel_color = ray_color(r);
      write_color(std::cout, pixel_color);
    }
  }
  return 0;
}
