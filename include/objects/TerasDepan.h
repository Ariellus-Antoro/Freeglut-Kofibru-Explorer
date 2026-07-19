#ifndef TERASDEPAN_H
#define TERASDEPAN_H

#include <GL/freeglut.h>
#include "utils/ModelLoader.h"

/**
 * @class TerasDepan
 * @brief Menangani rendering objek 3D teras depan hasil import dari Fusion 360.
 */
class TerasDepan {
public:
    TerasDepan();
    void drawAll();

    float posX, posY, posZ;
    float length, width, height;   // ukuran target per sumbu (length=panjang/Z, width=lebar/X, height=tinggi/Y)
    float rotationX, rotationY, rotationZ;
    float colorR, colorG, colorB;

private:
    ModelLoader model;
};

#endif