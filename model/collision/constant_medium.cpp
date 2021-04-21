//
// Created by Matias Ignacio Levi Fernandez on 19/04/2021.
//

#include "constant_medium.h"

bool ConstantMedium::Hit(const Ray &r, double t_min, double t_max, hit_record &rec) const {
    hit_record rec1, rec2;

    if (!boundary->Hit(r, -INF, INF, rec1))
        return false;

    //make sure its not grazing the object
    if (!boundary->Hit(r, rec1.t+0.0001, INF, rec2))
        return false;

    if (rec1.t < t_min) rec1.t = t_min;
    if (rec2.t > t_max) rec2.t = t_max;

    if (rec1.t >= rec2.t)
        return false;

    if (rec1.t < 0)
        rec1.t = 0;

    const double ray_length = r.direction.length();
    const double distance_inside_boundary = (rec2.t - rec1.t) * ray_length;
    const double hit_distance = neg_inv_density * log(Random::NextNumber());

    if (hit_distance > distance_inside_boundary)
        return false;

    rec.t = rec1.t + hit_distance / ray_length;
    rec.p = r.At(rec.t);

    rec.normal = Vec3(1,0,0);  // arbitrary
    rec.front_face = true;     // also arbitrary
    rec.hit = (Hittable *)this;

    return true;
}
