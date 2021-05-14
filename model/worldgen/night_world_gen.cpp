//
// Created by Matias Ignacio Levi Fernandez on 21/04/2021.
//

#include "night_world_gen.h"
#include "../geometry/box.h"
#include "../materials/reflective.h"
#include "../materials/textures/image_texture.h"
#include "../materials/diffuse_light.h"

void NightWorldGen::Generate(std::vector<shared_ptr<Hittable>> &objects) {
    std::shared_ptr<Material> ground = std::make_shared<Metal>(Color(153.0/255.0, 0, 0), 0.1);

    const int boxes_per_side = 1;
    for (int i = 0; i < boxes_per_side; i++) {
        for (int j = 0; j < boxes_per_side; j++) {
            double w = 100.0;
            double x0 = 220;
            double z0 = 300;
            double y0 = 0.0;
            double x1 = x0 + w;
            double z1 = z0 + w;
            double y1 = 150;

            objects.push_back(std::make_shared<Box>(Point3(x0,y0,z0), Point3(x1,y1,z1), ground));
        }
    }

    std::shared_ptr<Texture> img = std::make_shared<ImageTexture>("assets/moonTexture.png",
                                                                  Color(3, 1, 1), 0.75);
    std::shared_ptr<Material> mmat = std::make_shared<DiffuseLight>(img);
    //objects.push_back(std::make_shared<Sphere>(Point3(220,280,300), 80, mmat));
}
