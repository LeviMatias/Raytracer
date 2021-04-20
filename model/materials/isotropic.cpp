//
// Created by Matias Ignacio Levi Fernandez on 19/04/2021.
//

#include "isotropic.h"

bool Isotropic::Scatter(const Ray &r_in, const hit_record &rec, Color &attenuation, Ray &scattered) const {
    scattered = Ray(rec.p, Vec3::RandomUnit());
    attenuation = albedo->Value(rec.u, rec.v, rec.p);
    return true;
}
