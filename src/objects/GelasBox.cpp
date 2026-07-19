#include "objects/GelasBox.h"

GelasBox::GelasBox() {
    posX = 0.8f;
    posY = 0.0f;
    posZ = 0.0f;
    rotationX = 0.0f;
    rotationY = 0.0f;
    rotationZ = 0.0f;

    length = 0.1f;
    width = 0.1f;
    height = 0.5f;

    colorR = 1.0f;
    colorG = 0.0f;
    colorB = 0.0f;

    model.loadOBJ("src/models/GelasBox.obj");
}

void GelasBox::drawAll() {
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