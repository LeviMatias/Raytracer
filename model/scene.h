//
// Created by Matias Ignacio Levi Fernandez on 11/03/2021.
//

#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H

#include "geometry/sphere.h"
#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

class Scene : public Hittable {
public:
    std::vector<shared_ptr<Hittable>> objects;

    Scene() = default;

    Scene(shared_ptr<Hittable> &object);

    void clear() { objects.clear(); }
    void add(const shared_ptr<Hittable>& object);

    bool Hit(const Ray& r, double t_min, double t_max, hit_record& rec) const override;


};


#endif //RAYTRACER_SCENE_H
