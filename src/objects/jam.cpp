#include <GL/freeglut.h>
#include "objects/jam.h"
#include "objects/jam_data.h"

Jam::Jam() {
    // Casing/bezel luar: coklat tua
    caseRed = 0.30f; caseGreen = 0.18f; caseBlue = 0.08f;

    // Dial/pelat muka: putih
    dialRed = 1.0f; dialGreen = 1.0f; dialBlue = 1.0f;

    // Angka & jarum: gelap
    markRed = 0.08f; markGreen = 0.08f; markBlue = 0.08f;
}

void Jam::draw() {
    // Casing luar
    glColor3f(caseRed, caseGreen, caseBlue);
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < JAM_CASE_FACE_COUNT; i++) {
        const JamFace& f = JamCaseFaces[i];
        const JamVertex& a = JamCaseVertices[f.v0];
        const JamVertex& b = JamCaseVertices[f.v1];
        const JamVertex& c = JamCaseVertices[f.v2];

        glNormal3f(f.nx, f.ny, f.nz);
        glVertex3f(a.x, a.y, a.z);
        glVertex3f(b.x, b.y, b.z);
        glVertex3f(c.x, c.y, c.z);
    }
    glEnd();

    // Dial (pelat muka) dalam
    glColor3f(dialRed, dialGreen, dialBlue);
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < JAM_DIAL_FACE_COUNT; i++) {
        const JamFace& f = JamDialFaces[i];
        const JamVertex& a = JamDialVertices[f.v0];
        const JamVertex& b = JamDialVertices[f.v1];
        const JamVertex& c = JamDialVertices[f.v2];

        glNormal3f(f.nx, f.ny, f.nz);
        glVertex3f(a.x, a.y, a.z);
        glVertex3f(b.x, b.y, b.z);
        glVertex3f(c.x, c.y, c.z);
    }
    glEnd();

    // Angka & jarum
    glColor3f(markRed, markGreen, markBlue);
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < JAM_MARKS_FACE_COUNT; i++) {
        const JamFace& f = JamMarksFaces[i];
        const JamVertex& a = JamMarksVertices[f.v0];
        const JamVertex& b = JamMarksVertices[f.v1];
        const JamVertex& c = JamMarksVertices[f.v2];

        glNormal3f(f.nx, f.ny, f.nz);
        glVertex3f(a.x, a.y, a.z);
        glVertex3f(b.x, b.y, b.z);
        glVertex3f(c.x, c.y, c.z);
    }
    glEnd();
}
