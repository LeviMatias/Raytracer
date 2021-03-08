//
// Created by Matias Ignacio Levi Fernandez on 08/03/2021.
//

#ifndef RAYTRACER_VEC3_H
#define RAYTRACER_VEC3_H

#include <cmath>
#include <iostream>

#define COORDINATES 3

using std::sqrt;

class vec3 {
public:
    double e[COORDINATES];

    vec3(): e{0, 0, 0} {};

    vec3(double x, double y, double z) :e{x, y, z} {};

    double x() const { return e[0]; }
    double y() const { return e[1]; }
    double z() const { return e[2]; }

    double length() const {
        return sqrt(length_squared());
    }

    double length_squared() const {
        return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
    }

    inline vec3 unit(){
        return *this/this->length();
    }

    inline double dot(const vec3 &v){
        return e[0] * v.e[0]
               + e[1] * v.e[1]
               + e[2] * v.e[2];
    }

    // OPERATORS

    vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
    double operator[](int i) const { return e[i]; }
    double& operator[](int i) { return e[i]; }


    vec3& operator+=(const vec3 &v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }

    vec3& operator*=(const double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    vec3& operator/=(const double t) {
        return *this *= 1/t;
    }

    friend vec3 operator*(const vec3 &u, const vec3 &v){
        return vec3(u[0]*v[0] , u[1]*v[1] , u[2]*v[2]);
    }

    friend vec3 operator*(const vec3 &u, const double &t){
        return vec3(u[0]*t , u[1]*t , u[2]*t);
    }

    friend vec3 operator*(const double &t, const vec3 &v){
        return v*t;
    }

    friend vec3 operator+(const vec3 &u, const vec3 &v){
        return vec3(u[0]+v[0] , u[1]+v[1] , u[2]+v[2]);
    }

    friend vec3 operator-(const vec3 &u, const vec3 &v){
        return vec3(u[0]-v[0] , u[1]-v[1] , u[2]-v[2]);
    }

    friend vec3 operator/(const vec3 &v, const double &t){
        return v * (1/t);
    }
};

using poin3 = vec3;
using color = vec3;

#endif //RAYTRACER_VEC3_H
