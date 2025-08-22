#include "color.h"
void write_color(std::ostream& out, const color& pixel_color) {
    auto red = pixel_color.x();
    auto green = pixel_color.y();
    auto blue = pixel_color.z();

    int redbyte = int(255.999 * red);
    int greenbyte = int(255.999 * green);
    int bluebyte = int(255.999 * blue);

    out << redbyte << ' ' << greenbyte << ' ' << bluebyte << '\n';
}
