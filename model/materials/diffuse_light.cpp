//
// Created by Matias Ignacio Levi Fernandez on 16/04/2021.
//

#include "diffuse_light.h"

bool DiffuseLight::Scatter(const Ray &r_in, const hit_record &rec, Color &attenuation, Ray &scattered) const {
    return false;
}

Color DiffuseLight::Emitted(double u, double v, const Point3 &p) const {
    return albedo->Value(u, v, p);
}
