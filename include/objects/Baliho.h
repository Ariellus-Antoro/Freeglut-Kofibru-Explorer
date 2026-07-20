#ifndef BALIHO_H
#define BALIHO_H

#include <GL/freeglut.h>

class Baliho {
public:
    Baliho();
    void drawAll();

    // Posisi dan Rotasi
    float posX, posY, posZ;
    float rotationY;

    // Dimensi Baliho
    float width, height, thickness; 

private:
    float colorTiangR, colorTiangG, colorTiangB;
};

#endif