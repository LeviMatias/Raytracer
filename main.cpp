#include <iostream>

#include "utility/safe_stream.h"
#include "utility/constants.h"
#include "utility/color_helper.h"

#include "model/Camera.h"
#include "model/Scene.h"



int main() {
    //image
    struct image img{};
    img.aspect_ratio = 16.0/9.0;
    img.w = 400;
    img.h = static_cast<int>(img.w / img.aspect_ratio);

    // World
    Scene world;
    world.add(make_shared<Sphere>(point3(0,0,-1), 0.5));
    world.add(make_shared<Sphere>(point3(0,-100.5,-1), 100));

    // Camera
    Camera cam(2.0, img.aspect_ratio, 1.0);
    SafeStream out;
    out.OpenWrite("image.ppm");

    //add image header
    out << "P3\n" << img.w << ' ' << img.h << "\n255\n";;

    for (int j = img.h-1; j >= 0; j--){
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < img.w; i++){
            double u = double(i) / (img.w-1);
            double v = double(j) / (img.h-1);
            ray r = cam.ray_to(u, v);

            color pixel_color = ray_color(r, world);
            write_color(out, pixel_color);
        }
    }
    std::cerr << "\nDone.\n";
    return 0;
}
