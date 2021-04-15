//
// Created by Matias Ignacio Levi Fernandez on 13/04/2021.
//

#ifndef RAYTRACER_SOLID_COLOR_H
#define RAYTRACER_SOLID_COLOR_H


#include "texture.h"

class SolidColor : public Texture {
public:
    SolidColor() {}
    SolidColor(Color c) : color_value(c) {}

    SolidColor(double red, double green, double blue): SolidColor(Color(red,green,blue)) {}

    Color Value(double u, double v, const Vec3& p) const override {
        return color_value;
    }

private:
    Color color_value;
};


#endif //RAYTRACER_SOLID_COLOR_H
