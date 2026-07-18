#include "objects/Pembatas.h"

Pembatas::Pembatas()
{
    posX = 15.0f;
    posY = 0.0f;
    posZ = 1.0f;
    rotationY = 0.0f;

    length = 3.0f;
    height = 0.9f;
    thickness = 0.1f;

    colorR = 1.f;
    colorG = 1.f;
    colorB = 1.f;
}

void Pembatas::drawAll()
{
    glPushMatrix();
    glTranslatef(posX, posY, posZ);
    glRotatef(rotationY, 0.0f, 1.0f, 0.0f);
    glColor3f(colorR, colorG, colorB);

    // Balok digambar memanjang di sumbu Z lokal, mulai dari origin (0,0,0)
    // sampai (0,0,length) — jadi posX/posY/posZ itu titik AWAL balok.
    glPushMatrix();
    glTranslatef(0.0f, height * 0.5f, length * 0.5f);
    glScalef(thickness, height, length);
    glutSolidCube(1.0);
    glPopMatrix();
    glPopMatrix();
}