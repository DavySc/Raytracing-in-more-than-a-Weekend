#include <iostream>

int main () {

    int image_width {256};
    int image_height {256};

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
	for (int i = 0; i < image_width; i++) {
	    auto red = double(i)/(image_width-1);
	    auto green = double(j)/(image_height-1);
	    auto blue = 0.0;


	    int integer_red = int(255.999 * red);
	    int integer_green = int(255.999 * green);
	    int integer_blue = int(255.999 * blue);
	
            std::cout << integer_red << ' ' << integer_green << ' ' << integer_blue << '\n';
	}
    
    }
	return 0;
}
