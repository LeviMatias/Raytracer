//
// Created by Matias Ignacio Levi Fernandez on 08/04/2021.
//

#ifndef RAYTRACER_AABB_H
#define RAYTRACER_AABB_H

#include "../../utility/vec3.h"
#include "../../utility/ray.h"

class AABB {
public:
    Point3 near;
    Point3 far;

    AABB() = default;

    AABB(const Point3 &near, const Point3 &far);

    AABB(const AABB &b0, const AABB &b1);

    //tmin, tmax acceptable range to evaluate the ray on
    bool Hit(Ray ray, double t_min, double t_max);


};


#endif //RAYTRACER_AABB_H
