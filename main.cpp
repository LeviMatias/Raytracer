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

    auto material_ground = make_shared<Lambertian>(Color(0.8, 0.8, 0.0));
    auto material_center = make_shared<Lambertian>(Color(0.1, 0.2, 0.5));
    auto material_left   = make_shared<Dielectric>(1.5);
    auto material_right  = make_shared<Metal>(Color(0.8, 0.6, 0.2), 0.0);

    world.add(make_shared<Sphere>(Point3( 0.0, -100.5, -1.0), 100.0, material_ground));
    world.add(make_shared<Sphere>(Point3( 0.0,    0.0, -1.0),   0.5, material_center));
    world.add(make_shared<Sphere>(Point3(-1.0,    0.0, -1.0),   0.5, material_left));
    world.add(make_shared<Sphere>(Point3(-1.0,    0.0, -1.0), -0.45, material_left));
    world.add(make_shared<Sphere>(Point3( 1.0,    0.0, -1.0),   0.5, material_right));

    //camera
    Camera cam(Point3(-2,2,1), Point3(0,0,-1), 90, img.aspect_ratio);

    cam.Draw(world, img);

    img.Save();

    std::cerr << "\nDone in " << t.diff() << " seconds"<<std::flush;

    return 0;
}
