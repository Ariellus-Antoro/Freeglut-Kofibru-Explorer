
#ifndef CAMERA_H
#define CAMERA_H

class Camera {
public:

    // Konstruktor Camera.
    // Menginisialisasi posisi awal kamera, arah atas (up vector),
    // serta sudut awal yaw dan pitch.
    Camera();

    // Fungsi untuk memanggil gluLookAt() dan vektor arah
    void applyCamera() const; 

    // Fungsi untuk memutar kamera
    // deltaYaw Perubahan sudut horizontal
    // deltaPitch Perubahan sudut vertikal 
    void rotate(float deltaYaw, float deltaPitch);

    // Menggerakan kamera ke depan
    void MoveForward(float speed);

    // Menggerakan kamera ke belakang
    void MoveBackward(float speed);

    // Menggerakan kamera ke kiri
    void MoveLeft(float speed);

    // Menggerakan kamera ke kanan
    void MoveRight(float speed);

    // Posisi kamera dalam koordinat dunia.
    float eyeX, eyeY, eyeZ;

private:


    // Vektor arah pandangan kamera.
    float dirX, dirY, dirZ;

    // Up vector kamera
    float upX, upY, upZ;

    //Sudut rotasi horizontal
    float yaw;

    //Sudut rotasi vertikal
    float pitch;

    void updateDirection();
};

#endif