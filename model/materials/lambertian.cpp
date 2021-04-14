//
// Created by Matias Ignacio Levi Fernandez on 23/03/2021.
//

#include "lambertian.h"

bool Lambertian::Scatter(const Ray &r_in, const hit_record &rec, Color &attenuation, Ray &scattered) const{
    //scatter ray in random direction
    auto scatter_direction = rec.normal + Vec3::RandomUnit() * Random::NextNumber();

    //catch the case where the resulting scatter vector is close to zero
    //to prevent NaN and INF cases
    if (scatter_direction.NearZero())
        scatter_direction = rec.normal;

    scattered = Ray(rec.p, scatter_direction);
    attenuation = albedo->Value(rec.u, rec.v, rec.p);
    return true;
}
