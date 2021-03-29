//
// Created by Matias Ignacio Levi Fernandez on 25/03/2021.
//

#ifndef RAYTRACER_DIELECTRIC_H
#define RAYTRACER_DIELECTRIC_H


#include "material.h"
#include "reflective.h"

#define DEF_REFRACTION_I 1.0

class Dielectric : public Reflective {
public:
    double refraction_index;

    Dielectric(Color c, double ir) : Reflective(c), refraction_index(ir){};

    explicit Dielectric(double ir) : Reflective(DEFAULT_MAT_COLOR), refraction_index(ir){};

    explicit Dielectric(Color c) : Reflective(c), refraction_index(DEF_REFRACTION_I){};

    Dielectric() : Reflective(DEFAULT_MAT_COLOR), refraction_index(DEF_REFRACTION_I){};

    virtual bool Scatter(const Ray& r_in, const hit_record& rec, Color& attenuation, Ray& scattered) const;

    inline Vec3 Refract(const Vec3 &uv, const Vec3 &n, double refraction_index_quotient) const;

private:
    double Reflectance(double cosine, double ratio) const;
};

using Glass = Dielectric;

#endif //RAYTRACER_DIELECTRIC_H
