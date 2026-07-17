#include "objects/KursiBulat.h"

// Constructor
KursiBulat::KursiBulat()
{
}

// Helper untuk menggambar silinder
void KursiBulat::drawCylinder(float radius,
                              float height,
                              float r,
                              float g,
                              float b)
{
    glPushMatrix();

    glColor3f(r, g, b);

    // GLU Cylinder mengarah ke sumbu Z
    // Diputar supaya tegak di sumbu Y
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);

    GLUquadric *quad = gluNewQuadric();

    gluCylinder(quad, radius, radius, height, 32, 1);

    // Tutup bawah
    gluDisk(quad, 0.0f, radius, 32, 1);

    // Tutup atas
    glTranslatef(0.0f, 0.0f, height);
    gluDisk(quad, 0.0f, radius, 32, 1);

    gluDeleteQuadric(quad);

    glPopMatrix();
}

// Menggambar kursi
void KursiBulat::draw()
{
    //------------------------
    // Dudukan
    //------------------------
    glPushMatrix();
        glTranslatef(0.0f, 3.6f, 0.0f);
        drawCylinder(2.0f, 0.3f, 0.8f, 0.8f, 0.8f);
    glPopMatrix();

    float x = 1.2f;
    float z = 1.2f;

    //------------------------
    // Kaki 1
    //------------------------
    glPushMatrix();
        glTranslatef(-x, -1.5f, -z);
        drawCylinder(0.15f, 5.0f, 0.3f, 0.3f, 0.3f);
    glPopMatrix();

    //------------------------
    // Kaki 2
    //------------------------
    glPushMatrix();
        glTranslatef(x, -1.5f, -z);
        drawCylinder(0.15f, 5.0f, 0.3f, 0.3f, 0.3f);
    glPopMatrix();

    //------------------------
    // Kaki 3
    //------------------------
    glPushMatrix();
        glTranslatef(-x, -1.5f, z);
        drawCylinder(0.15f, 5.0f, 0.3f, 0.3f, 0.3f);
    glPopMatrix();

    //------------------------
    // Kaki 4
    //------------------------
    glPushMatrix();
        glTranslatef(x, -1.5f, z);
        drawCylinder(0.15f, 5.0f, 0.3f, 0.3f, 0.3f);
    glPopMatrix();
}