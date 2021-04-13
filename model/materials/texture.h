//
// Created by Matias Ignacio Levi Fernandez on 13/04/2021.
//

#ifndef RAYTRACER_TEXTURE_H
#define RAYTRACER_TEXTURE_H

#include "../../utility/vec3.h"

class Texture {
public:
    virtual Color Value(double u, double v, const Point3& p) const = 0;
};


#endif //RAYTRACER_TEXTURE_H
