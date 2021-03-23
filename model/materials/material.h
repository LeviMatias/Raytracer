//
// Created by Matias Ignacio Levi Fernandez on 19/03/2021.
//

#ifndef RAYTRACER_MATERIAL_H
#define RAYTRACER_MATERIAL_H

#include "../hit_record.h"

class Material {
public:
    Color albedo;

    explicit Material(Color c) : albedo(c) {}

    virtual bool Scatter(const Ray& r_in, const hit_record& rec, Color& attenuation, Ray& scattered){};
};


#endif //RAYTRACER_MATERIAL_H
