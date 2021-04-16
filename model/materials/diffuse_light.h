//
// Created by Matias Ignacio Levi Fernandez on 16/04/2021.
//

#ifndef RAYTRACER_DIFFUSE_LIGHT_H
#define RAYTRACER_DIFFUSE_LIGHT_H


#include "material.h"

class DiffuseLight : public Material {
public:
    DiffuseLight(std::shared_ptr<Texture> &t) : Material(t){};

    bool Scatter(const Ray &r_in, const hit_record &rec, Color &attenuation, Ray &scattered) const override;

    virtual Color Emitted(double u, double v, const Point3& p) const;
};


#endif //RAYTRACER_DIFFUSE_LIGHT_H
