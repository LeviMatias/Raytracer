//
// Created by Matias Ignacio Levi Fernandez on 23/03/2021.
//

#include "metal.h"

bool Metal::Scatter(const Ray &r_in, const hit_record &rec, Color &attenuation, Ray &scattered) const {
    Vec3 reflected = r_in.direction.unit().reflect( rec.normal );
    scattered = Ray(rec.p, reflected + fussiness * Vec3::RandomUnit());
    attenuation = albedo;
    return ( scattered.direction.dot(rec.normal) > 0);
}
