#ifndef TOILET_H
#define TOILET_H

#include <GL/freeglut.h>
#include "utils/ModelLoader.h"

/**
 * @class Toilet
 * @brief Menangani rendering objek 3D toilet hasil import dari Fusion 360.
 */
class Toilet {
public:
    Toilet();
    void drawAll();

    float posX, posY, posZ;
    float targetHeight;
    float rotationY;
    float colorR, colorG, colorB;

private:
    ModelLoader model;
};

#endif