//
// Created by Matias Ignacio Levi Fernandez on 10/03/2021.
//

#ifndef RAYTRACER_HITTABLE_H
#define RAYTRACER_HITTABLE_H

#include "../../utility/vec3.h"
#include "../../utility/ray.h"
#include "../../utility/math_macros.h"
#include "../materials/material.h"
#include "hit_record.h"
#include "aabb.h"

#define DEFAULT_MATERIAL Lambertian

class Hittable {
public:
    shared_ptr<Material> material;
    AABB bounding_box;

    Hittable()= default;

    explicit Hittable(shared_ptr<Material> &mat) : material(mat){};

    Hittable(shared_ptr<Material> &mat, Point3 &n, Point3 &f) : material(mat), bounding_box(n, f){};

    virtual bool Hit(const Ray& r, double t_min, double t_max, hit_record& rec) const = 0;
};


#endif //RAYTRACER_HITTABLE_H
