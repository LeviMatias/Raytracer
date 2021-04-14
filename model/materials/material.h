//
// Created by Matias Ignacio Levi Fernandez on 19/03/2021.
//

#ifndef RAYTRACER_MATERIAL_H
#define RAYTRACER_MATERIAL_H

#include "../collision/hit_record.h"
#include "texture.h"
#include "solid_color.h"

#define DEFAULT_MAT_COLOR Color(0.5, 0.5, 0.5)

class Material {
public:
    std::shared_ptr<Texture> albedo;

    explicit Material(Color c) : albedo(std::make_shared<SolidColor>(c)) {}

    explicit Material(std::shared_ptr<Texture> &t) : albedo(t) {}

    virtual bool Scatter(const Ray& r_in, const hit_record& rec, Color& attenuation, Ray& scattered) const = 0;
};


#endif //RAYTRACER_MATERIAL_H
