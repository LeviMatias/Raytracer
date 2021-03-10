cmake_minimum_required(VERSION 3.17)
project(raytracer)

set(CMAKE_CXX_STANDARD 17)

add_executable(raytracer main.cpp utility/safe_stream.h utility/safe_stream.cpp utility/vec3.h utility/color_helper.h utility/ray.h model/Camera.cpp model/Camera.h model/Hittable.cpp model/Hittable.h model/Sphere.cpp model/Sphere.h)