#include "core/Mouse.h"
#include "utils/Camera.h"
#include "GL/freeglut.h"

extern Camera playerCamera;

// Mencegah event mouse diproses dua kali setelah glutWarpPointer().
bool isWarping = false;

// Menangani pergerakan mouse.
void handleMouse(int x, int y){
     // Mengabaikan event yang berasal dari glutWarpPointer()
    if(isWarping){
        isWarping = false;
        return;
    }

    // Ambil titik tengah layar
    int centerX = glutGet(GLUT_WINDOW_WIDTH) / 2;
    int centerY = glutGet(GLUT_WINDOW_HEIGHT) / 2;

    // Menghitung selisih posisi mouse terhadap titik tengah layar.
    float deltaX = (float)(x - centerX);
    float deltaY = (float)(centerY - y); 

    // Mengatur sensivitas mouse
    float sensitivity = 0.1f;

    // Memutar kamera berdasarkan pergerakan mouse.
    playerCamera.rotate(deltaX * sensitivity, deltaY * sensitivity);

    // Digunakan agar kamera dapat terus berputar
    isWarping = true;
    glutWarpPointer(centerX, centerY);

    // Meminta OpenGL menggambar ulang scene.
    glutPostRedisplay();
}