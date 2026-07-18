#ifndef TANGGA_H
#define TANGGA_H

#include <GL/freeglut.h>

class Tangga {
public:
    Tangga();
    void draw(float posX, float posY, float posZ);

private:
    void drawStep(float w, float h, float d, float r, float g, float b);
    void drawPole(float radius, float h, float r, float g, float b);
};
#endif