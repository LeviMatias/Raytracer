//
// Created by Matias Ignacio Levi Fernandez on 11/03/2021.
//

#include "scene.h"

bool Scene::Hit(const Ray &r, double t_min, double t_max, hit_record &rec) const {
    bool h = false;
    for (auto &e : *a){
        h = e->Hit(r, t_min, (h) ? rec.t : t_max, rec) || h;
    }
    return h;
}

Scene::Scene(std::vector<shared_ptr<Hittable>> &source) : root(source), a(&source) {}
