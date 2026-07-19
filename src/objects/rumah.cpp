#include <GL/freeglut.h>
#include "objects/rumah.h"
#include "objects/rumah_data.h"
#include "objects/Kofibru.h"
#include "objects/Pembatas.h"
#include "objects/Rumput.h"
#include "objects/Jalan.h"


Pembatas pembatasDepan;
Pembatas pembatasSamping;
Pembatas pembatasSerong;
Kofibru logoKofibru;
Rumput rumputDepan;
Rumput rumputSerong;
Rumput rumputKecil;
Kofibru logoKofibruKedua;
Jalan jalanDepan;
Jalan jalanSamping;

Rumah::Rumah()
{
    // Atap -- coklat gelap
    atapRed = 0.3f;
    atapGreen = 0.15f;
    atapBlue = 0.05f;

    // Tembok -- abu-abu
    tembokRed = 0.7f;
    tembokGreen = 0.7f;
    tembokBlue = 0.7f;

    // Pintu -- coklat
    pintuRed = 0.45f;
    pintuGreen = 0.28f;
    pintuBlue = 0.12f;

    // Jendela -- biru
    jendelaRed = 0.25f;
    jendelaGreen = 0.5f;
    jendelaBlue = 0.85f;
}

static void drawFaces(const RumahFace *facesArr, int count)
{
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < count; i++)
    {
        const RumahFace &f = facesArr[i];
        const RumahVertex &a = RumahVertices[f.v0];
        const RumahVertex &b = RumahVertices[f.v1];
        const RumahVertex &c = RumahVertices[f.v2];

        glNormal3f(f.nx, f.ny, f.nz);
        glVertex3f(a.x, a.y, a.z);
        glVertex3f(b.x, b.y, b.z);
        glVertex3f(c.x, c.y, c.z);
    }
    glEnd();
}

void Rumah::draw()
{
    glColor3f(atapRed, atapGreen, atapBlue);
    drawFaces(RumahAtapFaces, RUMAH_ATAP_FACE_COUNT);

    glColor3f(tembokRed, tembokGreen, tembokBlue);
    drawFaces(RumahTembokFaces, RUMAH_TEMBOK_FACE_COUNT);

    glColor3f(pintuRed, pintuGreen, pintuBlue);
    drawFaces(RumahPintuFaces, RUMAH_PINTU_FACE_COUNT);

    glColor3f(jendelaRed, jendelaGreen, jendelaBlue);
    drawFaces(RumahJendelaFaces, RUMAH_JENDELA_FACE_COUNT);
}

