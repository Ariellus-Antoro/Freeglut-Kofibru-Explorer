#ifndef MENU_H
#define MENU_H

#include <GL/freeglut.h>

class Menu
{
public:
    Menu();

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