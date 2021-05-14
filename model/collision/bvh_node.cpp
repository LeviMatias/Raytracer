//
// Created by Matias Ignacio Levi Fernandez on 09/04/2021.
//

#include "bvh_node.h"

bool BVH_Node::Hit(const Ray &r, double t_min, double t_max, hit_record &rec) const {
    if (!bounding_box.Hit(r, t_min, t_max)) return false;

    bool ll = left && left->Hit(r, t_min, t_max, rec);
    bool rr = right && right->Hit(r, t_min, ll ? rec.t : t_max, rec);

    return rr || ll;
}

BVH_Node::BVH_Node(std::vector<shared_ptr<Hittable>> &src_objects)
: BVH_Node(src_objects, 0, src_objects.size()) {}

BVH_Node::BVH_Node(std::vector<shared_ptr<Hittable>> &src_objects, size_t start, size_t end) {
    auto objects = src_objects; // Create a modifiable array of the source scene objects

    int static axis = 1;
    axis = (axis + 1) % 3;

    size_t object_span = end - start;
    auto comparator = [&](const shared_ptr<Hittable>& a, const shared_ptr<Hittable>& b){
        return a->bounding_box.near[axis] < b->bounding_box.near[axis];
    };

    if (object_span == 1) {
        right = objects[start];
    } else if (object_span == 2) {
        if (comparator(objects[start], objects[start+1])) {
            left = objects[start];
            right = objects[start+1];
        } else {
            left = objects[start+1];
            right = objects[start];
        }
    } else {
        std::sort(objects.begin() + start, objects.begin() + end, comparator);

        auto mid = start + object_span/2;
        left = make_shared<BVH_Node>(objects, start, mid);
        right = make_shared<BVH_Node>(objects, mid, end);
    }

    auto max = right->bounding_box;
    auto min = (left) ? left->bounding_box : max;
    bounding_box = AABB(min, max);
}

BVH_Node &BVH_Node::operator=(const BVH_Node &other) {
    left = other.left;
    right = other.left;

    return *this;
}

BVH_Node::BVH_Node(const BVH_Node &other) {
    left = other.left;
    right = other.left;
}
