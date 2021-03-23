//
// Created by Matias Ignacio Levi Fernandez on 10/03/2021.
//

#ifndef RAYTRACER_HITTABLE_H
#define RAYTRACER_HITTABLE_H

#include "../utility/Vec3.h"
#include "../utility/Ray.h"
#include "../utility/defines.h"
#include "hit_record.h"
#include "materials/material.h"

class Hittable {
public:
    Material* material;

    Hittable()= default;

    explicit Hittable(Material* mat) : material(mat){};

    virtual bool Hit(const Ray& r, double t_min, double t_max, hit_record& rec) const = 0;
};


#endif //RAYTRACER_HITTABLE_H
