//
// Created by Matias Ignacio Levi Fernandez on 19/04/2021.
//

#ifndef RAYTRACER_ISOTROPIC_H
#define RAYTRACER_ISOTROPIC_H


#include "material.h"

class Isotropic : public Material {
public:
    explicit Isotropic(Color c) : Material(c) {}

    explicit Isotropic(std::shared_ptr<Texture> a) : Material(a) {}

    bool Scatter(const Ray& r_in, const hit_record& rec, Color& attenuation, Ray& scattered) const override;
};


#endif //RAYTRACER_ISOTROPIC_H
