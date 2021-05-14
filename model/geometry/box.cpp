//
// Created by Matias Ignacio Levi Fernandez on 19/04/2021.
//

#include "box.h"
#include "xy_rect.h"
#include "xz_rect.h"
#include "yz_rect.h"
#include "../materials/reflective.h"

Box::Box(Point3 p0, Point3 p1, std::shared_ptr<Material> &m) : Hittable(m, p0, p1) {
    min = p0;
    max = p1;

    v.push_back(std::make_shared<XYRect>(p0.x(), p1.x(), p0.y(), p1.y(), p0.z() ,m));
    v.push_back(std::make_shared<XYRect>(p0.x(), p1.x(), p0.y(), p1.y(), p1.z() ,m));

    v.push_back(std::make_shared<XZRect>(p0.x(), p1.x(), p0.z(), p1.z(), p0.y() ,m));
    v.push_back(std::make_shared<XZRect>(p0.x(), p1.x(), p0.z(), p1.z(), p1.y() ,m));

    v.push_back(std::make_shared<YZRect>(p0.y(), p1.y(), p0.z(), p1.z(), p0.x() ,m));
    v.push_back(std::make_shared<YZRect>(p0.y(), p1.y(), p0.z(), p1.z(), p1.x() ,m));

    sides = std::make_shared<BVH_Node>(v);
}

bool Box::Hit(const Ray &r, double t_min, double t_max, hit_record &rec) const {
    bool h = false;
    for (auto &e : v){
        h = e->Hit(r, t_min, (h) ? rec.t : t_max, rec) || h;
    }
    return h;
}
