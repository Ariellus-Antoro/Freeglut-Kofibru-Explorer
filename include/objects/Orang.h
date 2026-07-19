#ifndef ORANG_H
#define ORANG_H

#include <GL/freeglut.h>
#include "utils/ModelLoader.h"

class Orang {
public:
    Orang();
    void drawAll();

    float posX, posY, posZ;
    float targetHeight;
    float rotationY;
    float colorR, colorG, colorB;

private:
    ModelLoader model;
};

#endif