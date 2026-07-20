#include "../../include/objects/Baliho.h"

Baliho::Baliho() {
    // Default posisi
    posX = 50.0f; 
    posY = 0.0f; 
    posZ = .0f;
    rotationY = 90.0f;

    // Default ukuran
    width = 3.0f;
    height = 5.0f;
    thickness = 0.1f;

    // Warna
    colorTiangR = 0.4f; colorTiangG = 0.4f; colorTiangB = 0.4f;
}

void Baliho::drawAll() {
    glPushMatrix();
        glTranslatef(posX, posY, posZ);
        glRotatef(rotationY, 0.0f, 1.0f, 0.0f);

        // 1. Tiang (dua tiang penyangga)
        glColor3f(colorTiangR, colorTiangG, colorTiangB);
        
        // Tiang kiri
        glPushMatrix();
            glTranslatef(-1.2f, 2.0f, 0.0f);
            glScalef(0.2f, 4.0f, 0.2f);
            glutSolidCube(1.0);
        glPopMatrix();

        // Tiang kanan
        glPushMatrix();
            glTranslatef(1.2f, 2.0f, 0.0f);
            glScalef(0.2f, 4.0f, 0.2f);
            glutSolidCube(1.0);
        glPopMatrix();

        // 2. Papan Baliho
        glPushMatrix();
            glTranslatef(0.0f, 4.5f, 0.0f);
            glColor3f(1.5f, 0.0f, 0.0f); // Papan putih
            glScalef(width, height, thickness);
            glutSolidCube(1.0);
        glPopMatrix();

    glPopMatrix();
}