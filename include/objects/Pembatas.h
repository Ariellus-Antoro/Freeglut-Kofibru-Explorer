#ifndef PEMBATAS_H
#define PEMBATAS_H

#include <GL/freeglut.h>

/**
 * @class Pembatas
 * @brief Menggambar satu balok panjang pembatas (railing/partition).
 * Untuk membuat jalur berbelok, buat beberapa instance Pembatas dan atur
 * posisi + rotasi tiap instance supaya nyambung membentuk rute yang diinginkan.
 */
class Pembatas {
public:
    Pembatas();
    void drawAll();

    float posX, posY, posZ;
    float rotationY;
    float length;
    float height;
    float thickness;
    float colorR, colorG, colorB;
};

#endif