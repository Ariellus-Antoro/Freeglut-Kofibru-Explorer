#ifndef RUMPUT_H
#define RUMPUT_H

#include <GL/freeglut.h>

class Rumput {
public:
    Rumput();
    void drawAll();

    float posX, posY, posZ;
    float rotationY;
    float length, height, thickness; // Ukuran rumput

private:
    float colorR, colorG, colorB;
};

#endif