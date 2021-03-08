#include <iostream>
#include "utility/safe_stream.h"

int main() {
    const int img_w = 256;
    const int img_h = 256;

    //add image header
    SafeStream out;
    out.OpenWrite("image.ppm");

    out << "P3\n" << img_w << ' ' << img_h << "\n255\n";;

    for (short int j = img_h-1; j >= 0; j--){
        for (short int i = 0; i < img_w; i++){
            double r = double(i) / (img_w - 1);
            double g = double(j) / (img_h - 1);
            double b = 0.25;

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            out << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }

    return 0;
}
