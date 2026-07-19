#include "objects/Wastafel.h"

Wastafel::Wastafel() {
    posX = 4.9f;
    posY = 0.8f;
    posZ = 0.75f;
    rotationY = 90.0f;

    targetHeight = 0.6f;

    colorR = 0.9f;
    colorG = 0.9f;
    colorB = 0.9f;

    model.loadOBJ("src/models/Wastafel.obj");
}

void Wastafel::drawAll() {
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