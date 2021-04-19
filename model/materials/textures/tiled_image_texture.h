//
// Created by Matias Ignacio Levi Fernandez on 19/04/2021.
//

#ifndef RAYTRACER_TILED_IMAGE_TEXTURE_H
#define RAYTRACER_TILED_IMAGE_TEXTURE_H


#include "image_texture.h"

class TiledImageTexture : public ImageTexture {
    TiledImageTexture(const char* filename, Color c) : ImageTexture(filename, c){};

    TiledImageTexture(const char* filename, Color c, double t) : ImageTexture(filename, c, t){};

    virtual Color Value(double u, double v, const Point3& p) const override;
};


#endif //RAYTRACER_TILED_IMAGE_TEXTURE_H
