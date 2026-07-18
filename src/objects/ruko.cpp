#include <GL/freeglut.h>
#include "objects/ruko.h"
#include "objects/ruko_data.h"

Ruko::Ruko() {
    // Tembok -- biru tua
    tembokRed = 0.08f;
    tembokGreen = 0.15f;
    tembokBlue = 0.4f;

    // Pintu -- coklat
    pintuRed = 0.45f;
    pintuGreen = 0.28f;
    pintuBlue = 0.12f;

    // Jendela -- biru muda
    jendelaRed = 0.6f;
    jendelaGreen = 0.8f;
    jendelaBlue = 0.95f;
}

static void drawFaces(const RukoFace* facesArr, int count) {
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < count; i++) {
        const RukoFace& f = facesArr[i];
        const RukoVertex& a = RukoVertices[f.v0];
        const RukoVertex& b = RukoVertices[f.v1];
        const RukoVertex& c = RukoVertices[f.v2];

        glNormal3f(f.nx, f.ny, f.nz);
        glVertex3f(a.x, a.y, a.z);
        glVertex3f(b.x, b.y, b.z);
        glVertex3f(c.x, c.y, c.z);
    }
    glEnd();
}

void Ruko::draw() {
    glColor3f(tembokRed, tembokGreen, tembokBlue);
    drawFaces(RukoTembokFaces, RUKO_TEMBOK_FACE_COUNT);

    glColor3f(pintuRed, pintuGreen, pintuBlue);
    drawFaces(RukoPintuFaces, RUKO_PINTU_FACE_COUNT);

    glColor3f(jendelaRed, jendelaGreen, jendelaBlue);
    drawFaces(RukoJendelaFaces, RUKO_JENDELA_FACE_COUNT);
}
