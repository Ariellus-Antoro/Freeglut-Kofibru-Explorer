#ifndef MEJAKASIR_H
#define MEJAKASIR_H


#include <GL/freeglut.h>

class MejaKasir
{
public:
    MejaKasir();

    void draw();
private:
    void drawBlock(float width,
                   float height,
                   float depth,
                   float r,
                   float g,
                   float b);
};

#endif