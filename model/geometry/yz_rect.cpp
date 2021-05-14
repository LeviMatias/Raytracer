//
// Created by matil on 4/18/2021.
//

#include "yz_rect.h"

YZRect::YZRect(double _y0, double _y1, double _z0, double _z1, double _k, std::shared_ptr<Material> &mat)
        : y0(_y0), y1(_y1), z0(_z0), z1(_z1), k(_k), Hittable(mat){
    bounding_box.near = Point3(y0, z0, k-0.0001);
    bounding_box.far = Point3(y1, z1, k+0.0001);
}

bool YZRect::Hit(const Ray &r, double t_min, double t_max, hit_record &rec) const {
    //hitx = originx + t*dirx;
    //t = (hitx - originx)/dirx and k = x;
    auto t = (k-r.origin.x()) / r.direction.x();

    //if outside valid range
    if (t < t_min || t > t_max)
        return false;

    auto z = r.origin.z() + t*r.direction.z();
    auto y = r.origin.y() + t*r.direction.y();

    //if outside XY boundaries
    if (z < z0 || z > z1 || y < y0 || y > y1)
        return false;

    //where did it hit (relative)?
    rec.u = (z-z0)/(z1-z0);
    rec.v = (y-y0)/(y1-y0);
    rec.t = t;

    // rect is axis aligned over x
    auto outward_normal = Vec3(1, 0, 0);
    rec.set_face_normal(r, outward_normal);
    rec.hit = (Hittable *)this;
    rec.p = r.At(t);
    return true;
}
