#include "objects/Kofibru.h"

Kofibru::Kofibru()
{
    posX = 9.7f;
    posY = 0.9f;
    posZ = 4.0f;
    rotationY = 90.0f;

    targetHeight = 0.8f;
    letterSpacing = 0.15f;
    dotHeightAboveLetter = 0.15f;
    dotSize = 0.12f;

    modelK.loadOBJ("src/models/K.obj");
    modelO.loadOBJ("src/models/O.obj");
    modelF.loadOBJ("src/models/F.obj");
    modelI.loadOBJ("src/models/I.obj");
    modelB.loadOBJ("src/models/B.obj");
    modelR.loadOBJ("src/models/R.obj");
    modelU.loadOBJ("src/models/U.obj");
    modelT1.loadOBJ("src/models/t1.obj");
    modelT2.loadOBJ("src/models/t2.obj");
}

float Kofibru::drawLetterNormalized(ModelLoader &model, float cursorOffset,
                                    float colorRed, float colorGreen, float colorBlue)
{
    float h = model.getHeight();
    if (h <= 0.0f)
        return 0.0f;

    float scale = targetHeight / h;

    // Tentukan faktor tebal (misal 1.3f) jika isBold true, kalau false tetap 1.0f (normal)
    float boldFactor = isBold ? 1.3f : 1.0f;

    glPushMatrix();
    glTranslatef(cursorOffset, 0.0f, 0.0f);

    // Skala X dan Z dikali boldFactor
    glScalef(scale * boldFactor, scale, scale * boldFactor);

    glTranslatef(-model.getMinX(), -model.getMinY(), -model.getMinZ());
    glColor3f(colorRed, colorGreen, colorBlue);
    model.draw();
    glPopMatrix();

    return model.getWidth() * scale * boldFactor;
}

void Kofibru::drawDot(ModelLoader &model, float cursorOffset, float liftHeight,
                      float colorRed, float colorGreen, float colorBlue)
{
    float h = model.getHeight();
    if (h <= 0.0f)
        return;

    // Pakai dotSize seperti awal agar ukurannya tidak berubah-ubah
    float scale = dotSize / h;

    glPushMatrix();
    // Pakai offset sederhana
    glTranslatef(cursorOffset, liftHeight, 0.0f);
    glScalef(scale, scale, scale);
    // Kembali ke setting awal tanpa mengubah origin secara drastis
    glTranslatef(-model.getMinX(), -model.getMinY(), -model.getMinZ());
    glColor3f(colorRed, colorGreen, colorBlue);
    model.draw();
    glPopMatrix();
}

void Kofibru::drawAll()
{
    float black = 0.3f;
    float cursor = 0.0f;

    glPushMatrix();
    glTranslatef(posX, posY, posZ);
    glRotatef(rotationY, 0.0f, 1.0f, 0.0f);

    cursor += drawLetterNormalized(modelK, cursor, black, black, black) + letterSpacing;
    cursor += drawLetterNormalized(modelO, cursor, black, black, black) + letterSpacing;
    cursor += drawLetterNormalized(modelF, cursor, black, black, black) + letterSpacing;
    cursor += drawLetterNormalized(modelI, cursor, black, black, black) + letterSpacing;
    cursor += drawLetterNormalized(modelB, cursor, black, black, black) + letterSpacing;
    cursor += drawLetterNormalized(modelR, cursor, black, black, black) + letterSpacing;

    float uStartX = cursor;
    float uWidth = drawLetterNormalized(modelU, cursor, black, black, black);
    cursor += uWidth + letterSpacing;

    float uCenterX = uStartX + (uWidth * 0.5f);
    float dotGap = uWidth * 0.18f;

    if (drawDots)
    {
        float uCenterX = uStartX + (uWidth * 0.5f);
        float dotGap = uWidth * 0.18f;

        drawDot(modelT1, uCenterX - dotGap, targetHeight + dotHeightAboveLetter, black, black, black);
        drawDot(modelT2, uCenterX + dotGap, targetHeight + dotHeightAboveLetter, black, black, black);
    }
    glPopMatrix();
}