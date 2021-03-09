//
// Created by Matias Ignacio Levi Fernandez on 09/03/2021.
//

#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H
#include "vec3.h"

class ray {
public:
    vec3 dir;
    point3 orig;

    ray() {};
    ray(const point3& orig, const vec3& dir) : orig(orig), dir(dir) {};

    vec3 direction() const { return dir;}
    vec3 origin() const { return orig;}

    point3 at(double t) const{
        return orig + dir*t;
    }

};


#endif //RAYTRACER_RAY_H
