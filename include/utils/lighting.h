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

    void setupFloor1DownlightWastafel();
    void setupFloor1downlightWc();
    void setupFloor1downlightOutdoor();
    void setupFloor1downlightOutdoor2();

    void setupFloor2Light();
    void setupFloor2RightLight();
    void setupFloor2OutdoorLight();

    void setupFloor3Light(); 
    void setupFloor3LightOutdoor();
};

#endif