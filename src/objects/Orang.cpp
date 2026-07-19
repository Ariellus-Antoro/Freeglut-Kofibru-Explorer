#include "objects/Orang.h"

Orang::Orang() {
    posX = 0.0f; 
    posY = 0.0f; 
    posZ =-3.7f;
    rotationY = 0.0f;

    targetHeight = 1.6f; // Tinggi rata-rata orang

    colorR = 0.8f; colorG = 0.7f; colorB = 0.6f; // Warna kulit

    model.loadOBJ("src/models/Orang.obj");
}

void Orang::drawAll() {
    float h = model.getHeight();
    if (h <= 0.0f) return;
    float scale = targetHeight / h;

    glPushMatrix();
        glTranslatef(posX, posY, posZ);
        glRotatef(rotationY, 0.0f, 1.0f, 0.0f);
        glScalef(scale, scale, scale);
        // Memindahkan pivot ke pusat bawah objek
        glTranslatef(-model.getMinX(), -model.getMinY(), -model.getMinZ());
        glColor3f(colorR, colorG, colorB);
        model.draw();
    glPopMatrix();
}