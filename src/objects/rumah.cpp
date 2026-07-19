#include <GL/freeglut.h>
#include "objects/rumah.h"
#include "objects/rumah_data.h"
#include "objects/Kofibru.h"
#include "objects/Pembatas.h"

Pembatas pembatasDepan;
Pembatas pembatasSamping;
Pembatas pembatasSerong;
Kofibru logoKofibru;

Rumah::Rumah() {
    // Atap -- coklat gelap
    atapRed = 0.3f;
    atapGreen = 0.15f;
    atapBlue = 0.05f;

    // Tembok -- abu-abu
    tembokRed = 0.7f;
    tembokGreen = 0.7f;
    tembokBlue = 0.7f;

    // Pintu -- coklat
    pintuRed = 0.45f;
    pintuGreen = 0.28f;
    pintuBlue = 0.12f;

    // Jendela -- biru
    jendelaRed = 0.25f;
    jendelaGreen = 0.5f;
    jendelaBlue = 0.85f;

    

}

static void drawFaces(const RumahFace* facesArr, int count) {
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < count; i++) {
        const RumahFace& f = facesArr[i];
        const RumahVertex& a = RumahVertices[f.v0];
        const RumahVertex& b = RumahVertices[f.v1];
        const RumahVertex& c = RumahVertices[f.v2];

        glNormal3f(f.nx, f.ny, f.nz);
        glVertex3f(a.x, a.y, a.z);
        glVertex3f(b.x, b.y, b.z);
        glVertex3f(c.x, c.y, c.z);
    }
    glEnd();
}

void Rumah::draw() {
    glColor3f(atapRed, atapGreen, atapBlue);
    drawFaces(RumahAtapFaces, RUMAH_ATAP_FACE_COUNT);

    glColor3f(tembokRed, tembokGreen, tembokBlue);
    drawFaces(RumahTembokFaces, RUMAH_TEMBOK_FACE_COUNT);

    glColor3f(pintuRed, pintuGreen, pintuBlue);
    drawFaces(RumahPintuFaces, RUMAH_PINTU_FACE_COUNT);

    glColor3f(jendelaRed, jendelaGreen, jendelaBlue);
    drawFaces(RumahJendelaFaces, RUMAH_JENDELA_FACE_COUNT);
}

void Rumah::drawAll() {
    glPushMatrix();

    // Posisi rumah di luar footprint Gedung (gedung berada kira-kira di
    // X -7.5..7, Z -5..8). Digeser jauh ke samping supaya jelas di luar.
    glTranslatef(20.0f, 0.0f, 0.0f);

    // Mesh asli dalam satuan cm -> skala ke satuan scene (meter-ish)
    glScalef(0.01f, 0.01f, 0.01f);

    // Koreksi orientasi: STL pakai Z-up (CAD), scene pakai Y-up (OpenGL)
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);

    draw();

    glPopMatrix();

    logoKofibru.drawAll();

    pembatasDepan.posX = 9.7f;
    pembatasDepan.posY = 0.0f;
    pembatasDepan.posZ = -7.7f;
    pembatasDepan.rotationY = 0.0f;
    pembatasDepan.length = 13.0f;
    pembatasDepan.height = 0.9f;
    pembatasDepan.thickness = 0.5f;

    pembatasSamping.posX = 5.0f;
    pembatasSamping.posY = 0.0f;
    pembatasSamping.posZ = 5.1f;
    pembatasSamping.rotationY = 90.0f;
    pembatasSamping.length = 4.9f;
    pembatasSamping.height = 0.9f;
    pembatasSamping.thickness = 0.5f;

    pembatasSerong.posX = 3.0f;
    pembatasSerong.posY = 0.0f;
    pembatasSerong.posZ = 3.0f;
    pembatasSerong.rotationY = 45.0f;
    pembatasSerong.length = 3.0f;
    pembatasSerong.height = 0.9f;
    pembatasSerong.thickness = 0.5f;

    // =====================
    // Pembatas jalur (eksterior)
    // =====================
    pembatasDepan.drawAll();
    pembatasSamping.drawAll();
    pembatasSerong.drawAll();

    // =====================
    // Ruko (posisi & skala diatur di sini, persis pola kasir di Gedung.cpp)
    // =====================
    glPushMatrix();
    glTranslatef(-21.0f, 0.0f, 12.0f);   // sesuaikan posisi ruko (relatif dari titik asal scene)
    glScalef(0.015f, 0.015f, 0.015f);     // mesh asli satuan cm, sesuaikan skala ruko di sini
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    ruko.draw();
    glPopMatrix();
}
