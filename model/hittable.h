//
// Created by Matias Ignacio Levi Fernandez on 10/03/2021.
//

#ifndef RAYTRACER_HITTABLE_H
#define RAYTRACER_HITTABLE_H

#include "../utility/Vec3.h"
#include "../utility/Ray.h"
#include "../utility/defines.h"
#include "materials/material.h"
#include "hit_record.h"

#define DEFAULT_MATERIAL Lambertian

class Hittable {
public:
    shared_ptr<Material> material;

    Hittable()= default;

    explicit Hittable(shared_ptr<Material> &mat) : material(mat){};

    virtual bool Hit(const Ray& r, double t_min, double t_max, hit_record& rec) const = 0;
};


#endif //RAYTRACER_HITTABLE_H
