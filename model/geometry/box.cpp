//
// Created by Matias Ignacio Levi Fernandez on 19/04/2021.
//

#include "box.h"
#include "xy_rect.h"
#include "xz_rect.h"
#include "yz_rect.h"

Box::Box(Point3 p0, Point3 p1, std::shared_ptr<Material> &m) : Hittable(m) {
    std::vector<shared_ptr<Hittable>> v;
    min = p0;
    max = p1;

    v.push_back(std::make_shared<XYRect>(p0.x(), p1.x(), p0.y(), p1.y(), p0.z() ,material));
    v.push_back(std::make_shared<XYRect>(p0.x(), p1.x(), p0.y(), p1.y(), p1.z() ,material));

    v.push_back(std::make_shared<XZRect>(p0.x(), p1.x(), p0.z(), p1.z(), p0.y() ,material));
    v.push_back(std::make_shared<XZRect>(p0.x(), p1.x(), p0.z(), p1.z(), p1.y() ,material));

    v.push_back(std::make_shared<YZRect>(p0.y(), p1.y(), p0.z(), p1.z(), p0.x() ,material));
    v.push_back(std::make_shared<YZRect>(p0.y(), p1.y(), p0.z(), p1.z(), p1.x() ,material));

    sides = std::make_shared<BVH_Node>(v);
}

bool Box::Hit(const Ray &r, double t_min, double t_max, hit_record &rec) const {
    return false;
}
