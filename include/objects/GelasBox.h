#ifndef GELASBOX_H
#define GELASBOX_H

#include <GL/freeglut.h>
#include "utils/ModelLoader.h"

/**
 * @class GelasBox
 * @brief Menangani rendering objek 3D box gelas hasil import dari Fusion 360.
 */
class GelasBox {
public:
    GelasBox();
    void drawAll();

    float posX, posY, posZ;
    float length, width, height;
    float rotationX, rotationY, rotationZ;
    float colorR, colorG, colorB;

private:
    ModelLoader model;
};

#endif