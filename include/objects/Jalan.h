#ifndef JALAN_H
#define JALAN_H

#include <GL/freeglut.h>
//jalan
class Jalan {
public:
    Jalan();
    void drawAll();

    // Posisi dan Rotasi
    float posX, posY, posZ;
    float rotationY;

    // Dimensi jalan
    float length, width, height;

private:
    float colorR, colorG, colorB; // Untuk warna aspal
};

#endif