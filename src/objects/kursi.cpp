#include <GL/freeglut.h>
#include "objects/kursi.h"
#include "objects/kursi_data.h"

Kursi::Kursi() {
    // Warna default kursi (coklat kayu). Ubah di sini kalau mau warna lain.
    colorRed = 0.55f;
    colorGreen = 0.35f;
    colorBlue = 0.2f;
}

void Kursi::draw() {
    glColor3f(colorRed, colorGreen, colorBlue);

    glBegin(GL_TRIANGLES);
    for (int i = 0; i < KURSI_FACE_COUNT; i++) {
        const Face& f = KursiFaces[i];
        const Vertex& a = KursiVertices[f.v0];
        const Vertex& b = KursiVertices[f.v1];
        const Vertex& c = KursiVertices[f.v2];

        glNormal3f(f.nx, f.ny, f.nz);
        glVertex3f(a.x, a.y, a.z);
        glVertex3f(b.x, b.y, b.z);
        glVertex3f(c.x, c.y, c.z);
    }
    glEnd();
}
