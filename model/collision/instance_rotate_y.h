//
// Created by Matias Ignacio Levi Fernandez on 19/04/2021.
//

#ifndef RAYTRACER_INSTANCE_ROTATE_Y_H
#define RAYTRACER_INSTANCE_ROTATE_Y_H


#include "hittable.h"

class InstanceRotateY : public Hittable {
public:
    InstanceRotateY(shared_ptr<Hittable> &p, double angle);

    virtual bool Hit(const Ray& r, double t_min, double t_max, hit_record& rec) const override;

private:
    shared_ptr<Hittable> ptr;
    double sin_theta;
    double cos_theta;
};


#endif //RAYTRACER_INSTANCE_ROTATE_Y_H
