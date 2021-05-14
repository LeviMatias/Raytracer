//
// Created by Matias Ignacio Levi Fernandez on 21/04/2021.
//

#ifndef RAYTRACER_NIGHT_WORLD_GEN_H
#define RAYTRACER_NIGHT_WORLD_GEN_H

#include "../scene.h"
#include "../../utility/random.h"

class NightWorldGen {
public:
    void Generate(std::vector<shared_ptr<Hittable>> &objects);
};


#endif //RAYTRACER_NIGHT_WORLD_GEN_H
