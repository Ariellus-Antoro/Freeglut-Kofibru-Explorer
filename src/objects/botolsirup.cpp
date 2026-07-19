#include <GL/freeglut.h>
#include "objects/botolsirup.h"
#include "objects/botolsirup_data.h"

BotolSirup::BotolSirup() {
    // Warna body bagian atas (bahu, leher, tutup) -- hitam pekat
    capRed = 0.05f;
    capGreen = 0.05f;
    capBlue = 0.05f;

    // Warna & transparansi body bagian bawah -- kaca/plastik bening berisi sirup
    bodyRed = 0.80f;
    bodyGreen = 0.85f;
    bodyBlue = 0.80f;
    bodyAlpha = 0.35f;

    // Batas ketinggian (satuan mesh asli/cm) antara body bawah (transparan) dan
    // body atas (hitam). Mesh botolSirup.stl punya bahu/pundak mulai sekitar
    // z = 15, jadi split di titik ini mengikuti bentuk asli botolnya.
    splitZ = 15.0f;
}

void BotolSirup::draw() {
    // =========================================================
    // 1. Body bagian ATAS (bahu, leher, tutup) -- HITAM, digambar
    //    lebih dulu sebagai objek solid/opaque.
    // =========================================================
    glColor3f(capRed, capGreen, capBlue);
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < BOTOLSIRUP_FACE_COUNT; i++) {
        const BotolSirupFace& f = BotolSirupFaces[i];
        const BotolSirupVertex& a = BotolSirupVertices[f.v0];
        const BotolSirupVertex& b = BotolSirupVertices[f.v1];
        const BotolSirupVertex& c = BotolSirupVertices[f.v2];

        float avgZ = (a.z + b.z + c.z) / 3.0f;
        if (avgZ < splitZ) continue; // bagian bawah -- dilewati, digambar di tahap 2

        glNormal3f(f.nx, f.ny, f.nz);
        glVertex3f(a.x, a.y, a.z);
        glVertex3f(b.x, b.y, b.z);
        glVertex3f(c.x, c.y, c.z);
    }
    glEnd();

    // =========================================================
    // 2. Body bagian BAWAH (dekat dasar) -- TRANSPARAN, digambar
    //    belakangan dengan alpha blending menyala.
    // =========================================================
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDepthMask(GL_FALSE);

    glColor4f(bodyRed, bodyGreen, bodyBlue, bodyAlpha);
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < BOTOLSIRUP_FACE_COUNT; i++) {
        const BotolSirupFace& f = BotolSirupFaces[i];
        const BotolSirupVertex& a = BotolSirupVertices[f.v0];
        const BotolSirupVertex& b = BotolSirupVertices[f.v1];
        const BotolSirupVertex& c = BotolSirupVertices[f.v2];

        float avgZ = (a.z + b.z + c.z) / 3.0f;
        if (avgZ >= splitZ) continue; // bagian atas -- sudah digambar di tahap 1

        glNormal3f(f.nx, f.ny, f.nz);
        glVertex3f(a.x, a.y, a.z);
        glVertex3f(b.x, b.y, b.z);
        glVertex3f(c.x, c.y, c.z);
    }
    glEnd();

    glDisable(GL_BLEND);
    glDepthMask(GL_TRUE);
}
