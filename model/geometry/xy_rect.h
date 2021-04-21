//
// Created by Matias Ignacio Levi Fernandez on 16/04/2021.
//

#ifndef RAYTRACER_XY_RECT_H
#define RAYTRACER_XY_RECT_H

#include "../materials/material.h"
#include "../collision/aabb.h"
#include "../collision//hittable.h"

class XYRect : public Hittable {
public:
    XYRect() {}

    //alligned over k=z
    XYRect(double _x0, double _x1, double _y0, double _y1, double _k, std::shared_ptr<Material> &mat);

    virtual bool Hit(const Ray& r, double t_min, double t_max, hit_record& rec) const override;

    std::shared_ptr<Material> material;
    double x0, x1, y0, y1, k;
};


#endif //RAYTRACER_XY_RECT_H
