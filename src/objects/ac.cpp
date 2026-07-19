#include <GL/freeglut.h>
#include "objects/ac.h"
#include "objects/ac_data.h"

AC::AC() {
    // Warna body AC: merah gelap
    colorRed = 0.55f;
    colorGreen = 0.0f;
    colorBlue = 0.0f;
}

void AC::draw() {
    glColor3f(colorRed, colorGreen, colorBlue);

    glBegin(GL_TRIANGLES);
    for (int i = 0; i < AC_FACE_COUNT; i++) {
        const ACFace& f = ACFaces[i];
        const ACVertex& a = ACVertices[f.v0];
        const ACVertex& b = ACVertices[f.v1];
        const ACVertex& c = ACVertices[f.v2];

        glNormal3f(f.nx, f.ny, f.nz);
        glVertex3f(a.x, a.y, a.z);
        glVertex3f(b.x, b.y, b.z);
        glVertex3f(c.x, c.y, c.z);
    }
    glEnd();
}
