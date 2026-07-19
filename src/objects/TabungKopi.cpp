#include "objects/TabungKopi.h"

TabungKopi::TabungKopi() {
    posX = -0.65f; 
    posY = 1.2f; 
    posZ = -3.1f;
    rotationY = 0.0f;

    targetHeight = 0.4f;

    colorR = 0.8f; colorG = 0.8f; colorB = 0.8f; // Warna kaca/transparan
    
    model.loadOBJ("src/models/TabungKopi.obj");
}

void TabungKopi::drawAll() {
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