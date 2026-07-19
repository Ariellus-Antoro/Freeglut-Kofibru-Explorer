#include <GL/freeglut.h>
#include "objects/prayogo.h"
#include "objects/prayogo_data.h"

Prayogo::Prayogo() {
    // Body 1 -- bangunan bagian bawah -> abu-abu terang
    body1Red = 0.80f;
    body1Green = 0.80f;
    body1Blue = 0.80f;

    // Body 2 & 3 -- atap/kanopi yang menonjol ke bawah -> abu-abu gelap
    body23Red = 0.35f;
    body23Green = 0.35f;
    body23Blue = 0.35f;

    // Body 4 -- ornamen tengah -> abu-abu gelap
    body4Red = 0.35f;
    body4Green = 0.35f;
    body4Blue = 0.35f;

    // Body 5 -- bangunan bagian atas -> abu-abu terang
    body5Red = 0.80f;
    body5Green = 0.80f;
    body5Blue = 0.80f;

    // Body 6 & 7 -- 2 jendela atas -> hitam
    body67Red = 0.05f;
    body67Green = 0.05f;
    body67Blue = 0.05f;

    // Body 8, 9, 10 -- pintu bangunan bawah -> kuning gelap
    body8910Red = 0.55f;
    body8910Green = 0.42f;
    body8910Blue = 0.05f;
}

static void drawFaces(const PrayogoFace* facesArr, int count) {
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < count; i++) {
        const PrayogoFace& f = facesArr[i];
        const PrayogoVertex& a = PrayogoVertices[f.v0];
        const PrayogoVertex& b = PrayogoVertices[f.v1];
        const PrayogoVertex& c = PrayogoVertices[f.v2];

        glNormal3f(f.nx, f.ny, f.nz);
        glVertex3f(a.x, a.y, a.z);
        glVertex3f(b.x, b.y, b.z);
        glVertex3f(c.x, c.y, c.z);
    }
    glEnd();
}

void Prayogo::draw() {
    // Body 1 -- bangunan bagian bawah
    glColor3f(body1Red, body1Green, body1Blue);
    drawFaces(PrayogoBody1Faces, PRAYOGO_BODY1_FACE_COUNT);

    // Body 2 & 3 -- atap/kanopi menonjol bawah (kiri & kanan)
    glColor3f(body23Red, body23Green, body23Blue);
    drawFaces(PrayogoBody2Faces, PRAYOGO_BODY2_FACE_COUNT);
    drawFaces(PrayogoBody3Faces, PRAYOGO_BODY3_FACE_COUNT);

    // Body 4 -- ornamen tengah
    glColor3f(body4Red, body4Green, body4Blue);
    drawFaces(PrayogoBody4Faces, PRAYOGO_BODY4_FACE_COUNT);

    // Body 5 -- bangunan bagian atas
    glColor3f(body5Red, body5Green, body5Blue);
    drawFaces(PrayogoBody5Faces, PRAYOGO_BODY5_FACE_COUNT);

    // Body 6 & 7 -- 2 jendela atas (kiri & kanan)
    glColor3f(body67Red, body67Green, body67Blue);
    drawFaces(PrayogoBody6Faces, PRAYOGO_BODY6_FACE_COUNT);
    drawFaces(PrayogoBody7Faces, PRAYOGO_BODY7_FACE_COUNT);

    // Body 8, 9, 10 -- pintu bangunan bawah (kiri, tengah, kanan)
    glColor3f(body8910Red, body8910Green, body8910Blue);
    drawFaces(PrayogoBody8Faces, PRAYOGO_BODY8_FACE_COUNT);
    drawFaces(PrayogoBody9Faces, PRAYOGO_BODY9_FACE_COUNT);
    drawFaces(PrayogoBody10Faces, PRAYOGO_BODY10_FACE_COUNT);
}
