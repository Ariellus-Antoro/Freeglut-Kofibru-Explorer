#ifndef KOFIBRU_H
#define KOFIBRU_H

#include <GL/freeglut.h>
#include "utils/ModelLoader.h"

/**
 * @class Kofibru
 * @brief Menangani rendering logo 3D "KOFIBRU" hasil import dari Fusion 360.
 * Logo terdiri dari 7 huruf terpisah (K, O, F, I, B, R, U) plus 2 titik
 * kecil (t1, t2) di atas huruf U. Ukuran tiap huruf dinormalisasi otomatis
 * berdasarkan bounding box-nya, supaya semua huruf tampil dengan tinggi
 * yang seragam walau file OBJ aslinya punya skala berbeda-beda.
 */
class Kofibru {
public:
    Kofibru();
    void drawAll();

private:
    ModelLoader modelK, modelO, modelF, modelI, modelB, modelR, modelU;
    ModelLoader modelT1, modelT2;

    float posX, posY, posZ;
    float targetHeight;
    float letterSpacing;
    float dotHeightAboveLetter;
    float dotSize;
    float rotationY;

    float drawLetterNormalized(ModelLoader& model, float cursorOffset,
                                 float colorRed, float colorGreen, float colorBlue);
    void drawDot(ModelLoader& model, float cursorOffset, float liftHeight,
                  float colorRed, float colorGreen, float colorBlue);
};

#endif