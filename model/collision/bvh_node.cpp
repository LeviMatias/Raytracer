//
// Created by Matias Ignacio Levi Fernandez on 09/04/2021.
//

#include "bvh_node.h"

bool BVH_Node::Hit(const Ray &r, double t_min, double t_max, hit_record &rec) {
    if (!bounding_box.Hit(r, t_min, t_max))
    return false;

    bool ll = left && left->Hit(r, t_min, t_max, rec);
    bool rr = right && right->Hit(r, t_min, t_max, rec);

    return rr || ll;
}
