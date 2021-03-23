//
// Created by Matias Ignacio Levi Fernandez on 23/03/2021.
//

#ifndef RAYTRACER_GRASS_H
#define RAYTRACER_GRASS_H


#include "lambertian.h"

class Grass : public Lambertian {
public:
    explicit Grass(Color color) : Lambertian(color){}

    virtual bool Scatter(const Ray& r_in, const hit_record& rec, Color& attenuation, Ray& scattered) const;
};


#endif //RAYTRACER_GRASS_H
