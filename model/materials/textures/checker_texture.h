//
// Created by Matias Ignacio Levi Fernandez on 14/04/2021.
//

#ifndef RAYTRACER_CHECKER_TEXTURE_H
#define RAYTRACER_CHECKER_TEXTURE_H


#include "solid_color.h"

class CheckerTexture : public Texture {
public:
    CheckerTexture() = default;

    CheckerTexture(std::shared_ptr<Texture> &_even, std::shared_ptr<Texture> &_odd)
    : even(_even), odd(_odd) {};

    CheckerTexture(Color c1, Color c2)
    : even(std::make_shared<SolidColor>(c1)) , odd(std::make_shared<SolidColor>(c2)) {};

    virtual Color Value(double u, double v, const Point3& p) const override {
        auto sines = sin(10*p.x())*sin(10*p.y())*sin(10*p.z());
        if (sines < 0)
            return odd->Value(u, v, p);
        else
            return even->Value(u, v, p);
    }

public:
    std::shared_ptr<Texture> odd;
    std::shared_ptr<Texture> even;
};


#endif //RAYTRACER_CHECKER_TEXTURE_H
