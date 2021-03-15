//
// Created by Matias Ignacio Levi Fernandez on 09/03/2021.
//

#ifndef RAYTRACER_COLOR3_H
#define RAYTRACER_COLOR3_H

#include "../model/Hittable.h"
#include "safe_stream.h"
#include "Utility.h"

#define LIGHT_BLUE Color(0.5, 0.7, 1.0)
#define WHITE Color(1.0, 1.0, 1.0)
#define MAX_DEPTH 25

Color ray_color(const Ray& r, const Hittable& world, int bounce) {
    if (bounce >= MAX_DEPTH ) return {};

    hit_record rec;
    if (world.hit(r, 0, INF, rec)) {
        double x = Random::NextNumber(-1,1);
        double s = cos((PI/2) * x);
        double y = Random::NextNumber(-s, s);
        double eq = sqrt(1 - x*x - y*y);
        double z = Random::NextNumber(-eq, eq);

        Point3 target = rec.p + rec.normal + Vec3(x, y, z);
        return 0.50 * ray_color(Ray(rec.p, target - rec.p), world, ++bounce);
    }
    Vec3 unit_direction = r.direction.unit();
    auto t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t) * WHITE + t * LIGHT_BLUE;
}

Color ray_color(const Ray& r, const Hittable& world){
    return ray_color(r, world, 0);
}


#endif
