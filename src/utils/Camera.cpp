#include "utils/Camera.h"
#include <GL/freeglut.h>
#include <math.h>

// Nilai konstanta PI untuk konversi derajat ke radian.
const float PI = 3.14159265f;

// Konstruktor Camera.
// Menginisialisasi posisi awal kamera
Camera::Camera() {
    eyeX = 0.0f; eyeY = 2.5f; eyeZ = 5.0f; 
    upX = 0.0f; upY = 1.0f; upZ = 0.0f;
    
    yaw = -90.0f; 
    pitch = 0.0f;
    
    updateDirection();
}

// Menghitung arah pandangan kamera.
// Mengubah nilai yaw dan pitch menjadi vektor arah menggunakan trigonometri.
void Camera::updateDirection() {
    float radYaw = yaw * PI / 180.0f;
    float radPitch = pitch * PI / 180.0f;

    dirX = cos(radYaw) * cos(radPitch);
    dirY = sin(radPitch);
    dirZ = sin(radYaw) * cos(radPitch);
}


// Memutar kamera.
// Memperbarui nilai yaw dan pitch, kemudian menghitung ulang arah pandangan.
void Camera::rotate(float deltaYaw, float deltaPitch) {
    yaw += deltaYaw;
    pitch += deltaPitch;

    if (pitch > 89.0f) pitch = 89.0f;
    if (pitch < -89.0f) pitch = -89.0f;

    updateDirection();
}

// Menerapkan kamera ke OpenGL.
// Menggunakan fungsi gluLookAt() untuk menentukan posisi dan arah kamera.
void Camera::applyCamera() const {
    gluLookAt(eyeX, eyeY, eyeZ,
              eyeX + dirX, eyeY + dirY, eyeZ + dirZ,
              upX, upY, upZ);
}

void Camera::MoveForward(float speed) {
    eyeX += dirX * speed;
    eyeZ += dirZ * speed;
}

void Camera::MoveBackward(float speed) {
    eyeX -= dirX * speed;
    eyeZ -= dirZ * speed;
}

void Camera::MoveLeft(float speed) {
    float rad = (yaw - 90.0f) * PI / 180.0f;
    eyeX += cos(rad) * speed;
    eyeZ += sin(rad) * speed;
}

void Camera::MoveRight(float speed) {
    float rad = (yaw + 90.0f) * PI / 180.0f;
    eyeX += cos(rad) * speed;
    eyeZ += sin(rad) * speed;
}