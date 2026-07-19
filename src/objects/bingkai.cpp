#include <GL/freeglut.h>
#include "objects/bingkai.h"
#include "objects/bingkai_data.h"

Bingkai::Bingkai() {
    // Bingkai luar: coklat gelap
    frameRed = 0.25f; frameGreen = 0.14f; frameBlue = 0.06f;
}

void Bingkai::draw(GLuint fotoTexture) {
    // Bagian luar bingkai (molding) - warna solid coklat gelap
    glDisable(GL_TEXTURE_2D);
    glColor3f(frameRed, frameGreen, frameBlue);
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < BINGKAI_FRAME_FACE_COUNT; i++) {
        const BingkaiFace& f = BingkaiFrameFaces[i];
        const BingkaiVertex& a = BingkaiFrameVertices[f.v0];
        const BingkaiVertex& b = BingkaiFrameVertices[f.v1];
        const BingkaiVertex& c = BingkaiFrameVertices[f.v2];

        glNormal3f(f.nx, f.ny, f.nz);
        glVertex3f(a.x, a.y, a.z);
        glVertex3f(b.x, b.y, b.z);
        glVertex3f(c.x, c.y, c.z);
    }
    glEnd();

    // Bidang dalam (rabbet) - ditekstur dengan gambar
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, fotoTexture);
    glColor3f(1.0f, 1.0f, 1.0f); // putih agar tekstur tidak berubah warna

    glBegin(GL_TRIANGLES);
    for (int i = 0; i < BINGKAI_FOTO_FACE_COUNT; i++) {
        const BingkaiFace& f = BingkaiFotoFaces[i];
        const BingkaiFotoVertex& a = BingkaiFotoVertices[f.v0];
        const BingkaiFotoVertex& b = BingkaiFotoVertices[f.v1];
        const BingkaiFotoVertex& c = BingkaiFotoVertices[f.v2];

        glNormal3f(f.nx, f.ny, f.nz);
        glTexCoord2f(a.u, a.v); glVertex3f(a.x, a.y, a.z);
        glTexCoord2f(b.u, b.v); glVertex3f(b.x, b.y, b.z);
        glTexCoord2f(c.u, c.v); glVertex3f(c.x, c.y, c.z);
    }
    glEnd();

    glDisable(GL_TEXTURE_2D);
}
