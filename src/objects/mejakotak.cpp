#include <GL/freeglut.h>
#include "objects/mejakotak.h"
#include "objects/mejakotak_data.h"

MejaKotak::MejaKotak() {
    // Warna default meja kotak (coklat kayu). Ubah di sini kalau mau warna lain.
    colorRed = 0.55f;
    colorGreen = 0.35f;
    colorBlue = 0.2f;
}

void MejaKotak::draw() {
    glColor3f(colorRed, colorGreen, colorBlue);

    glBegin(GL_TRIANGLES);
    for (int i = 0; i < MEJAKOTAK_FACE_COUNT; i++) {
        const MejaKotakFace& f = MejaKotakFaces[i];
        const MejaKotakVertex& a = MejaKotakVertices[f.v0];
        const MejaKotakVertex& b = MejaKotakVertices[f.v1];
        const MejaKotakVertex& c = MejaKotakVertices[f.v2];

        glNormal3f(f.nx, f.ny, f.nz);
        glVertex3f(a.x, a.y, a.z);
        glVertex3f(b.x, b.y, b.z);
        glVertex3f(c.x, c.y, c.z);
    }
    glEnd();
}
