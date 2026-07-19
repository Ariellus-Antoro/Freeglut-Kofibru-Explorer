#include "objects/downlight.h"

Downlight::Downlight()
{
    quad = gluNewQuadric();
}

void Downlight::drawCylinder(float radius,
                             float height,
                             float r,
                             float g,
                             float b)
{
    glColor3f(r, g, b);

    gluCylinder(
        quad,
        radius,
        radius,
        height,
        32,
        1
    );
}

void Downlight::drawDisk(float radius,
                         float r,
                         float g,
                         float b)
{
    glColor3f(r, g, b);

    gluDisk(
        quad,
        0.0,
        radius,
        32,
        1
    );
}

void Downlight::drawSphere(float radius,
                           float r,
                           float g,
                           float b)
{
    glColor3f(r, g, b);

    glutSolidSphere(
        radius,
        32,
        32
    );
}

void Downlight::draw()
{
    //-----------------------------------
    // Ring luar putih
    //-----------------------------------
    glPushMatrix();

    glRotatef(-90.0f,1.0f,0.0f,0.0f);

    drawCylinder(
        0.50f,
        0.10f,
        1.0f,
        1.0f,
        1.0f
    );

    glPopMatrix();


    //-----------------------------------
    // Tutup depan
    //-----------------------------------
    glPushMatrix();

    glRotatef(-90.0f,1.0f,0.0f,0.0f);

    drawDisk(
        0.50f,
        1.0f,
        1.0f,
        1.0f
    );

    glPopMatrix();


    //-----------------------------------
    // Reflektor abu-abu
    //-----------------------------------
    glPushMatrix();

    glTranslatef(0.0f,-0.05f,0.0f);

    glRotatef(-90.0f,1.0f,0.0f,0.0f);

    glColor3f(1.0f,1.0f,1.0f);

    gluCylinder(
        quad,
        0.40,
        0.25,
        0.30,
        32,
        1
    );

    glPopMatrix();


    // //-----------------------------------
    // // LED
    // //-----------------------------------
    // glPushMatrix();

    // glTranslatef(0.0f,-0.18f,0.0f);

    // drawSphere(
    //     0.12f,
    //     1.0f,
    //     1.0f,
    //     0.9f
    // );

    // glPopMatrix();
}