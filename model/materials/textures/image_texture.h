//
// Created by Matias Ignacio Levi Fernandez on 14/04/2021.
//

#ifndef RAYTRACER_IMAGE_TEXTURE_H
#define RAYTRACER_IMAGE_TEXTURE_H

#include "texture.h"
#include "../../../utility/math_macros.h"
#define BYTES_PER_PIXEL 4 //RGBA

class ImageTexture : public Texture {
public:
    int height, width;
    double transparency;

    ImageTexture(const char* filename);

    ImageTexture(const char* filename, Color c);

    ImageTexture(const char* filename, Color c, double transparency);

    virtual Color Value(double u, double v, const Point3& p) const override;

    ~ImageTexture();

protected:
    Color color;
    int bytes_per_scanline;
    unsigned char* data;
};


#endif //RAYTRACER_IMAGE_TEXTURE_H
