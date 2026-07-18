#include <GL/freeglut.h>

#include "utils/Camera.h"
#include "core/Keyboard.h"
#include "core/Mouse.h"
#include "objects/Gedung.h"
#include "objects/Kofibru.h"
#include "objects/Wastafel.h"
#include "objects/Pembatas.h"

Pembatas pembatasDepan;
Pembatas pembatasSamping; // tinggi 0.9, tebal 0.1, warna coklat
Pembatas pembatasserong;
// Inisialisasi Objek Kamera secara Global
Camera playerCamera;

Gedung kofibruBuilding;
Kofibru kofibruLogo;
Wastafel kofibruWastafel;

// Mengatur proyeksi 3D saat ukuran jendela berubah dengan menyesuaikan rasio
void reshape(int w, int h)
{
    // Mencegah pembagian dengan nol
    if (h == 0)
        h = 1;

    // Menghitung rasio lebar dan tinggi jendela.
    float ratio = (float)w / (float)h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Mengatur perspektif kamera.
    // Field of View : 45 derajat
    // Near Plane    : 0.1
    // Far Plane     : 100
    gluPerspective(45.0f, ratio, 0.1f, 100.0f);

    glMatrixMode(GL_MODELVIEW);
}

// Menggambar seluruh objek pada scene 3D.
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    playerCamera.applyCamera();

    kofibruBuilding.drawAll();
    kofibruLogo.drawAll();
    kofibruWastafel.drawAll();
    pembatasDepan.drawAll();
    pembatasSamping.drawAll();
    pembatasserong.drawAll();

    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(1200, 720);
    glutCreateWindow("TR - Simple Kofibru Explorer");

    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    // Setup rute pembatas: dari depan pintu, menuju arah Kofibru, lalu belok ke samping.
    // Titik-titik ini masih tebakan awal — sesuaikan dengan koordinat pintu depan
    // gedung kamu yang sebenarnya (cek drawWallWithHole di Gedung.cpp).
    pembatasDepan.posX = 9.7f;
    pembatasDepan.posY = 0.0f;
    pembatasDepan.posZ = -7.7f;
    pembatasDepan.rotationY = 0.0f;
    pembatasDepan.length = 13.0f;
    pembatasDepan.height = 0.9f;
    pembatasDepan.thickness = 0.5f;

    // Segmen 2: belok ke samping, mulai dari ujung segmen 1
    pembatasSamping.posX = 5.0f;
    pembatasSamping.posY = 0.0f;
    pembatasSamping.posZ = 5.1f; // ujung segmen 1 (posZ + length = 5.0 - 3.0 = 2.0)
    pembatasSamping.rotationY = 90.0f;
    pembatasSamping.length = 4.9f;
    pembatasSamping.height = 0.9f;
    pembatasSamping.thickness = 0.5f;
    ; // titik akhir, belok ke samping

    pembatasserong.posX = 3.0f;
    pembatasserong.posY = 0.0f;
    pembatasserong.posZ = 3.0f;
    pembatasserong.rotationY = 45.0f;
    pembatasserong.length = 3.0f;
    pembatasserong.height = 0.9f;
    pembatasserong.thickness = 0.5f;

    // Controller keyboard dan mouse — persis seperti semula, gak ada perubahan
    glutKeyboardFunc(handleKeyboard);
    glutPassiveMotionFunc(handleMouse);

    glutSetCursor(GLUT_CURSOR_NONE);

    glutMainLoop();

    return 0;
}