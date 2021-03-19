//
// Created by Matias Ignacio Levi Fernandez on 19/03/2021.
//

#ifndef RAYTRACER_MATERIAL_H
#define RAYTRACER_MATERIAL_H


class Material {
public:
    virtual bool Scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const = 0;
};


#endif //RAYTRACER_MATERIAL_H
