#ifndef WASTAFEL_H
#define WASTAFEL_H

#include <GL/freeglut.h>
#include "utils/ModelLoader.h"

/**
 * @class Wastafel
 * @brief Menangani rendering objek 3D wastafel hasil import dari Fusion 360.
 */
class Wastafel {
public:
    Wastafel();
    void drawAll();

    float posX, posY, posZ;
    float targetHeight;
    float rotationY;
    float colorR, colorG, colorB;

private:
    ModelLoader model;
};

#endif