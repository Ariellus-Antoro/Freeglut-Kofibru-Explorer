#include "objects/KotakRak.h"

KotakRak::KotakRak()
{

}
void KotakRak::drawBlock(
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

void KotakRak::draw()
{
    glPushMatrix();

    drawBlock(
        0.8f,   // lebar
        1.0f,   // tinggi
        0.8f,   // kedalaman
        0.45f,  // merah
        0.28f,  // hijau
        0.12f   // biru
    );

    glPopMatrix();
}