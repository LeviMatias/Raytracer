//
// Created by Matias Ignacio Levi Fernandez on 10/03/2021.
//

#ifndef RAYTRACER_HITTABLE_H
#define RAYTRACER_HITTABLE_H

#include "../utility/vec3.h"
#include "../utility/ray.h"

struct hit_record {
    point3 p;
    vec3 normal;
    double t{};
};

class Hittable {
public:
    virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const = 0;
};


#endif //RAYTRACER_HITTABLE_H
