#ifndef BOXKOPI_H
#define BOXKOPI_H

#include <GL/freeglut.h>
#include "utils/ModelLoader.h"

/**
 * @class BoxKopi
 * @brief Menangani rendering objek 3D box kopi hasil import dari Fusion 360.
 */
class BoxKopi {
public:
    BoxKopi();
    void drawAll();

    float posX, posY, posZ;
    float length, width, height;
    float rotationX, rotationY, rotationZ;
    float colorR, colorG, colorB;

private:
    ModelLoader model;
};

#endif