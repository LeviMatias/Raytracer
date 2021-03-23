//
// Created by Matias Ignacio Levi Fernandez on 08/03/2021.
//

#ifndef RAYTRACER_VEC3_H
#define RAYTRACER_VEC3_H

#include <cmath>
#include <iostream>
#include "Random.h"

#define COORDINATES 3

using std::sqrt;

class Vec3 {
public:
    double e[COORDINATES];

    Vec3(): e{0, 0, 0} {};

    Vec3(double x, double y, double z) : e{x, y, z} {};

    double x() const { return e[0]; }
    double y() const { return e[1]; }
    double z() const { return e[2]; }

    double length() const {
        return sqrt(length_squared());
    }

    double length_squared() const {
        return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
    }

    inline Vec3 unit() const{
        return *this/this->length();
    }

    inline double dot(const Vec3 &v) const{
        return e[0] * v.e[0]
               + e[1] * v.e[1]
               + e[2] * v.e[2];
    }

    inline Vec3 reflect(const Vec3& normal) const{
        //         *
        //  \  |  /
        //   \ | /
        //  __\N/__
        return *this - 2 * this->dot(normal) * normal;
    }

    inline bool NearZero(){
        const static auto s = 1e-8;
        return (fabs(e[0]) < s) && (fabs(e[1]) < s) && (fabs(e[2]) < s);
    }

    inline static Vec3 Random() {
        return {Random::NextNumber(), Random::NextNumber(), Random::NextNumber()};
    }

    inline static Vec3 Random(double min, double max) {
        return {Random::NextNumber(min, max), Random::NextNumber(min, max), Random::NextNumber(min, max)};
    }

    inline static Vec3 RandomUnit(){
        return Vec3::Random(-1, 1).unit();
    }

    // OPERATORS

    Vec3 operator-() const { return Vec3(-e[0], -e[1], -e[2]); }
    double operator[](int i) const { return e[i]; }
    double& operator[](int i) { return e[i]; }


    Vec3& operator+=(const Vec3 &v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }

    Vec3& operator*=(const double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    Vec3& operator/=(const double t) {
        return *this *= 1/t;
    }

    friend Vec3 operator*(const Vec3 &u, const Vec3 &v){
        return Vec3(u[0] * v[0] , u[1] * v[1] , u[2] * v[2]);
    }

    friend Vec3 operator*(const Vec3 &u, const double &t){
        return Vec3(u[0] * t , u[1] * t , u[2] * t);
    }

    friend Vec3 operator*(const double &t, const Vec3 &v){
        return v*t;
    }

    friend Vec3 operator+(const Vec3 &u, const Vec3 &v){
        return Vec3(u[0] + v[0] , u[1] + v[1] , u[2] + v[2]);
    }

    friend Vec3 operator-(const Vec3 &u, const Vec3 &v){
        return Vec3(u[0] - v[0] , u[1] - v[1] , u[2] - v[2]);
    }

    friend Vec3 operator/(const Vec3 &v, const double &t){
        return v * (1/t);
    }
};

using Point3 = Vec3;
using Color = Vec3;

#endif //RAYTRACER_VEC3_H
