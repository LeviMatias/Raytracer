//
// Created by Matias Ignacio Levi Fernandez on 11/03/2021.
//

#include "scene.h"

bool Scene::Hit(const Ray &r, double t_min, double t_max, hit_record &rec) const {
    return root.Hit(r, t_min, t_max, rec);
}

Scene::Scene(std::vector<shared_ptr<Hittable>> &source) : root(source), a(&source) {}
