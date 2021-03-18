//
// Created by Matias Ignacio Levi Fernandez on 12/03/2021.
//

#ifndef RAYTRACER_BASETHREAD_H
#define RAYTRACER_BASETHREAD_H

#include <thread>
#include <atomic>

class BaseThread {
    std::thread t;
    std::atomic<bool> alive;
    bool running;

protected:
    virtual void _run() = 0;
public:

    BaseThread();

    void run();

    bool isAlive();

    bool isRunning();

    //POS closes the thread and prepares to join
    //isAlive returns false
    virtual void close();

    void sleep(float seconds);

    void join();

    BaseThread(BaseThread&& other);

    BaseThread& operator=(BaseThread&& other);

};


#endif //RAYTRACER_BASETHREAD_H
