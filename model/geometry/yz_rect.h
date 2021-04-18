//
// Created by matil on 4/18/2021.
//

#ifndef RAYTRACER_YZ_RECT_H
#define RAYTRACER_YZ_RECT_H


#include "../collision/hittable.h"

class YZRect : public Hittable {
public:
    YZRect(){};

    YZRect(double _y0, double _y1, double _z0, double _z1, double _k, shared_ptr<Material> &mat);

    bool Hit(const Ray& r, double t_min, double t_max, hit_record& rec) const override;

public:
    shared_ptr<Material> material;
    double y0, y1, z0, z1, k;
};


#endif //RAYTRACER_YZ_RECT_H
