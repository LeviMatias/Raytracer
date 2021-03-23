//
// Created by Matias Ignacio Levi Fernandez on 11/03/2021.
//

#include "Scene.h"

bool Scene::Hit(const Ray &r, double t_min, double t_max, hit_record &rec) const {
    hit_record aux_record;
    bool hit_anything = false;
    auto closest_so_far = t_max;

    for (const auto& object : objects) {
        if (object->Hit(r, t_min, closest_so_far, aux_record)){
            rec = aux_record;
            closest_so_far = aux_record.t;
            hit_anything = true;
        }
    }

    return hit_anything;
}

Scene::Scene(shared_ptr<Hittable> &object) {
    add(object);
}

void Scene::add(const shared_ptr<Hittable> &object) {
    objects.push_back(object);
}
