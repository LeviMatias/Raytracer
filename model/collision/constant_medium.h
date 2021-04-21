//
// Created by Matias Ignacio Levi Fernandez on 19/04/2021.
//

#ifndef RAYTRACER_CONSTANT_MEDIUM_H
#define RAYTRACER_CONSTANT_MEDIUM_H

#include "hittable.h"
#include "../materials/isotropic.h"

class ConstantMedium : public Hittable {

    ConstantMedium(shared_ptr<Hittable> &b, double d, shared_ptr<Texture> &a): boundary(b), neg_inv_density(-1/d),
    Hittable(std::make_shared<Isotropic>(a)), phase_function(material)
    {}

    ConstantMedium(std::shared_ptr<Hittable> &b, double d, Color c): boundary(b), neg_inv_density(-1/d),
    Hittable(std::make_shared<Isotropic>(c)), phase_function(material)
    {}

    virtual bool Hit(const Ray& r, double t_min, double t_max, hit_record& rec) const override;

private:
    shared_ptr<Hittable> boundary;
    shared_ptr<Material> phase_function;
    double neg_inv_density;
};


#endif //RAYTRACER_CONSTANT_MEDIUM_H
