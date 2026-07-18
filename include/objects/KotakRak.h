#ifndef KOTAKRAK_H
#define KOTAKRAK_H

#include <GL/freeglut.h>

class KotakRak
{
public:
    KotakRak();

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