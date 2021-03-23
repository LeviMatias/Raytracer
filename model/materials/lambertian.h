//
// Created by Matias Ignacio Levi Fernandez on 23/03/2021.
//

#ifndef RAYTRACER_LAMBERTIAN_H
#define RAYTRACER_LAMBERTIAN_H


#include "material.h"
#include "../../utility/Ray.h"

class Lambertian : public Material {
public:
    Color albedo;

    explicit Lambertian(Color color) : albedo(color){}

    virtual bool Scatter(const Ray& r_in, const hit_record& rec, Color& attenuation, Ray& scattered);
};


#endif //RAYTRACER_LAMBERTIAN_H
