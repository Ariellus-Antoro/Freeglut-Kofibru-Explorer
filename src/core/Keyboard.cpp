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
    const float eyeHeight = 2.5f;
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
            playerCamera.eyeY = 0.0f + eyeHeight; 
            break;
        case '2':
            playerCamera.eyeY = 8.0f; + eyeHeight;
            break;
        case '3':
            playerCamera.eyeY = 12.0f + eyeHeight; 
            break;

        // ESC untuk exit
        case 27: // Kode ASCII ESC
            exit(0);
            break;
    }

    // Gambar ulang frame baru agar perubahan posisi kamera langsung terlihat.
    glutPostRedisplay();
}