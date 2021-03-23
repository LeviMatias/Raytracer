//
// Created by Matias Ignacio Levi Fernandez on 23/03/2021.
//

#ifndef RAYTRACER_HIT_RECORD_H
#define RAYTRACER_HIT_RECORD_H

#include "../utility/Ray.h"
class Hittable;

struct hit_record {
    Point3 p;
    Vec3 normal;
    // ray = origin + direction * t
    // t record the t-value for the hit_record
    double t{};
    bool front_face;
    Hittable* hit = nullptr;

    inline void set_face_normal(const Ray& r, const Vec3& outward_normal) {
        front_face = r.direction.dot(outward_normal) < 0;
        //Hit normal always points contrary to ray
        normal = front_face ? outward_normal :-outward_normal;
    }
};


#endif //RAYTRACER_HIT_RECORD_H
