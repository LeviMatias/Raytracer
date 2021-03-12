cmake_minimum_required(VERSION 3.17)
project(raytracer)

set(CMAKE_CXX_STANDARD 17)

add_executable(raytracer main.cpp utility/safe_stream.h utility/safe_stream.cpp utility/Vec3.h utility/color_helper.h utility/Ray.h model/Camera.cpp model/Camera.h model/Hittable.h model/Sphere.cpp model/Sphere.h model/Scene.cpp model/Scene.h utility/Utility.h utility/Random.h model/Image.cpp model/Image.h utility/BaseThread.cpp utility/BaseThread.h model/painter_thread.cpp model/painter_thread.h)