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
    // ray = orig + dir * t
    // t record the t-value for the hit_record
    double t{};
    bool front_face;

    inline void set_face_normal(const ray& r, const vec3& outward_normal) {
        front_face = r.direction().dot(outward_normal) < 0;
        //hit normal always points contrary to ray
        normal = front_face ? outward_normal :-outward_normal;
    }
};

class Hittable {
public:
    virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const = 0;
};


#endif //RAYTRACER_HITTABLE_H
