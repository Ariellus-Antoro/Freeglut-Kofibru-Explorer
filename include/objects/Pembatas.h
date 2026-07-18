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

    float posX, posY, posZ;   ///< Posisi titik awal (kiri-bawah-belakang) balok
    float rotationY;          ///< Rotasi balok di sumbu Y (derajat)
    float length;             ///< Panjang balok (sepanjang sumbu lokal setelah rotasi)
    float height;             ///< Tinggi balok
    float thickness;          ///< Ketebalan/lebar balok
    float colorR, colorG, colorB;
};

#endif