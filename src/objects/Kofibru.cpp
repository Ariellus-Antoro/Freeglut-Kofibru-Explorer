#include "objects/Kofibru.h"
#include <fstream>

Kofibru::Kofibru() {
    posX = 9.7f;
    posY = 0.9f;
    posZ = 4.0f;
    rotationY = 90.0f;

    targetHeight = 0.8f;
    letterSpacing = 0.15f;
    dotHeightAboveLetter = 0.15f;
    dotSize = 0.12f;

    modelK.loadOBJ("src/objects/K.obj");
    modelO.loadOBJ("src/objects/O.obj");
    modelF.loadOBJ("src/objects/F.obj");
    modelI.loadOBJ("src/objects/I.obj");
    modelB.loadOBJ("src/objects/B.obj");
    modelR.loadOBJ("src/objects/R.obj");
    modelU.loadOBJ("src/objects/U.obj");
    modelT1.loadOBJ("src/objects/t1.obj");
    modelT2.loadOBJ("src/objects/t2.obj");
}

float Kofibru::drawLetterNormalized(ModelLoader& model, float cursorOffset,
                                      float colorRed, float colorGreen, float colorBlue) {
    float h = model.getHeight();
    if (h <= 0.0f) return 0.0f;

    float scale = targetHeight / h;
    float scaledWidth = model.getWidth() * scale;

    glPushMatrix();
        glTranslatef(cursorOffset, 0.0f, 0.0f);
        glScalef(scale, scale, scale);
        glTranslatef(-model.getMinX(), -model.getMinY(), -model.getMinZ());
        glColor3f(colorRed, colorGreen, colorBlue);
        model.draw();
    glPopMatrix();

    return scaledWidth;
}

void Kofibru::drawDot(ModelLoader& model, float cursorOffset, float liftHeight,
                        float colorRed, float colorGreen, float colorBlue) {
    float h = model.getHeight();
    if (h <= 0.0f) return;

    float scale = dotSize / h;

    glPushMatrix();
        glTranslatef(cursorOffset, liftHeight, 0.0f);
        glScalef(scale, scale, scale);
        glTranslatef(-model.getMinX(), -model.getMinY(), -model.getMinZ());
        glColor3f(colorRed, colorGreen, colorBlue);
        model.draw();
    glPopMatrix();
}

void Kofibru::drawAll() {
    float grey = 0.85f;
    float cursor = 0.0f;

    glPushMatrix();
        glTranslatef(posX, posY, posZ);
        glRotatef(rotationY, 0.0f, 1.0f, 0.0f);

        cursor += drawLetterNormalized(modelK, cursor, grey, grey, grey) + letterSpacing;
        cursor += drawLetterNormalized(modelO, cursor, grey, grey, grey) + letterSpacing;
        cursor += drawLetterNormalized(modelF, cursor, grey, grey, grey) + letterSpacing;
        cursor += drawLetterNormalized(modelI, cursor, grey, grey, grey) + letterSpacing;
        cursor += drawLetterNormalized(modelB, cursor, grey, grey, grey) + letterSpacing;
        cursor += drawLetterNormalized(modelR, cursor, grey, grey, grey) + letterSpacing;

        float uStartX = cursor;
        float uWidth = drawLetterNormalized(modelU, cursor, grey, grey, grey);
        cursor += uWidth + letterSpacing;

        float uCenterX = uStartX + (uWidth * 0.5f);
        float dotGap = uWidth * 0.18f;

        drawDot(modelT1, uCenterX - dotGap, targetHeight + dotHeightAboveLetter, grey, grey, grey);
        drawDot(modelT2, uCenterX + dotGap, targetHeight + dotHeightAboveLetter, grey, grey, grey);
    glPopMatrix();
}