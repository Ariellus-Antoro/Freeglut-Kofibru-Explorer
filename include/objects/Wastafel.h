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

    /**
     * @brief Menggambar wastafel pada posisi yang sudah diatur.
     * Panggil dari display() di main.cpp.
     */
    void drawAll();

private:
    ModelLoader model;

    float posX, posY, posZ;   ///< Posisi anchor (kiri-bawah-belakang bounding box)
    float targetHeight;       ///< Tinggi target di scene; scale dihitung otomatis dari bounding box
    float rotationY;          ///< Rotasi objek di sumbu Y (derajat)
    float colorR, colorG, colorB;
};

#endif