void Rumah::drawAll()
{
    glPushMatrix();

    // Posisi rumah di luar footprint Gedung (gedung berada kira-kira di
    // X -7.5..7, Z -5..8). Digeser jauh ke samping supaya jelas di luar.
    glTranslatef(20.0f, 0.0f, 0.0f);

    // Mesh asli dalam satuan cm -> skala ke satuan scene (meter-ish)
    glScalef(0.02f, 0.02f, 0.02f);

    // Koreksi orientasi: STL pakai Z-up (CAD), scene pakai Y-up (OpenGL)
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);

    draw();

    glPopMatrix();

    logoKofibru.drawAll();

    pembatasDepan.posX = 9.7f;
    pembatasDepan.posY = 0.0f;
    pembatasDepan.posZ = -7.7f;
    pembatasDepan.rotationY = 0.0f;
    pembatasDepan.length = 13.0f;
    pembatasDepan.height = 0.9f;
    pembatasDepan.thickness = 0.5f;

    pembatasSamping.posX = 5.0f;
    pembatasSamping.posY = 0.0f;
    pembatasSamping.posZ = 5.1f;
    pembatasSamping.rotationY = 90.0f;
    pembatasSamping.length = 4.9f;
    pembatasSamping.height = 0.9f;
    pembatasSamping.thickness = 0.5f;

    pembatasSerong.posX = 3.0f;
    pembatasSerong.posY = 0.0f;
    pembatasSerong.posZ = 3.0f;
    pembatasSerong.rotationY = 45.0f;
    pembatasSerong.length = 3.0f;
    pembatasSerong.height = 0.9f;
    pembatasSerong.thickness = 0.5f;

    // Rumput yang diatas pembatas
    rumputDepan.posX = 9.7f;
    rumputDepan.posY = 0.9f; // Taruh persis di atas pembatas (tinggi pembatas 0.9)
    rumputDepan.posZ = -4.5f;
    rumputDepan.length = 5.9f;
    rumputDepan.thickness = 0.3f;
    rumputDepan.height = 0.9f;

    // Di bagian constructor atau fungsi setup
    rumputSerong.posX = 4.1f;
    rumputSerong.posY = 0.9f; 
    rumputSerong.posZ = 4.1f;
    rumputSerong.rotationY = 45.0f; // Bisa dirotasi sesuai pembatasnya
    rumputSerong.height = 0.7f;     // Bisa diatur beda tiap objek
    rumputSerong.length = 2.5f;
    rumputSerong.thickness = 0.2f;

    rumputKecil.posX = 7.5f;
    rumputKecil.posY = 0.9f; 
    rumputKecil.posZ = 5.15f;
    rumputKecil.rotationY = 90.0f; // Bisa dirotasi sesuai pembatasnya
    rumputKecil.height = 0.7f;     // Bisa diatur beda tiap objeK
    rumputKecil.length = 4.4f;
    rumputKecil.thickness = 0.2f;

    //logo kedua
    logoKofibruKedua.drawDots = false;
    logoKofibruKedua.posX = -3.6f;    // ganti sesuai posisi dinding target
    logoKofibruKedua.posY = 3.0f;
    logoKofibruKedua.posZ = 7.9f;    // ganti sesuai posisi dinding target
    logoKofibruKedua.rotationY = 0.0f; // ganti sesuai arah hadap dinding
    logoKofibruKedua.targetHeight = 0.09f;
    logoKofibruKedua.letterSpacing = 0.05f;
    logoKofibruKedua.isBold = true;

    jalanDepan.posX = 5.0f;     // Geser titik tengah jalan ke kiri (X = -10)
    jalanDepan.posY = 0.0f;      // Agak naik sedikit agar tidak nabrak tanah
    jalanDepan.posZ = 18.0f;     // Posisi kedalaman (sesuaikan dengan jarak depan rumah)
    jalanDepan.rotationY = 0.0f;  
    
    // Jalan
    jalanDepan.width = 52.0f;     //  panjang dari kiri ke kanan
    jalanDepan.height = 0.1f;     // Ketebalan aspal (biar tipis)
    jalanDepan.length = 10.0f;  //lebar




    //Jalan samping
    jalanSamping.posX = 15.5f;    // Geser posisinya ke arah kiri (bisa disesuaikan, misalnya di antara ruko dan rumah)
    jalanSamping.posY = 0.0f;     // Tinggi sama dengan jalan depan biar tidak tumpang tindih aneh
    jalanSamping.posZ = -5.0f;      // Memanjang ke area belakang scene
    jalanSamping.rotationY = 0.0f; 
    
    // Dimensinya dibalik dari jalan utama
    jalanSamping.width = 10.0f;     // lebar kanan kiri jalan
    jalanSamping.height = 0.1f;    // Ketebalan tetap tipis
    jalanSamping.length = 50.0f; //panjang depan belakang

    // =====================
    // Pembatas jalur (eksterior)
    // =====================
    pembatasDepan.drawAll();
    pembatasSamping.drawAll();
    pembatasSerong.drawAll();
    rumputDepan.drawAll();
    rumputSerong.drawAll();
    rumputKecil.drawAll();
    logoKofibruKedua.drawAll();
    jalanDepan.drawAll();
    jalanSamping.drawAll();
    // =====================
    // Ruko (posisi & skala diatur di sini, persis pola kasir di Gedung.cpp)
    // =====================
    glPushMatrix();
    glTranslatef(-21.0f, 0.0f, 12.0f); // sesuaikan posisi ruko (relatif dari titik asal scene)
    glScalef(0.015f, 0.015f, 0.015f);  // mesh asli satuan cm, sesuaikan skala ruko di sini
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    ruko.draw();
    glPopMatrix();
}
