#include <GL/freeglut.h>
#include "objects/ktembok.h"
#include "objects/ktembok_data.h"

KTembok::KTembok() {
    colorRed = 0.36f;
    colorGreen = 0.25f;
    colorBlue = 0.20f;
}

void KTembok::draw() {
    glColor3f(colorRed, colorGreen, colorBlue);

    glBegin(GL_TRIANGLES);
    for (int i = 0; i < KTEMBOK_FACE_COUNT; i++) {
        const KTembokFace& f = KTembokFaces[i];
        const KTembokVertex& a = KTembokVertices[f.v0];
        const KTembokVertex& b = KTembokVertices[f.v1];
        const KTembokVertex& c = KTembokVertices[f.v2];

        glNormal3f(f.nx, f.ny, f.nz);
        glVertex3f(a.x, a.y, a.z);
        glVertex3f(b.x, b.y, b.z);
        glVertex3f(c.x, c.y, c.z);
    }
    glEnd();
}
