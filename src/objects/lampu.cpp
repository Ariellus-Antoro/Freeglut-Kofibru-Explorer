#include "objects/lampu.h"

Lampu::Lampu()
{
}

void Lampu::drawBlock(float width,
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

void Lampu::draw()
{
    // ==========================
    // Dudukan Lampu (Abu-abu)
    // ==========================
    glPushMatrix();

    glTranslatef(0.0f, 0.05f, 0.0f);

    drawBlock(
        3.0f,   // panjang
        0.10f,  // tinggi
        0.60f,  // lebar
        0.75f, 0.75f, 0.75f
    );

    glPopMatrix();

    // ==========================
    // Diffuser LED (Putih)
    // ==========================
    glPushMatrix();

    glTranslatef(0.0f, -0.02f, 0.0f);

    drawBlock(
        2.8f,
        0.08f,
        0.45f,
        1.0f, 1.0f, 1.0f
    );

    glPopMatrix();
}