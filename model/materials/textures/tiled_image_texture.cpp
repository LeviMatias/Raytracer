//
// Created by Matias Ignacio Levi Fernandez on 19/04/2021.
//

#include "tiled_image_texture.h"

Color TiledImageTexture::Value(double u, double v, const Point3 &p) const {
    if (!data) return {0, 1, 1}; //failed to load

    //todo recv hit_record as param and get hit coordinates from
    // hit->getXYCoordinates(p);

    int x = static_cast<int>(p.x() * width) % width;
    int y = static_cast<int>(height - p.y() * height) % height;// flip y

    auto pixel = data + y*bytes_per_scanline + x*BYTES_PER_PIXEL;
    double color_scale = 1.0/255.0;
    double alpha = color_scale * pixel[3] + transparency;
    alpha = (alpha > 1) ? 1 : alpha;
    Color c(color_scale * pixel[0], color_scale*pixel[1], color_scale*pixel[2]);

    return c * (1-alpha) + color * alpha;
}
