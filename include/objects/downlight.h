#ifndef DOWNLIGHT_H
#define DOWNLIGHT_H

#include <GL/freeglut.h>
#include <GL/glu.h>

class Downlight
{
public:
    Downlight();

    void draw();

private:
    GLUquadric* quad;

    void drawCylinder(float radius,
                      float height,
                      float r,
                      float g,
                      float b);

    void drawDisk(float radius,
                  float r,
                  float g,
                  float b);

    void drawSphere(float radius,
                    float r,
                    float g,
                    float b);
};

#endif