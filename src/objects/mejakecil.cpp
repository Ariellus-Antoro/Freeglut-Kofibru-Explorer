#include <GL/freeglut.h>
#include "objects/mejakecil.h"
#include "objects/mejakecil_data.h"

MejaKecil::MejaKecil() {
    // Warna default meja kecil (coklat kayu). Ubah di sini kalau mau warna lain.
    colorRed = 0.55f;
    colorGreen = 0.35f;
    colorBlue = 0.2f;
}

void MejaKecil::draw() {
    glPushMatrix();

    // Mesh asli dari STL pakai konvensi Z = sumbu vertikal (khas CAD/AutoCAD),
    // sedangkan scene OpenGL di sini pakai konvensi Y = sumbu vertikal.
    // Tanpa rotasi ini meja akan tampak rebah, sama seperti kasus Kursi.
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);

    glColor3f(colorRed, colorGreen, colorBlue);

    glBegin(GL_TRIANGLES);
    for (int i = 0; i < MEJAKECIL_FACE_COUNT; i++) {
        const MejaKecilFace& f = MejaKecilFaces[i];
        const MejaKecilVertex& a = MejaKecilVertices[f.v0];
        const MejaKecilVertex& b = MejaKecilVertices[f.v1];
        const MejaKecilVertex& c = MejaKecilVertices[f.v2];

        glNormal3f(f.nx, f.ny, f.nz);
        glVertex3f(a.x, a.y, a.z);
        glVertex3f(b.x, b.y, b.z);
        glVertex3f(c.x, c.y, c.z);
    }
    glEnd();

    glPopMatrix();
}
