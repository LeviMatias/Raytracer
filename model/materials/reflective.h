//
// Created by Matias Ignacio Levi Fernandez on 25/03/2021.
//

#ifndef RAYTRACER_REFLECTIVE_H
#define RAYTRACER_REFLECTIVE_H

#include "material.h"
#define DEF_FUSSINESS 0

class Reflective : public Material {
public:
    double fussiness;

    Vec3 Reflect(const Vec3& v, const Vec3& normal) const;

    Reflective(Color c) : Material(c), fussiness(DEF_FUSSINESS) {}

    Reflective(Color c, double f) : Material(c), fussiness((f < 1) ? f : 1) {}

    Reflective() :Material(DEFAULT_MAT_COLOR), fussiness(DEF_FUSSINESS) {}

    virtual bool Scatter(const Ray& r_in, const hit_record& rec, Color& attenuation, Ray& scattered) const;
};

using Metal = Reflective;

#endif //RAYTRACER_REFLECTIVE_H
