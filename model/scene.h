//
// Created by Matias Ignacio Levi Fernandez on 11/03/2021.
//

#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H

#include "geometry/sphere.h"
#include "collision/bvh_node.h"
#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

class Scene : public Hittable {
public:
    BVH_Node root;
    std::vector<shared_ptr<Hittable>> *a;

    Scene(std::vector<shared_ptr<Hittable>> &source);

    bool Hit(const Ray& r, double t_min, double t_max, hit_record& rec) const override;
};


#endif //RAYTRACER_SCENE_H
