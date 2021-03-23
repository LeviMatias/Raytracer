//
// Created by Matias Ignacio Levi Fernandez on 23/03/2021.
//

#include "grass.h"

bool Grass::Scatter(const Ray &r_in, const hit_record &rec, Color &attenuation, Ray &scattered) const {
    Lambertian::Scatter(r_in, rec, attenuation, scattered);

    attenuation = attenuation * Random::NextNumber(0,1);

    return true;
}
