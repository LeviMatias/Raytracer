//
// Created by Matias Ignacio Levi Fernandez on 14/04/2021.
//

#ifndef RAYTRACER_IMAGE_TEXTURE_H
#define RAYTRACER_IMAGE_TEXTURE_H

#include "texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "../../infostream/stb_image.h"
#include "../../../utility/math_macros.h"

#define BYTES_PER_PIXEL 3

class ImageTexture : public Texture {
public:
    int height, width;

    ImageTexture(const char* filename);


    virtual Color Value(double u, double v, const Point3& p) const override;

private:
    unsigned char* data;
    int bytes_per_scanline;
};


#endif //RAYTRACER_IMAGE_TEXTURE_H
