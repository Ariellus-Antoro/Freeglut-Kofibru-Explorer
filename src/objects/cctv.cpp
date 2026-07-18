#include <GL/freeglut.h>
#include "objects/cctv.h"
#include "objects/cctv_data.h"

CCTV::CCTV() {
    // Bagian kubah / setengah lingkaran (lensa) -- gelap, kesan kaca hitam
    domeRed = 0.08f;
    domeGreen = 0.08f;
    domeBlue = 0.1f;

    // Bagian dudukan / mounting atas -- terang, kesan plastik putih
    mountRed = 0.9f;
    mountGreen = 0.9f;
    mountBlue = 0.9f;
}

void CCTV::draw() {
    // Kubah / setengah lingkaran (gelap)
    glColor3f(domeRed, domeGreen, domeBlue);
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < CCTV_DOME_FACE_COUNT; i++) {
        const CCTVFace& f = CCTVDomeFaces[i];
        const CCTVVertex& a = CCTVVertices[f.v0];
        const CCTVVertex& b = CCTVVertices[f.v1];
        const CCTVVertex& c = CCTVVertices[f.v2];

        glNormal3f(f.nx, f.ny, f.nz);
        glVertex3f(a.x, a.y, a.z);
        glVertex3f(b.x, b.y, b.z);
        glVertex3f(c.x, c.y, c.z);
    }
    glEnd();

    // Dudukan / mounting atas (terang)
    glColor3f(mountRed, mountGreen, mountBlue);
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < CCTV_MOUNT_FACE_COUNT; i++) {
        const CCTVFace& f = CCTVMountFaces[i];
        const CCTVVertex& a = CCTVVertices[f.v0];
        const CCTVVertex& b = CCTVVertices[f.v1];
        const CCTVVertex& c = CCTVVertices[f.v2];

        glNormal3f(f.nx, f.ny, f.nz);
        glVertex3f(a.x, a.y, a.z);
        glVertex3f(b.x, b.y, b.z);
        glVertex3f(c.x, c.y, c.z);
    }
    glEnd();
}
