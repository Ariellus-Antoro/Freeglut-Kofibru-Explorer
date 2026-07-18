#include <GL/freeglut.h>

#include "utils/Camera.h"
#include "core/Keyboard.h"
#include "core/Mouse.h"
#include "objects/Gedung.h"
#include "objects/rumah.h"
// Inisialisasi Objek Kamera secara Global
Camera playerCamera;

Gedung kofibruBuilding;
Rumah rumahLuar;

// Mengatur proyeksi 3D saat ukuran jendela berubah dengan menyesuaikan rasio
void reshape(int w, int h) {
    // Mencegah pembagian dengan nol
    if (h == 0) h = 1; 

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
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    playerCamera.applyCamera();

    kofibruBuilding.drawAll();
    rumahLuar.drawAll();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(1200,720);
    glutCreateWindow("TR - Simple Kofibru Explorer");

    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape); 
    
    // Controller keyboard dan mouse
    glutKeyboardFunc(handleKeyboard);
    glutPassiveMotionFunc(handleMouse);
    
    glutSetCursor(GLUT_CURSOR_NONE);

    glutMainLoop();
    
    return 0;
}