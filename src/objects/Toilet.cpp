#include "objects/Toilet.h"

Toilet::Toilet() {
    // Sesuaikan koordinat posisi toiletmu di sini
    posX = 4.0f; 
    posY = 0.0f; 
    posZ = -4.7f;
    rotationY = 0.0f;

    targetHeight = 1.0f; // Sesuaikan skala tinggi toilet

    colorR = 0.95f;
    colorG = 0.95f;
    colorB = 0.95f;

    // Pastikan file modelnya ada di path ini
    model.loadOBJ("src/models/Toilet2.obj");
}

void Toilet::drawAll() {
    float h = model.getHeight();
    if (h <= 0.0f) return;

    float scale = targetHeight / h;

    glPushMatrix();
        glTranslatef(posX, posY, posZ);
        glRotatef(rotationY, 0.0f, 1.0f, 0.0f);
        glScalef(scale, scale, scale);
        // Menyesuaikan posisi model agar menempel di tanah berdasarkan koordinat minimum
        glTranslatef(-model.getMinX(), -model.getMinY(), -model.getMinZ());
        glColor3f(colorR, colorG, colorB);
        model.draw();
    glPopMatrix();
}