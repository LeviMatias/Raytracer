#include <iostream>

#include "model/concurrency/safe_stream.h"
#include "utility/defines.h"

#include "model/camera.h"
#include "model/scene.h"
#include "model/image.h"
#include "utility/stopwatch.h"
#include "model/materials/lambertian.h"
#include "model/materials/reflective.h"
#include "model/materials/grass.h"
#include "model/materials/dielectric.h"

int main() {
    Stopwatch t;
    t.reset();

    //image
    Image img;

    // World
    Scene world;

    auto R = cos(PI/4);

    auto material_left  = make_shared<Lambertian>(Color(0,0,1));
    auto material_right = make_shared<Lambertian>(Color(1,0,0));

    world.add(make_shared<Sphere>(material_left, Point3(-R, 0, -1), R));
    world.add(make_shared<Sphere>(material_right, Point3( R, 0, -1), R));

    // Camera
    Camera cam(90.0, img.aspect_ratio, 1.0);

    cam.Draw(world, img);

    img.Save();

    std::cerr << "\nDone in " << t.diff() << " seconds"<<std::flush;

    return 0;
}
