#include "objects/Wastafel.h"

Wastafel::Wastafel() {
    posX = 7.8f;   // sesuaikan posisi wastafel di scene
    posY = 1.1f;
    posZ = 0.7f;
    rotationY = 90.0f;

    targetHeight = 0.6f; // tinggi wajar wastafel, sesuaikan

    colorR = 0.9f;
    colorG = 0.9f;
    colorB = 0.9f;

    model.loadOBJ("src/objects/Wastafel.obj"); // sesuaikan path sesuai lokasi file asli
}

void Wastafel::drawAll() {
    float h = model.getHeight();
    if (h <= 0.0f) return; // model gagal load atau kosong

    float scale = targetHeight / h;

    glPushMatrix();
        glTranslatef(posX, posY, posZ);
        glRotatef(rotationY, 0.0f, 1.0f, 0.0f);
        glScalef(scale, scale, scale);
        // Kompensasi supaya titik pivot objek (min corner bounding box) jadi acuan,
        // bukan origin OBJ asli dari Fusion (yang biasanya bukan di sudut objek)
        glTranslatef(-model.getMinX(), -model.getMinY(), -model.getMinZ());
        glColor3f(colorR, colorG, colorB);
        model.draw();
    glPopMatrix();
}