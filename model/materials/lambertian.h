//
// Created by Matias Ignacio Levi Fernandez on 23/03/2021.
//

#ifndef RAYTRACER_LAMBERTIAN_H
#define RAYTRACER_LAMBERTIAN_H

#include "material.h"

class Lambertian : public Material {
public:
    Lambertian() :Material(DEFAULT_MAT_COLOR) {}

    explicit Lambertian(Color color) : Material(color){}

    virtual bool Scatter(const Ray& r_in, const hit_record& rec, Color& attenuation, Ray& scattered) const;
};


#endif //RAYTRACER_LAMBERTIAN_H
