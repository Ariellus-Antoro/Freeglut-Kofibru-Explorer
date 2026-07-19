#include "objects/Rumput.h"

Rumput::Rumput() {
    posX = 0.0f; posY = 0.0f; posZ = 0.0f;
    rotationY = 0.0f;
    length = 3.0f;
    height = 0.2f;      // Rumput lebih tipis
    thickness = 0.4f;   // Lebih kecil dari pembatas
    
    colorR = 0.1f; colorG = 0.6f; colorB = 0.1f; // Warna hijau
}

void Rumput::drawAll() {
    glPushMatrix();
        glTranslatef(posX, posY, posZ);
        glRotatef(rotationY, 0.0f, 1.0f, 0.0f);
        glColor3f(colorR, colorG, colorB);
        
        glScalef(thickness, height, length);
        glutSolidCube(1.0);
    glPopMatrix();
}