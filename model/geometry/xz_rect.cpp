//
// Created by matil on 4/18/2021.
//

#include "xz_rect.h"
XZRect::XZRect(double _x0, double _x1, double _z0, double _z1, double _k, shared_ptr<Material> &mat)
        : x0(_x0), x1(_x1), z0(_z0), z1(_z1), k(_k), Hittable(mat){
    bounding_box.near = Point3(x0, z0, k-0.0001);
    bounding_box.far = Point3(x1, z1, k+0.0001);
}

bool XZRect::Hit(const Ray &r, double t_min, double t_max, hit_record &rec) const {
    auto t = (k-r.origin.y()) / r.direction.y();
    if (t < t_min || t > t_max)
        return false;

    auto x = r.origin.x() + t*r.direction.x();
    auto z = r.origin.z() + t*r.direction.z();
    if (x < x0 || x > x1 || z < z0 || z > z1)
        return false;

    //where did it hit (relative)?
    rec.u = (x-x0)/(x1-x0);
    rec.v = (z-z0)/(z1-z0);
    rec.t = t;

    auto outward_normal = Vec3(0, 1, 0);
    rec.set_face_normal(r, outward_normal);
    rec.hit = (Hittable *)this;
    rec.p = r.At(t);
    return true;
}
