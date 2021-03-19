cmake_minimum_required(VERSION 3.17)
project(raytracer)
set(CMAKE_CXX_FLAGS_RELEASE "/O2")
set(CMAKE_CXX_STANDARD 17)


add_executable(raytracer main.cpp utility/safe_stream.h utility/safe_stream.cpp utility/Vec3.h utility/Ray.h model/Camera.cpp model/Camera.h model/Hittable.h model/Sphere.cpp model/Sphere.h model/Scene.cpp model/Scene.h utility/Utility.h utility/Random.h model/Image.cpp model/Image.h model/concurrency/BaseThread.cpp model/concurrency/BaseThread.h model/concurrency/draw_thread.cpp model/concurrency/draw_thread.h model/concurrency/LambdaThread.h utility/stopwatch.cpp utility/stopwatch.h model/concurrency/StatusThread.h)