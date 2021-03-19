//
// Created by Matias Ignacio Levi Fernandez on 12/03/2021.
//

#include "Image.h"

void Image::WriteColor(Color pixel_color) {
    // Write the translated [0,255] value of each Color component.
    // Divide the color by the number of samples and gamma-correct for gamma=2.0.
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    r = sqrt(r);
    g = sqrt(g);
    b = sqrt(b);

    out << static_cast<int>(255.999 * r) << ' '
        << static_cast<int>(255.999 * g) << ' '
        << static_cast<int>(255.999 * b) << '\n';
}

Image::Image(): Image(IMAGE_NAME) {}

Image::Image(const std::string& imgname) : buffer(IMG_WIDTH * IMG_HEIGHT){
    out.OpenWrite(imgname);
    this->aspect_ratio = IMG_ASPECT_RATIO;
    this->w = IMG_WIDTH;
    this->h = IMG_HEIGHT;

    out << "P3\n" << w << " " << this->h << "\n255\n";
}

void Image::WriteColorAt(Color col, int x, int y) {
    //convert to reg and apply sqrt gamma correction
    int r = static_cast<int>(255.999 * sqrt(col.x()));
    int g = static_cast<int>(255.999 * sqrt(col.y()));
    int b = static_cast<int>(255.999 * sqrt(col.z()));

    buffer[ w * y + x].r =  r;
    buffer[ w * y + x].g =  g;
    buffer[ w * y + x].b =  b;
}

void Image::Save() {

    for (auto pix = buffer.end(); pix != buffer.begin(); pix--){
        out << pix->r << ' '
            << pix->g << ' '
            << pix->b << '\n';
    }

    for (auto &pix : buffer){

    }
}
