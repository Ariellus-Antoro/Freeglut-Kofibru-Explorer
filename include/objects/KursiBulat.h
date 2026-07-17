#ifndef KURSIBULAT_H
#define KURSIBULAT_H


#include <GL/freeglut.h>

class KursiBulat
{
public:
    KursiBulat();

    void draw();
private:
     void drawCylinder(float radius,
                      float height,
                      float r,
                      float g,
                      float b);
};

#endif