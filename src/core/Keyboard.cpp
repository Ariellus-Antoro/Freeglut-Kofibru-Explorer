#include "core/Keyboard.h"
#include "utils/Camera.h" 
#include <GL/freeglut.h>
#include <stdlib.h>       

// Untuk mengendalikan pergerakan pemain.
extern Camera playerCamera; 

// Menangani input keyboard.
void handleKeyboard(unsigned char key, int x, int y) {
    // Menentukan kecepatan pergerakan kamera.
    float speed = 0.5f;
    // Memeriksa tombol keyboard yang ditekan.
    switch (key) {

        // W Kedepan
        case 'w': case 'W':
            playerCamera.MoveForward(speed);
            break;

        // S kebelakang
        case 's': case 'S':
            playerCamera.MoveBackward(speed);
            break;

        // A ke kiri
        case 'a': case 'A':
            playerCamera.MoveLeft(speed);
            break;
        
        // D ke kanan
        case 'd': case 'D':
            playerCamera.MoveRight(speed);
            break;

        case '1':
            playerCamera.eyeY = 1.5f; // Elevasi mata normal di Lantai 1
            break;
        case '2':
            playerCamera.eyeY = 8.0f; // Elevasi Lantai 2
            break;
        case '3':
            playerCamera.eyeY = 14.0f; 
            break;

        // ESC untuk exit
        case 27: // Kode ASCII ESC
            exit(0);
            break;
    }

    // Gambar ulang frame baru agar perubahan posisi kamera langsung terlihat.
    glutPostRedisplay();
}