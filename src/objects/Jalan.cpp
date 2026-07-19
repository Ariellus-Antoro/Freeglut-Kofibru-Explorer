#include "objects/Jalan.h"

Jalan::Jalan() {
    // Default posisi
    posX = 0.0f; posY = 0.0f; posZ = 0.0f;
    rotationY = 0.0f;

    // Ukuran default
    width = 5.0f;
    height = 0.1f; // Sangat tipis karena jalan menempel di tanah
    length = 10.0f;

    // Warna aspal (abu-abu gelap)
    colorR = 0.2f; 
    colorG = 0.2f; 
    colorB = 0.2f;
}

void Jalan::drawAll() {
    glPushMatrix();
        // Geser ke posisi yang ditentukan
        glTranslatef(posX, posY, posZ);
        
        // Putar jika diperlukan
        glRotatef(rotationY, 0.0f, 1.0f, 0.0f);
        
        // Set warna aspal
        glColor3f(colorR, colorG, colorB);
        
        // Atur ukuran jalan (merubah kubus 1x1x1 menjadi persegi panjang pipih)
        glScalef(width, height, length);
        
        // Gambar kotaknya
        glutSolidCube(1.0);
    glPopMatrix();
}