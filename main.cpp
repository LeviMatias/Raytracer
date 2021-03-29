#include <iostream>

#include "utility/safe_stream.h"
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

    auto material_ground = make_shared<Grass>(Color(0.8, 0.8, 0.0));
    auto material_center = make_shared<Lambertian>(Color(0.7, 0.3, 0.3));
    auto material_left   = make_shared<Metal>(Color(0.8, 0.8, 0.8), 0.75);
    auto material_right  = make_shared<Glass>( 1.5);

    world.add(make_shared<Sphere>(material_ground, Point3( 0.0, -100.5, -1.0), 100.0));
    world.add(make_shared<Sphere>(material_center, Point3( 0.0,    0.0, -1.0),   0.5));
    world.add(make_shared<Sphere>(material_left, Point3(-1.0,    0.0, -1.0),   0.5));
    world.add(make_shared<Sphere>(material_right, Point3( 1.0,    0.0, -1.0),   -0.4));

    // Camera
    Camera cam(2.0, img.aspect_ratio, 1.0);

    cam.Draw(world, img);

    img.Save();

    std::cerr << "\nDone in " << t.diff() << " seconds"<<std::flush;

    return 0;
}
