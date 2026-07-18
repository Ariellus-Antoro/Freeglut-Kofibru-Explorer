#include <GL/freeglut.h>
#include "objects/gelas.h"
#include "objects/gelas_data.h"

Gelas::Gelas() {
    // Warna default gelas (putih kebiruan, kesan kaca/plastik bening).
    // Ubah di sini kalau mau warna lain (misal gelas keramik atau berwarna).
    colorRed = 0.85f;
    colorGreen = 0.92f;
    colorBlue = 0.95f;
}

void Gelas::draw() {
    glColor3f(colorRed, colorGreen, colorBlue);

    glBegin(GL_TRIANGLES);
    for (int i = 0; i < GELAS_FACE_COUNT; i++) {
        const GelasFace& f = GelasFaces[i];
        const GelasVertex& a = GelasVertices[f.v0];
        const GelasVertex& b = GelasVertices[f.v1];
        const GelasVertex& c = GelasVertices[f.v2];

        glNormal3f(f.nx, f.ny, f.nz);
        glVertex3f(a.x, a.y, a.z);
        glVertex3f(b.x, b.y, b.z);
        glVertex3f(c.x, c.y, c.z);
    }
    glEnd();
}
