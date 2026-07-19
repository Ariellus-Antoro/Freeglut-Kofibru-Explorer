#ifndef MEJATEMPEL_H
#define MEJATEMPEL_H

#include <GL/freeglut.h>

class MejaTempel
{
public:
    MejaTempel();

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