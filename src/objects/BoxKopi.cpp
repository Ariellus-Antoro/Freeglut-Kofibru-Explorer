#include "objects/BoxKopi.h"

BoxKopi::BoxKopi() {
    posX = 0.0f;
    posY = 0.8f;
    posZ = -3.0f;
    rotationX = 0.0f;
    rotationY = 0.0f;
    rotationZ = 0.0f;

    length = 0.5f;
    width = 0.5f;
    height = 0.5f;

    colorR = 0.0f;
    colorG = 0.0f;
    colorB = 1.0f;

    model.loadOBJ("src/models/BoxKopi.obj");
}

void BoxKopi::drawAll() {
    float originalWidth = model.getWidth();
    float originalHeight = model.getHeight();
    float originalDepth = model.getDepth();

    if (originalHeight <= 0.0f) return;

    float scaleX = (originalWidth > 0.0f) ? (width / originalWidth) : 1.0f;
    float scaleY = height / originalHeight;
    float scaleZ = (originalDepth > 0.0f) ? (length / originalDepth) : 1.0f;

    glPushMatrix();
        glTranslatef(posX, posY, posZ);
        glRotatef(rotationX, 1.0f, 0.0f, 0.0f);
        glRotatef(rotationY, 0.0f, 1.0f, 0.0f);
        glRotatef(rotationZ, 0.0f, 0.0f, 1.0f);
        glScalef(scaleX, scaleY, scaleZ);
        glTranslatef(-model.getMinX(), -model.getMinY(), -model.getMinZ());
        glColor3f(colorR, colorG, colorB);
        model.draw();
    glPopMatrix();
}