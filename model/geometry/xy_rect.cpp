//
// Created by Matias Ignacio Levi Fernandez on 16/04/2021.
//

#include "xy_rect.h"

XYRect::XYRect(double _x0, double _x1, double _y0, double _y1, double _k, shared_ptr<Material> &mat)
        : x0(_x0), x1(_x1), y0(_y0), y1(_y1), k(_k), Hittable(mat){
    bounding_box.near = Point3(x0,y0, k-0.0001);
    bounding_box.far = Point3(x1, y1, k+0.0001);
}

bool XYRect::Hit(const Ray &r, double t_min, double t_max, hit_record &rec) const {
    //hitz = originz + t*dirz;
    //t = (hitz - originz)/dirz and k = z;
    auto t = (k-r.origin.z()) / r.direction.z();

    //if outside valid range
    if (t < t_min || t > t_max)
        return false;

    auto x = r.origin.x() + t*r.direction.x();
    auto y = r.origin.y() + t*r.direction.y();

    //if outside XY boundaries
    if (x < x0 || x > x1 || y < y0 || y > y1)
        return false;

    //where did it hit (relative)?
    rec.u = (x-x0)/(x1-x0);
    rec.v = (y-y0)/(y1-y0);
    rec.t = t;

    // rect is axis aligned over Z
    auto outward_normal = Vec3(0, 0, 1);
    rec.set_face_normal(r, outward_normal);
    rec.hit = (Hittable *)this;
    rec.p = r.At(t);
    return true;
}
