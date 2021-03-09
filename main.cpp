#include <iostream>
#include "utility/safe_stream.h"
#include "utility/vec3.h"
#include "utility/color_helper.h"
#include "utility/ray.h"



int main() {
    const int img_w = 256;
    const int img_h = 256;

    //add image header
    SafeStream out;
    out.OpenWrite("image.ppm");

    out << "P3\n" << img_w << ' ' << img_h << "\n255\n";;

    for (short int j = img_h-1; j >= 0; j--){
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (short int i = 0; i < img_w; i++){
            color pixel_color(double(i) / (img_w - 1), double(j) / (img_h - 1), 0.25);
            write_color(out, pixel_color);
        }
    }

    return 0;
}
