//
// Created by matil on 4/18/2021.
//

#ifndef RAYTRACER_XZ_RECT_H
#define RAYTRACER_XZ_RECT_H


#include "../collision/hittable.h"

class XZRect : public Hittable {
public:
    XZRect() {}

    //alligned over k=y
    XZRect(double _x0, double _x1, double _z0, double _z1, double _k, std::shared_ptr<Material> &mat);

    virtual bool Hit(const Ray& r, double t_min, double t_max, hit_record& rec) const override;

    std::shared_ptr<Material> material;
    double x0, x1, z0, z1, k;
};


#endif //RAYTRACER_XZ_RECT_H
