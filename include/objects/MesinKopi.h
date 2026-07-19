#ifndef MESINKOPI_H
#define MESINKOPI_H

#include <GL/freeglut.h>
#include "utils/ModelLoader.h"

class MesinKopi {
public:
    MesinKopi();
    void drawAll();

    float posX, posY, posZ;
    float targetHeight;
    float rotationY;
    float colorR, colorG, colorB;

private:
    ModelLoader model;
};

#endif