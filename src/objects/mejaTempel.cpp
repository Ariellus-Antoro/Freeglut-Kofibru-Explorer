
#include "objects/mejaTempel.h"

MejaTempel::MejaTempel()
{

}

void MejaTempel::drawBlock(float width,
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

void MejaTempel::draw()
{
    glPushMatrix();

    drawBlock(
        14.0f,   // panjang
        0.18f,  // tebal
        1.20f,  // lebar
        0.96f,  // putih agak doff
        0.96f,
        0.96f
    );

    glPopMatrix();
}