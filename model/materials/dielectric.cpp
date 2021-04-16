//
// Created by Matias Ignacio Levi Fernandez on 25/03/2021.
//

#include "dielectric.h"


bool Dielectric::Scatter(const Ray &r_in, const hit_record &rec, Color &attenuation, Ray &scattered) const {
    attenuation = albedo->Value(0,0, rec.p);
    double refraction_ratio = rec.front_face ? (1.0/refraction_index) : refraction_index;

    Vec3 unit_direction = r_in.direction.unit();
    double cos_theta = fmin((-unit_direction).dot(rec.normal), 1.0);
    double sin_theta = sqrt(1.0 - cos_theta*cos_theta);

    bool cannot_refract = refraction_ratio * sin_theta > 1.0;
    Vec3 direction;

    if (cannot_refract || Reflectance(cos_theta, refraction_ratio) > Random::NextNumber())
        direction = Reflect(unit_direction, rec.normal);
    else
        direction = Refract(unit_direction, rec.normal, refraction_ratio);

    scattered = Ray(rec.p, direction);
    return true;
}

Vec3 Dielectric::Refract(const Vec3 &uv, const Vec3 &n, double refraction_index_quotient) const {
    auto cos_theta = fmin( (-uv).dot(n), 1.0);
    Vec3 r_out_perp =  refraction_index_quotient * (uv + cos_theta*n);
    Vec3 r_out_parallel = -sqrt(fabs(1.0 - r_out_perp.length_squared())) * n;
    return r_out_perp + r_out_parallel;
}

double Dielectric::Reflectance(double cosine, double ref_idx) const {
    // Use Schlick's approximation for reflectance.
    auto r0 = (1-ref_idx) / (1+ref_idx);
    r0 = r0*r0;
    return r0 + (1-r0)*pow((1 - cosine),5);
}
