//
// Created by Matias Ignacio Levi Fernandez on 25/03/2021.
//

#include "reflective.h"

Vec3 Reflective::Reflect(const Vec3 &v, const Vec3 &normal) const {
    //         *
    //  \  |  /
    //   \ | /
    //  __\N/__
    return v - 2 * v.dot(normal) * normal;
}

bool Reflective::Scatter(const Ray &r_in, const hit_record &rec, Color &attenuation, Ray &scattered) const {
    Vec3 reflected = this->Reflect(r_in.direction.unit(), rec.normal );
    scattered = Ray(rec.p, reflected + fussiness * Vec3::RandomUnit() * Random::NextNumber());
    attenuation = albedo;
    return ( scattered.direction.dot(rec.normal) > 0);
}
