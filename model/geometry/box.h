//
// Created by Matias Ignacio Levi Fernandez on 19/04/2021.
//

#ifndef RAYTRACER_BOX_H
#define RAYTRACER_BOX_H

#include "../collision/hittable.h"
#include "../collision/bvh_node.h"

class Box : public Hittable {
public:

    Box() = default;

    Box(Point3 p0, Point3 p1, std::shared_ptr<Material> &m);

    bool Hit(const Ray &r, double t_min, double t_max, hit_record &rec) const override;

private:
    Point3 min;
    Point3 max;
    std::shared_ptr<BVH_Node> sides;
    std::vector<shared_ptr<Hittable>> v;
};


#endif //RAYTRACER_BOX_H
