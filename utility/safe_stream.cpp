//
// Created by Matias Ignacio Levi Fernandez on 05/03/2021.
//

#include "safe_stream.h"

SafeStream::SafeStream() {

}

SafeStream::~SafeStream() {

}

int SafeStream::OpenRead(const std::string &path) {
    return 0;
}

int SafeStream::OpenWrite(const std::string &path) {
    return 0;
}

unsigned int SafeStream::Read(char *buffer, unsigned int index, size_t size) {
    return 0;
}

int SafeStream::Write(char *buffer, size_t size) {
    return 0;
}

bool SafeStream::EoF() {
    return false;
}

void SafeStream::Close() {

}

void SafeStream::CloseOutput() {

}

void SafeStream::CloseInput() {

}
