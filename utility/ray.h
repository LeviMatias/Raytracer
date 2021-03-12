//
// Created by Matias Ignacio Levi Fernandez on 09/03/2021.
//

#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H
#include "vec3.h"

class ray {
public:
    vec3 direction;
    point3 origin;

    ray() = default;;
    ray(const point3& orig, const vec3& dir) : origin(orig), direction(dir) {};

    point3 At(double t) const{
        return origin + direction * t;
    }

};


#endif //RAYTRACER_RAY_H
