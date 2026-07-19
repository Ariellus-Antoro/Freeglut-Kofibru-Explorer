#ifndef TABUNGKOPI_H
#define TABUNGKOPI_H

#include <GL/freeglut.h>
#include "utils/ModelLoader.h"

class TabungKopi {
public:
    TabungKopi();
    void drawAll();

    float posX, posY, posZ;
    float targetHeight;
    float rotationY;
    float colorR, colorG, colorB;

private:
    ModelLoader model;
};

#endif