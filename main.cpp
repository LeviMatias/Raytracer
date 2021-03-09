#include <iostream>
#include "utility/safe_stream.h"
#include "utility/vec3.h"
#include "utility/color_helper.h"
#include "utility/ray.h"



int main() {
    //image
    const auto aspect_ratio = 16.0 / 9.0;
    const int img_w = 400;
    const int img_h = static_cast<int>(img_w / aspect_ratio);

    // Camera
    auto viewport_height = 2.0;
    auto viewport_width = aspect_ratio * viewport_height;
    auto focal_length = 1.0;

    auto origin = point3(0, 0, 0);
    auto horizontal = vec3(viewport_width, 0, 0);
    auto vertical = vec3(0, viewport_height, 0);
    auto lower_left_corner = origin - horizontal/2 - vertical/2 - vec3(0, 0, focal_length);

    SafeStream out;
    out.OpenWrite("image.ppm");

    //add image header
    out << "P3\n" << img_w << ' ' << img_h << "\n255\n";;

    for (short int j = img_h-1; j >= 0; j--){
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (short int i = 0; i < img_w; i++){
            auto u = double(i) / (img_w-1);
            auto v = double(j) / (img_h-1);
            ray r(origin, lower_left_corner + u*horizontal + v*vertical - origin);

            color pixel_color = ray_color(r);
            write_color(out, pixel_color);
        }
    }
    std::cerr << "\nDone.\n";
    return 0;
}
