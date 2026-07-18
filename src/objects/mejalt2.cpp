#include <GL/freeglut.h>
#include "objects/mejalt2.h"
#include "objects/mejalt2_data.h"

MejaLt2::MejaLt2() {
    // Warna default meja (coklat kayu). Ubah di sini kalau mau warna lain.
    colorRed = 0.55f;
    colorGreen = 0.35f;
    colorBlue = 0.2f;
}

void MejaLt2::draw() {
    glColor3f(colorRed, colorGreen, colorBlue);

    glBegin(GL_TRIANGLES);
    for (int i = 0; i < MEJALT2_FACE_COUNT; i++) {
        const MejaLt2Face& f = MejaLt2Faces[i];
        const MejaLt2Vertex& a = MejaLt2Vertices[f.v0];
        const MejaLt2Vertex& b = MejaLt2Vertices[f.v1];
        const MejaLt2Vertex& c = MejaLt2Vertices[f.v2];

        glNormal3f(f.nx, f.ny, f.nz);
        glVertex3f(a.x, a.y, a.z);
        glVertex3f(b.x, b.y, b.z);
        glVertex3f(c.x, c.y, c.z);
    }
    glEnd();
}
