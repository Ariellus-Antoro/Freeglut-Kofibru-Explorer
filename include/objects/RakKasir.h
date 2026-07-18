#ifndef RAKKASIR_H
#define RAKKASIR_H

#include <GL/freeglut.h>
#include "objects/KotakRak.h"

class RakKasir
{
public:
    RakKasir();

    // Menggambar 1 buah rak lengkap
    void draw();

private:
    KotakRak kotakRak;

    // Primitive helper
    void drawBlock(float width,
                   float height,
                   float depth,
                   float r,
                   float g,
                   float b);

    // Komponen rak
    void drawShelf();      // papan rak
    void drawBracket();    // penyangga rak
    void drawMenus();      // deretan menu di atas rak
};

#endif