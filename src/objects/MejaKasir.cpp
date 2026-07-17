#include "objects/MejaKasir.h"

//
MejaKasir::MejaKasir()
{

}

void MejaKasir::drawBlock(
                   float width,
                   float height,
                   float depth,
                   float r,
                   float g,
                   float b
){
    glPushMatrix();

    glColor3f(r,g,b);

    glScalef(width,height,depth);

    glutSolidCube(1.0f);

    glPopMatrix();
}

void MejaKasir::draw()
{
   // ==========================
    // Bagian bawah (Abu-abu)
    // ==========================
    glPushMatrix();
        glTranslatef(0.0f, 0.5f, 0.0f);
        drawBlock(
            15.0f,   // lebar
            1.0f,   // tinggi
            1.5f,   // kedalaman
            0.66f, 0.66f, 0.66f   // abu-abu
        );
    glPopMatrix();

    // ==========================
    // Bagian atas (Putih)
    // ==========================
    glPushMatrix();
        glTranslatef(0.0f, 1.5f, 0.0f);
        drawBlock(
            15.0f,
            1.0f,
            1.5f,
            1.0f, 1.0f, 1.0f   // putih
        );
    glPopMatrix();
}