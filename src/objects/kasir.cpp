#include <GL/freeglut.h>
#include "objects/kasir.h"
#include "objects/kasir_data.h"

Kasir::Kasir() {
    // Warna default kasir (coklat kayu). Ubah di sini kalau mau warna lain.
    colorRed = 0.30f;
    colorGreen = 0.30f;
    colorBlue = 0.30f;
}

void Kasir::draw() {
    glColor3f(colorRed, colorGreen, colorBlue);

    glBegin(GL_TRIANGLES);
    for (int i = 0; i < KASIR_FACE_COUNT; i++) {
        const KasirFace& f = KasirFaces[i];
        const KasirVertex& a = KasirVertices[f.v0];
        const KasirVertex& b = KasirVertices[f.v1];
        const KasirVertex& c = KasirVertices[f.v2];

        glNormal3f(f.nx, f.ny, f.nz);
        glVertex3f(a.x, a.y, a.z);
        glVertex3f(b.x, b.y, b.z);
        glVertex3f(c.x, c.y, c.z);
    }
    glEnd();
}
