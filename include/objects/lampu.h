#ifndef LAMPU_H
#define LAMPU_H

#include <GL/freeglut.h>

class Lampu
{
public:
    Lampu();

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