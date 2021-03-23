//
// Created by Matias Ignacio Levi Fernandez on 09/03/2021.
//

#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H
#include "vec3.h"

class Ray {
public:
    Vec3 direction;
    Point3 origin;

    Ray() = default;
    Ray(const Point3& orig, const Vec3& dir) : origin(orig), direction(dir) {};

    Point3 At(double t) const{
        return origin + direction * t;
    }

};


#endif //RAYTRACER_RAY_H
