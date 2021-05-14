//
// Created by Matias Ignacio Levi Fernandez on 21/04/2021.
//

#include "night_world_gen.h"
#include "../geometry/box.h"
#include "../materials/reflective.h"
#include "../materials/textures/image_texture.h"
#include "../materials/diffuse_light.h"
#include "../materials/lambertian.h"

void NightWorldGen::Generate(std::vector<shared_ptr<Hittable>> &objects) {
    std::shared_ptr<Material> ground = std::make_shared<Lambertian>(Color(153.0/255.0, 0, 0));

    double w = 100.0;
    const int boxes_per_side = 20;
    double base_x = -1000.0;
    double base_z = 200.0;

    for (int i = 0; i < boxes_per_side; i++) {
        for (int j = 0; j < boxes_per_side; j++) {
            double x0 = base_x + i*w;
            double z0 = base_z + j*w;
            double y0 = 0.0;
            double x1 = x0 + w;
            double z1 = z0 + w;
            double y1 = 100 + 100*Random::PerlinNoise(x0/(base_x + boxes_per_side*w),z0/(base_z + boxes_per_side*w));

            objects.push_back(std::make_shared<Box>(Point3(x0,y0,z0), Point3(x1,y1,z1), ground));
        }
    }

    std::shared_ptr<Texture> img = std::make_shared<ImageTexture>("assets/moonTexture.png",
                                                                  Color(3, 1, 1), 0.75);
    std::shared_ptr<Material> mmat = std::make_shared<DiffuseLight>(img);
    objects.push_back(std::make_shared<Sphere>(Point3(220,280,300), 80, mmat));
}
