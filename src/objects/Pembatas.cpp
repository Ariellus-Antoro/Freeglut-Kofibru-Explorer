#include "objects/Pembatas.h"

Pembatas::Pembatas() {
    posX = 0.0f;
    posY = 0.0f;
    posZ = 5.0f;
    rotationY = 0.0f;

    length = 3.0f;
    height = 0.9f;
    thickness = 0.5f;

    colorR = 0.85f;
    colorG = 0.85f;
    colorB = 0.85f;
}

void Pembatas::drawAll() {
    glPushMatrix();
        glTranslatef(posX, posY, posZ);
        glRotatef(rotationY, 0.0f, 1.0f, 0.0f);
        glColor3f(colorR, colorG, colorB);

        glPushMatrix();
            glTranslatef(0.0f, height * 0.5f, length * 0.5f);
            glScalef(thickness, height, length);
            glutSolidCube(1.0);
        glPopMatrix();
    glPopMatrix();
}