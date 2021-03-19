#include <iostream>

#include "utility/safe_stream.h"
#include "utility/Utility.h"

#include "model/Camera.h"
#include "model/Scene.h"
#include "model/Image.h"
#include "utility/stopwatch.h"

int main() {
    Stopwatch t;
    t.reset();

    //image
    Image img;

    // World
    Scene world;
    world.add(make_shared<Sphere>(Point3(0, 0, -1), 0.5));
    world.add(make_shared<Sphere>(Point3(0, -100.5, -1), 100));

    // Camera
    Camera cam(2.0, img.aspect_ratio, 1.0);

    cam.Draw(world, img);

    img.Save();

    std::cerr << "\nDone in " << t.diff() << " seconds"<<std::flush;

    return 0;
}
