//
// Created by Matias Ignacio Levi Fernandez on 12/03/2021.
//

#include "Image.h"

void Image::WriteColor(color pixel_color) {
    // Write the translated [0,255] value of each color component.
    out << static_cast<int>(255.999 * pixel_color.x()) << ' '
        << static_cast<int>(255.999 * pixel_color.y()) << ' '
        << static_cast<int>(255.999 * pixel_color.z()) << '\n';
}

Image::Image(double aspect_ratio, int w): Image(IMAGE_NAME, aspect_ratio, w) {}

Image::Image(const std::string& imgname, double aspect_ratio, int w) {
    out.OpenWrite(imgname);
    this->aspect_ratio = aspect_ratio;
    this->w = w;
    this->h = static_cast<int>(w / aspect_ratio);

    out << "P3\n" << w << " " << this->h << "\n255\n";
}

void Image::WriteColorAt(color pixel_color, int i) {
}
