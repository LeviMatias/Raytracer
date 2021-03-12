//
// Created by Matias Ignacio Levi Fernandez on 10/03/2021.
//

#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H


#include "Hittable.h"

class Sphere: public Hittable {
public:
    Point3 center;
    double radius;

    Sphere(Point3 center, double r);

    virtual bool hit(const Ray& r, double t_min, double t_max, hit_record& rec) const override;

};


#endif //RAYTRACER_SPHERE_H
