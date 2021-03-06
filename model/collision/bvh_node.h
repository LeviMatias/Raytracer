//
// Created by Matias Ignacio Levi Fernandez on 09/04/2021.
//

#ifndef RAYTRACER_BVH_NODE_H
#define RAYTRACER_BVH_NODE_H


#include "hittable.h"

// todo make into avl tree
class BVH_Node : public Hittable {
public:
    shared_ptr<Hittable> left;
    shared_ptr<Hittable> right;

    BVH_Node(std::vector<shared_ptr<Hittable>> &src_objects);

    //copy
    BVH_Node(const BVH_Node &other);

    //assignment
    BVH_Node& operator = (const BVH_Node &other);

    bool Hit(const Ray& r, double t_min, double t_max, hit_record& rec) const override;

    BVH_Node(std::vector<shared_ptr<Hittable>> &src_objects, size_t start, size_t end);
};


#endif //RAYTRACER_BVH_NODE_H
