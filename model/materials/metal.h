//
// Created by Matias Ignacio Levi Fernandez on 23/03/2021.
//

#ifndef RAYTRACER_METAL_H
#define RAYTRACER_METAL_H


#include "material.h"

class Metal : public Material {
public:
    Metal(Color c) : Material(c) {}

    Metal() :Material(DEFAULT_MAT_COLOR) {}

    virtual bool Scatter(const Ray& r_in, const hit_record& rec, Color& attenuation, Ray& scattered) const;
};


#endif //RAYTRACER_METAL_H
