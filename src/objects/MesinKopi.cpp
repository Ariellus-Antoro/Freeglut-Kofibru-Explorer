#include "objects/MesinKopi.h"

MesinKopi::MesinKopi() {
    posX = -0.6f; 
    posY = 0.8f; 
    posZ = -3.0f;
    rotationY = 0.0f;

    targetHeight = 0.4f;
    
    colorR = 0.5f; colorG = 0.5f; colorB = 0.5f; // Warna logam/abu-abu

    model.loadOBJ("src/models/MesinKopi.obj");
}

void MesinKopi::drawAll() {
    float h = model.getHeight();
    if (h <= 0.0f) return;
    float scale = targetHeight / h;

    glPushMatrix();
        glTranslatef(posX, posY, posZ);
        glRotatef(rotationY, 0.0f, 1.0f, 0.0f);
        glScalef(scale, scale, scale);
        glTranslatef(-model.getMinX(), -model.getMinY(), -model.getMinZ());
        glColor3f(colorR, colorG, colorB);
        model.draw();
    glPopMatrix();
}