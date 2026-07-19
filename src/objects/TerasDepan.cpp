#include "objects/TerasDepan.h"

TerasDepan::TerasDepan() {
    posX = 0.0f;
    posY = 0.0f;
    posZ = 0.0f;
    rotationX = 0.0f;
    rotationY = 0.0f;
    rotationZ = 0.0f;

    length = 8.5f;
    width = 4.5f;
    height = 1.0f;

    colorR = 0.7f;
    colorG = 0.7f;
    colorB = 0.7f;

    model.loadOBJ("src/models/TerasDepan.obj");
}

void TerasDepan::drawAll() {
    float originalWidth = model.getWidth();   // sumbu X model asli
    float originalHeight = model.getHeight();  // sumbu Y model asli
    float originalDepth = model.getDepth();    // sumbu Z model asli

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