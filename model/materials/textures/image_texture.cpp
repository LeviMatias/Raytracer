//
// Created by Matias Ignacio Levi Fernandez on 14/04/2021.
//

#include "image_texture.h"

ImageTexture::ImageTexture(const char *filename) {
    auto components_per_pixel = BYTES_PER_PIXEL;

    data = stbi_load(
            filename, &width, &height, &components_per_pixel, components_per_pixel);

    if (!data) {
        std::cerr << "ERROR: Could not load texture image file '" << filename << "'.\n";
        width = height = 0;
    }

    bytes_per_scanline = BYTES_PER_PIXEL * width;
}

Color ImageTexture::Value(double u, double v, const Point3 &p) const {
    if (!data) return {0, 1, 1}; //failed to load

    u = CLAMP(u, 0.0, 1.0); //CLAMP u,v in image boundaries
    v = CLAMP(v, 0.0, 1.0);

    int x = static_cast<int>(u * width);
    int y = static_cast<int>(height - v * height);// flip y

    x = std::min(x, width - 1);
    y = std::min(y, height - 1);

    auto pixel = data + y*bytes_per_scanline + x*BYTES_PER_PIXEL;
    double color_scale = 1.0/255.0;

    return {color_scale * pixel[0], color_scale*pixel[1], color_scale*pixel[2]};
}
