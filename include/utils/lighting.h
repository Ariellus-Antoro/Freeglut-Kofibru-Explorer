#ifndef LIGHTING_H
#define LIGHTING_H

#include <GL/freeglut.h>

class Lighting
{
public:
    Lighting();

    void initialize();

    void update();

private:

    void setupFloor1Light();

    // void setupFloor2Light();

    // void setupFloor3Light();
};

#endif