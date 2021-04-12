//
// Created by Matias Ignacio Levi Fernandez on 12/03/2021.
//

#include "image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "infostream/stb_image_write.h"

Image::Image(): Image(IMAGE_NAME) {}

Image::Image(const std::string& imgname) : buffer(IMG_WIDTH * IMG_HEIGHT){
    this->aspect_ratio = IMG_ASPECT_RATIO;
    this->w = IMG_WIDTH;
    this->h = IMG_HEIGHT;
}

void Image::WriteColorAt(Color col, int x, int y) {
    //convert to reg and apply sqrt gamma correction
    char r = static_cast<char>(255.999 * sqrt(col.x()));
    char g = static_cast<char>(255.999 * sqrt(col.y()));
    char b = static_cast<char>(255.999 * sqrt(col.z()));

    int position = IMG_WIDTH * IMG_HEIGHT - 1;
    position -= w * y + x;
    buffer[position].r =  r;
    buffer[position].g =  g;
    buffer[position].b =  b;
}

void Image::Save() {
    std::string fname = IMAGE_NAME;
    stbi_write_png(&fname.front(), w, h, 3, &buffer.front(), w*3);
}
