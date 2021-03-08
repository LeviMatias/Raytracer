//
// Created by Matias Ignacio Levi Fernandez on 05/03/2021.
//

#include "safe_stream.h"

SafeStream::SafeStream() {
    this->ifile_opened = false;
    this->ofile_opened = false;
    this->index = 0;
}

SafeStream::~SafeStream() {
    this->Close();
}

int SafeStream::OpenRead(const std::string &path) {
    bool read_from_stdin =  (path.empty() || strcmp(&path[0], "-") == 0) ;
    if (this->ifile_opened) CloseInput();

    if (read_from_stdin){
        this->istream = &std::cin;
    } else{
        ifile.open(path, std::fstream::in | std::ios_base::binary);
        if (!this->ifile.good()){
            std::cerr<<"failed to open the input stream"<<std::endl;
            return 1;
        }
        this->istream = &ifile;
        this->ifile_opened = true;
        this->index = 0;
    }
    return 0;
}

int SafeStream::OpenWrite(const std::string &path) {
    bool write_to_stdout = (path.empty() || strcmp(&path[0], "-") == 0) ;
    if (this->ofile_opened) CloseOutput();

    if (write_to_stdout){
        this->ostream = &std::cout;
    } else {
        ofile.open(path, std::fstream::out);
        if (!ofile.good()){
            std::cerr<<"failed to open the output stream"<<std::endl;
            return 1;
        }
        this->ostream = &ofile;
        this->ofile_opened = true;
    }

    return 0;
}

unsigned int SafeStream::Read(char *buffer, unsigned int i, size_t size) {
    if (this->EoF()) this->istream->clear();
    unsigned int s = 0;
    // seek index relative to beginning of file
    //dont seekg in std::out
    if (ofile_opened) istream->seekg(i, std::istream::beg);
    while (s < size && istream->read(buffer, 1)){
        s++;
    }

    return s;
}

unsigned int SafeStream::Read(char *buffer, size_t size) {
    unsigned int read_c = this->Read(buffer, this->index, size);
    this->index += read_c;
    return read_c;
}

int SafeStream::Write(char *buffer, size_t size) {
    std::unique_lock<std::mutex> lock(this->m);
    this->ostream->write(buffer, size);
    return 0;
}

bool SafeStream::EoF() {
    if (!this->ifile_opened) return true;
    return this->istream->eof();
}

void SafeStream::Close() {
    this->CloseInput();
    this->CloseOutput();
}

void SafeStream::CloseOutput() {
    if (this->ofile_opened){
        this->ofile.close();
        this->ofile_opened = false;
    }
}

void SafeStream::CloseInput() {
    if (this->ifile_opened){
        this->ifile.close();
        this->ifile_opened = false;
    }
}

int SafeStream::OpenRead() {
    return this->OpenRead("");
}

int SafeStream::OpenWrite() {
    return this->OpenWrite("");
}

SafeStream& SafeStream::operator<<(const std::string& s) {
    *(this->ostream) << s;
    return *this;
}

SafeStream& SafeStream::operator<<(char* c) {
    while (*c){
        this->Write(c, 1);
        c++;
    }
    return *this;
}


SafeStream& SafeStream::operator>>(char *c) {
    size_t r = 0;
    while (this->Read(c, 1)) r++;
    return *this;
}

SafeStream& SafeStream::operator<<(int i) {
    *(this->ostream) << i;
    return *this;
}
