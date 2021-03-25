//
// Created by Matias Ignacio Levi Fernandez on 25/03/2021.
//

#include "dielectric.h"


bool Dielectric::Scatter(const Ray &r_in, const hit_record &rec, Color &attenuation, Ray &scattered) const {
    attenuation = Color(1.0, 1.0, 1.0);
    double refraction_ratio = rec.front_face ? (1.0/refraction_index) : refraction_index;

    Vec3 unit_direction = r_in.direction.unit();
    Vec3 refracted = Refract(unit_direction, rec.normal, refraction_ratio);

    scattered = Ray(rec.p, refracted);
    return true;
}

Vec3 Dielectric::Refract(const Vec3 &uv, const Vec3 &n, double refraction_index_quotient) const {
    auto cos_theta = fmin( (-uv).dot(n), 1.0);
    Vec3 r_out_perp =  refraction_index_quotient * (uv + cos_theta*n);
    Vec3 r_out_parallel = -sqrt(fabs(1.0 - r_out_perp.length_squared())) * n;
    return r_out_perp + r_out_parallel;
}
