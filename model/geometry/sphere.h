//
// Created by Matias Ignacio Levi Fernandez on 10/03/2021.
//

#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H


#include "../collision/hittable.h"

class Sphere: public Hittable {
public:
    Point3 center;
    double radius;

    Sphere(Point3 center, double r);

    Sphere(Point3 center, double r, shared_ptr<Material> material);

    bool Hit(const Ray& r, double t_min, double t_max, hit_record& rec) const override;

private:
    static void SetSphereUV(const Point3& point_in_usphere, hit_record& rec);
};


#endif //RAYTRACER_SPHERE_H
