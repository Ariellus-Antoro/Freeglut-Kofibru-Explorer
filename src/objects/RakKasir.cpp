#include "objects/RakKasir.h"

RakKasir::RakKasir()
{

}
void RakKasir::drawBlock(
    float width,
    float height,
    float depth,
    float r,
    float g,
    float b)
{
    glPushMatrix();

    glColor3f(r, g, b);

    glScalef(width, height, depth);

    glutSolidCube(1.0f);

    glPopMatrix();
}


void RakKasir::drawShelf()
{
    glPushMatrix();

    drawBlock(
        8.0f,
        0.15f,
        1.0f,
        1.0f,
        1.0f,
        1.0f);

    glPopMatrix();
}
void RakKasir::drawBracket()
{
    // kiri
    glPushMatrix();

    glTranslatef(-3.5f,-0.45f,0.0f);

    drawBlock(
        0.12f,
        0.9f,
        0.12f,
        0.8f,
        0.8f,
        0.8f);

    glPopMatrix();

    // kanan
    glPushMatrix();

    glTranslatef(3.5f,-0.45f,0.0f);

    drawBlock(
        0.12f,
        0.9f,
        0.12f,
        0.8f,
        0.8f,
        0.8f);

    glPopMatrix();
}
void RakKasir::drawMenus()
{
    for(int i = 0; i < 10; i++)
    {
        glPushMatrix();

        glTranslatef(-3.4f + i * 0.75f,
                     0.30f,
                     0.0f);

        glScalef(0.45f,0.45f,0.20f);

        kotakRak.draw();

        glPopMatrix();
    }
}

void RakKasir::draw()
{
    drawShelf();

    // drawBracket();

    drawMenus();
}