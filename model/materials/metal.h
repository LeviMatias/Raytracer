//
// Created by Matias Ignacio Levi Fernandez on 23/03/2021.
//

#ifndef RAYTRACER_METAL_H
#define RAYTRACER_METAL_H


#include "material.h"
#define DEF_METAL_FUSSINESS 0

class Metal : public Material {
public:
    double fussiness;

    Metal(Color c) : Material(c), fussiness(DEF_METAL_FUSSINESS) {}

    Metal(Color c, double f) : Material(c), fussiness((f < 1) ? f : 1) {}

    Metal() :Material(DEFAULT_MAT_COLOR), fussiness(DEF_METAL_FUSSINESS) {}

    virtual bool Scatter(const Ray& r_in, const hit_record& rec, Color& attenuation, Ray& scattered) const;
};


#endif //RAYTRACER_METAL_H
