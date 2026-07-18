#include "objects/Gedung.h"
#include "objects/KursiBulat.h"
#include "objects/MejaKasir.h"
#include "objects/Tangga.h"
#include "objects/ktembok.h"
#include "objects/mejakecil.h"
#include "objects/gelas.h"
#include "utils/Helper.h"

#include <math.h>

Gedung::Gedung() {
    // skala bangunan
    buildingScale = 1.5f; 
}


void Gedung::drawKeramik(float startX, float startZ, float endX, float endZ, float posY, float tileSize) {
    glPushMatrix();
    
    // Menempatkan lantai pada elevasi (Y) yang diminta
    glTranslatef(0.0f, posY, 0.0f); 

    glBegin(GL_QUADS);
    int row = 0;
    for (float z = startZ; z < endZ; z += tileSize) {
        int col = 0;
        for (float x = startX; x < endX; x += tileSize) {
            
            // Logika selang-seling warna keramik
            if ((row + col) % 2 == 0) {
                glColor3f(0.85f, 0.85f, 0.85f); // Warna terang
            } else {
                glColor3f(0.70f, 0.70f, 0.70f); // Warna agak gelap
            }

            // Menggambar 1 kotak keramik
            glVertex3f(x, 0.0f, z);
            glVertex3f(x + tileSize, 0.0f, z);
            glVertex3f(x + tileSize, 0.0f, z + tileSize);
            glVertex3f(x, 0.0f, z + tileSize);
            
            col++;
        }
        row++;
    }
    glEnd();
    glPopMatrix();
}

void Gedung::drawLantai1() {
    float startY = 0.0f;
    float wallHeight = 3.5f; 
    float wallThickness = 0.5f; 
    float wallRed = 0.75f, wallGreen = 0.75f, wallBlue = 0.75f; // Warna dinding abu-abu standar

    // =========================================================
    // 0. Ubin
    // ========================================================
    
    drawKeramik(-7.5f, -5.0f, 6.0f, 5.0f, -0.05f, 1.2f);

    // =========================================================
    // 1. DINDING EKSTERIOR (BATAS LUAR BANGUNAN)
    // =========================================================
    // Dinding Eksterior Kiri (Sisi terluar dari Ruang Utama / Main Area)
    drawBlock(-7.5f, startY, 0.0f, wallThickness, wallHeight, 10.0f, wallRed, wallGreen, wallBlue); 
    
    // Dinding Eksterior Belakang (Membentang lurus menutupi Ruang Utama dan Toilet)
    drawBlock(-0.75f, startY, -5.0f, 13.5f, wallHeight, wallThickness, wallRed, wallGreen, wallBlue);
    
    // =========================================================
    // 2. AREA TOILET & LORONG (SUDUT KANAN ATAS)
    // =========================================================
    // Dinding Eksterior Kanan (Membentuk sisi kanan dari area toilet dan lorong)
    drawBlock(6.0f, startY, -2.0f, wallThickness, wallHeight, 6.0f, wallRed, wallGreen, wallBlue); 
    
    // Dinding Eksterior Depan Lorong (Menutup ujung lorong di sebelah kanan bangunan)
    drawBlock(5.0f, startY, 1.0f, 2.0f, wallHeight, wallThickness, wallRed, wallGreen, wallBlue);
    
    // Dinding Sekat Depan Toilet (Dilengkapi lubang untuk pintu masuk toilet)
    drawWallWithHole(2.0f, startY, -1.0f, 4.0f, wallHeight, wallThickness, 
                     0.2f, 0.0f, 1.5f, 2.5f, 
                     wallRed, wallGreen, wallBlue);

    // =========================================================
    // 3. DINDING SEKAT INTERNAL (PEMBAGI RUANGAN)
    // =========================================================
    // Dinding Sekat Vertikal (Memisahkan Ruang Utama di sebelah kiri dengan area Lorong/Toilet di kanan. Dilengkapi pintu penghubung internal)
    drawWallWithHoleZ(2.0f, startY, -5.0f, 7.0f, wallHeight, wallThickness, 
                      4.5f, 0.0f, 1.5f, 2.5f, 
                      wallRed, wallGreen, wallBlue);

    // =========================================================
    // 4. AREA FASAD DEPAN & PINTU UTAMA
    // =========================================================
    // Dinding Sudut Dalam Horizontal (Tembok yang menjorok ke dalam ruangan, tempat pintu penghubung depan berada)
    drawWallWithHole(-2.0f, startY, 2.0f, 4.0f, wallHeight, wallThickness, 
                     0.5f, 0.0f, 3.0f, 2.5f, 
                     wallRed, wallGreen, wallBlue);
    
    // Dinding Sudut Dalam Vertikal (Membentuk siku-siku pada area pintu depan yang menjorok ke dalam)
    drawBlock(-2.0f, startY, 3.5f, wallThickness, wallHeight, 3.0f, wallRed, wallGreen, wallBlue);

    // Dinding Fasad Pintu Masuk (Batas depan Ruang Utama. Posisi lubang pintu diatur agar rata kanan menempel dengan dinding siku-siku)
    drawWallWithHole(-7.5f, startY, 5.0f, 5.5f, wallHeight, wallThickness, 
                     3.8f, 0.0f, 1.2f, 2.5f, 
                     wallRed, wallGreen, wallBlue);

    // =========================================================
    // 5. AREA BOOTH SEATING (SISI KIRI MAIN AREA)
    // =========================================================
    // Kedalaman semua pilar/partisi disamakan agar membentuk dinding lurus 
    // dengan cekungan di dalamnya (sesuai referensi foto).
    
    float protrusion = 2.5f; // Seberapa jauh dinding menjorok ke tengah ruangan
    float boothX = -7.25f + (protrusion / 2.0f); // X = -6.0f (Agar menempel dinding kiri)
    
    float greyColor = 0.45f;  // Warna abu-abu gelap untuk partisi samping
    float whiteColor = 0.95f; // Warna putih bersih untuk pilar tengah

    // 5A. Partisi Depan (Pembatas dekat meja kasir)
    float depthPartisiDepan = 0.3f;
    drawBlock(boothX, startY, 2.5f, protrusion, wallHeight, depthPartisiDepan, greyColor, greyColor, greyColor);

    // 5B. Pilar Tengah (Tebal & Berwarna Putih)
    float depthPilarTengah = 1.2f;
    drawBlock(boothX, startY, 0.0f, protrusion, wallHeight, depthPilarTengah, whiteColor, whiteColor, whiteColor);

    // 5C. Partisi / Kotak Belakang (Menempel ke sudut belakang)
    float depthPartisiBelakang = 1.5f;
    float zPartisiBelakang = -4.75f + (depthPartisiBelakang / 2.0f); // Merapat ke belakang
    drawBlock(boothX, startY, zPartisiBelakang, protrusion, wallHeight, depthPartisiBelakang, greyColor, greyColor, greyColor);

// =========================================================
    // 6. ATAP LANTAI 1 / PLAFON (Dengan Void Tangga)
    // =========================================================
    // Bagian Kanan (Menutup area utama hingga batas void)
    // Lebar 10.5 (X: -4.5 sampai 6.0), Kedalaman utuh 10.0 (Z: -5.0 sampai 5.0)
    drawBlock(-0.75f, wallHeight, 0.0f, 13.5f, 0.5f, 10.0f, 0.8f, 0.8f, 0.8f);
}

void Gedung::drawFurnitureLantai1(){

    // Kursi 1
    glPushMatrix();

    glTranslatef(1.5f, 0.1f, -2.0f);
    glRotatef(-40.0f, 0.0f, 1.0f, 0.0f);
    glScalef(0.1f, 0.1f, 0.1f);

    chair.draw();
    glPopMatrix();

    // Kursi 2
    glPushMatrix();

    glTranslatef(1.4f, 0.1f, -1.3f);
    glRotatef(-50.0f, 0.0f, 1.0f, 0.0f);
    glScalef(0.1f, 0.1f, 0.1f);

    chair.draw();
    glPopMatrix();

    // Kursi 3
    glPushMatrix();

    glTranslatef(1.5f, 0.1f, -0.7f);
    glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
    glScalef(0.1f, 0.1f, 0.1f);

    chair.draw();

    glPopMatrix();
    //meja kasir
    glPushMatrix();

    glTranslatef(-0.8f, 0.0f, -2.8f);   // Atur posisi
    glRotatef(180.0f, 0.0f, 1.0f, 0.0f); // Arah hadap
    glScalef(0.4f, 0.4f, 0.4f);         // Ukuran

    cashierTable.draw();

    glPopMatrix();

    //menu
    glPushMatrix();

    glTranslatef(0.3f, 0.9f, -2.6f); // Di atas meja kasir
    glScalef(0.3f,0.3f,0.3f);

    menu.draw();

    glPopMatrix();
    // Rak Atas
    glPushMatrix();

    glTranslatef(-1.0f,2.5f,-4.6f);

    glScalef(0.5f,0.5f,0.5f);

    rakKasir.draw();

    glPopMatrix();


    // Rak Bawah
    glPushMatrix();

    glTranslatef(-1.0f,1.7f,-4.6f);

    glScalef(0.5f,0.5f,0.5f);

    rakKasir.draw();

glPopMatrix();
}

void Gedung::drawLantai2() {
    // Elevasi lantai 2 dimulai di atas dinding Lantai 1 (3.5) + ketebalan kanopi (0.5)
    float startY = 4.0f; 
    float wallHeight = 3.5f; 
    float wallThickness = 0.5f; 
    
    // Warna dinding Lantai 2 (Putih bersih sesuai referensi)
    float wallRed = 0.95f, wallGreen = 0.95f, wallBlue = 0.95f; 

// =========================================================
    // 1. LANTAI / PIJAKAN LANTAI 2 (Menjorok ke Z = 8.0)
    // =========================================================
    // Sisi Kanan (Area utuh, menjorok ke depan menutupi teras)
   // 1A. Sisi Kanan Utama (Berhenti di Z = 6.0 agar tidak menembus keluar dinding lengkung)
    // Lebar 10.5 (X: -4.5 sampai 6.0), Kedalaman 11.0 (Z: -5.0 sampai 6.0 -> Center Z = 0.5)
    drawBlock(0.75f, startY - 0.05f, 0.5f, 10.5f, 0.1f, 11.0f, 0.7f, 0.7f, 0.7f);
    
    // 1B. Ekstensi Balkon Tengah (Maju dari Z = 6.0 ke 8.0, berhenti merapat di dinding konektor X = 3.5)
    // Lebar 8.0 (X: -4.5 sampai 3.5 -> Center X = -0.5), Kedalaman 2.0 (Z: 6.0 sampai 8.0 -> Center Z = 7.0)
    drawBlock(-0.5f, startY - 0.05f, 7.0f, 8.0f, 0.1f, 2.0f, 0.7f, 0.7f, 0.7f);

    // 1C. Sisi Kiri Dalam (Lantai interior di atas ruang utama L1)
    // Kedalaman 10.0 (Z: -5.0 sampai 5.0 -> Center Z = 0.0)
    drawBlock(-6.0f, startY - 0.05f, 0.0f, 3.0f, 0.1f, 10.0f, 0.7f, 0.7f, 0.7f);
    
    // (Area Z=5.0 hingga Z=7.0 di sebelah kiri dibiarkan KOSONG sebagai void tangga)

    // 1D. Sisi Kiri Depan (Pijakan Balkon menutupi area di depan void tangga)
    // Kedalaman 1.0 (Z: 7.0 sampai 8.0 -> Center Z = 7.5)
    drawBlock(-6.0f, startY - 0.05f, 7.5f, 3.0f, 0.1f, 1.0f, 0.7f, 0.7f, 0.7f);

    // =========================================================
    // 2. DINDING BELAKANG, KIRI, & KANAN
    // =========================================================
    drawBlock(-0.75f, startY, -5.0f, 13.5f, wallHeight, wallThickness, wallRed, wallGreen, wallBlue);

    // Dinding Kiri
    drawBlock(-7.5f, startY, 1.5f, wallThickness, wallHeight, 13.0f, wallRed, wallGreen, wallBlue);

    // DINDING KANAN (Dengan Jendela)
    drawWallWithHoleZ(6.0f, startY, -5.0f, 
                      8.5f, wallHeight, wallThickness, 
                      1.0f, 0.7f, 3.0f, 1.5f, 
                      wallRed, wallGreen, wallBlue);

    // =========================================================
    // 3. FASAD MELENGKUNG (SUDUT KANAN DEPAN)
    // =========================================================
    float radius = 2.5f;
    drawCylinder(3.5f, startY, 3.5f, radius, wallHeight, wallRed, wallGreen, wallBlue);

    // =========================================================
    // 4. DINDING DEPAN (OVERHANG & BALKON BESAR)
    // =========================================================
    // Dinding balkon ditarik maju ke Z = 8.0
    drawWallWithHole(-7.5f, startY, 8.0f, 11.0f, wallHeight, wallThickness,
                     1.0f, 0.5f, 6.0f, 2.5f, 
                     wallRed, wallGreen, wallBlue);
                     
    // Tiang pemisah (Mullion) di Z = 8.0
    drawBlock(-3.5f, startY + 0.5f, 8.0f, 0.5f, 2.5f, wallThickness, wallRed, wallGreen, wallBlue);

    // Dinding penyambung: X di 3.25 (merapat ke sisi lengkungan), Z di 7.0, kedalaman 2.0
    drawBlock(3.25f, startY, 7.0f, wallThickness, wallHeight, 2.0f, wallRed, wallGreen, wallBlue);

// =========================================================
    // 5. ATAP LANTAI 2 / PLAFON (Dengan Void Tangga ke L3)
    // =========================================================
    // Atap Bagian Kanan (Menutup area kanan secara utuh)
    drawBlock(0.75f, startY + wallHeight, 1.5f, 10.5f, 0.5f, 13.0f, 0.8f, 0.8f, 0.8f);

    // ---> INI BAGIAN YANG DILUBANGI UNTUK TANGGA <---
    // Atap Bagian Kiri Dalam (Berhenti sebelum area tangga)
    drawBlock(-6.0f, startY + wallHeight, 0.0f, 3.0f, 0.5f, 10.0f, 0.8f, 0.8f, 0.8f);

    // Atap Bagian Kiri Depan (Melanjutkan penutup setelah area tangga)
    drawBlock(-6.0f, startY + wallHeight, 7.5f, 3.0f, 0.5f, 1.0f, 0.8f, 0.8f, 0.8f);

    // =========================================================
    // TEMBOK SEKAT INTERNAL
    // =========================================================

    drawWallWithHole(-7.5f, startY, 3.5f, 
                     13.5f, wallHeight, 0.3f, 
                     4.0f, 0.0f, 2.0f, 2.5f, 
                     wallRed, wallGreen, wallBlue);


    drawWallWithHoleZ(3.0f, startY, -5.0f, 
                      8.5f, wallHeight, 0.3f, 
                      3.25f, 0.0f, 2.0f, 2.5f, 
                      wallRed, wallGreen, wallBlue);
    
}


void Gedung::drawLantai3() {
    float startY = 8.0f; 
    
    // Kita pisahkan tinggi dinding indoor dan eksterior
    float wallHeight = 3.5f;      // Tinggi normal untuk ruang indoor
    float fasadHeight = 8.0f;     // Tinggi dinding luar dibuat menjulang
    float wallThickness = 0.5f;
    
    float wallRed = 0.95f, wallGreen = 0.95f, wallBlue = 0.95f; 
    float glassR = 0.85f, glassG = 0.85f, glassB = 0.85f;

    // =========================================================
    // 1. DINDING EKSTERIOR
    // =========================================================
    drawBlock(-0.75f, startY, -5.0f, 13.5f, fasadHeight, wallThickness, wallRed, wallGreen, wallBlue); // Belakang
    drawBlock(-7.5f, startY, 1.5f, wallThickness, fasadHeight, 13.0f, wallRed, wallGreen, wallBlue);   // Kiri

    // ---> DINDING KANAN (Rakitan 3 Jendela) <---
    // Tembok Bawah (Sill) dan Tembok Atas (Header)
    drawBlock(6.0f, startY, -0.75f, wallThickness, 1.0f, 8.5f, wallRed, wallGreen, wallBlue); 
    drawBlock(6.0f, startY + 2.5f, -0.75f, wallThickness, fasadHeight - 2.5f, 8.5f, wallRed, wallGreen, wallBlue);
    
    // Pilar-pilar pemisah jendela
    drawBlock(6.0f, startY + 1.0f, -4.25f, wallThickness, 1.5f, 1.5f, wallRed, wallGreen, wallBlue); // Pilar 1 (Paling Belakang)
    drawBlock(6.0f, startY + 1.0f, -2.0f, wallThickness, 1.5f, 1.0f, wallRed, wallGreen, wallBlue);  // Pilar 2
    drawBlock(6.0f, startY + 1.0f, 0.0f, wallThickness, 1.5f, 1.0f, wallRed, wallGreen, wallBlue);   // Pilar 3
    drawBlock(6.0f, startY + 1.0f, 2.5f, wallThickness, 1.5f, 2.0f, wallRed, wallGreen, wallBlue);   // Pilar 4 (Paling Depan)

    // =========================================================
    // IMPLEMENTASI 3 JENDELA DENGAN FUNGSI HELPER
    // =========================================================
    float winWidth = 1.0f;  // Lebar bukaan jendela
    float winHeight = 1.5f; // Tinggi bukaan jendela
    float winThick = 0.3f;  // Ketebalan kusen

    // Jendela 1 (Paling Belakang)
    glPushMatrix();
    glTranslatef(6.0f, startY + 1.0f, -3.0f); 
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f); 
    drawWindow(0.0f, 0.0f, 0.0f, winWidth, winHeight, winThick); 
    glPopMatrix();

    // Jendela 2 (Tengah)
    glPushMatrix();
    glTranslatef(6.0f, startY + 1.0f, -1.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    drawWindow(0.0f, 0.0f, 0.0f, winWidth, winHeight, winThick);
    glPopMatrix();

    // Jendela 3 (Paling Depan)
    glPushMatrix();
    glTranslatef(6.0f, startY + 1.0f, 1.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    drawWindow(0.0f, 0.0f, 0.0f, winWidth, winHeight, winThick);
    glPopMatrix();

    // =========================================================
    // 2. RUANG INDOOR (Partisi Kaca)
    // =========================================================
    // Kaca biasanya jauh lebih tipis dari tembok beton standar, 
    // jadi kita ubah ketebalannya dari 0.3f menjadi 0.1f
    float indoorThickness = 0.1f; 
    float alphaKaca = 0.35f;

    // Dinding Kiri Indoor
    drawBlock(-4.5f, startY, -1.0f, indoorThickness, wallHeight, 6.0f, glassR, glassG, glassB,alphaKaca);
    
    // Dinding Kanan Indoor
    drawBlock(3.5f, startY, -1.0f, indoorThickness, wallHeight, 6.0f, glassR, glassG, glassB,alphaKaca);
    
    // Dinding Belakang Indoor
    drawBlock(-0.5f, startY, -4.0f, 8.0f, wallHeight, indoorThickness, glassR, glassG, glassB,alphaKaca);

    // Dinding Depan Indoor (Tetap menggunakan lubang untuk area pintu masuk)
    drawWallWithHole(-4.5f, startY, 2.0f, 8.3f, wallHeight, indoorThickness, 
                     3.15f, 0.0f, 2.0f, 2.5f, 
                     glassR, glassG, glassB,alphaKaca);
    // =========================================================
    // 3. ATAP INDOOR
    // =========================================================
    drawBlock(-0.5f, startY + wallHeight, -1.0f, 8.3f, 0.5f, 6.3f, 0.8f, 0.8f, 0.8f);

    // =========================================================
    // 4. PAGAR BALKON OUTDOOR (Lurus & Melengkung)
    // =========================================================
    float pagarHeight = 1.2f; 
    float pagarThickness = 0.2f; 

    // Pagar Lurus Depan
    drawBlock(-2.0f, startY, 8.0f, 11.0f, pagarHeight, pagarThickness, glassR, glassG, glassB,alphaKaca);
    
    // Pagar Konektor Kanan
    drawBlock(3.25f, startY, 7.0f, pagarThickness, pagarHeight, 2.0f, glassR, glassG, glassB,alphaKaca);

    // Mengganti gluCylinder dengan GL_QUAD_STRIP untuk menggambar 
    // hanya seperempat lingkaran (kuadran luar) agar tidak tembus ke dalam.
    glPushMatrix();
    glTranslatef(3.5f, startY, 3.5f); // Titik pusat lengkungan

    glEnable(GL_BLEND);                                  // <-- Aktifkan Kaca
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);   // <-- Aktifkan Kaca
    glDepthMask(GL_FALSE);
    glColor4f(glassR, glassG, glassB, alphaKaca);

    glBegin(GL_QUAD_STRIP);
    int segments = 16; 
    float PI = 3.14159265f;
    float radius = 2.5f;
    
    for (int i = 0; i <= segments; i++) {
        float angle = i * (PI / 2.0f) / segments; 
        float px = radius * cos(angle); 
        float pz = radius * sin(angle);
        
        glVertex3f(px, 0.0f, pz);           
        glVertex3f(px, pagarHeight, pz);    
    }
    glEnd();

    glDisable(GL_BLEND);                                 // <-- Matikan Kaca
    glDepthMask(GL_TRUE);
    
    glPopMatrix();

    // =========================================================
    // 5. ATAP UTAMA GEDUNG & KANOPI DEPAN
    // =========================================================
    // Atap Utama (Menutupi badan gedung dari belakang hingga batas melengkung)
    drawBlock(-0.75f, startY + fasadHeight, -0.75f, 13.5f, 0.5f, 8.5f, 0.8f, 0.8f, 0.8f);
    
    // Atap Kanopi Ekstensi (Menjorok ke depan hanya di sisi kiri atas balkon)
    drawBlock(-4.0f, startY + fasadHeight, 5.75f, 7.0f, 0.5f, 4.5f, 0.8f, 0.8f, 0.8f);

    // =========================================================
    // 6. PILAR PENYANGGA KANOPI (Agar tidak mengambang)
    // =========================================================
    // Ketebalan pilar dibuat 0.4f (ramping agar tidak menghalangi pandangan)
    float pillarThick = 0.4f; 

    // Pilar 1: Kiri Depan (Diletakkan dekat sudut luar pagar balkon L3)
    drawBlock(-7.2f, startY, 7.7f, pillarThick, fasadHeight, pillarThick, wallRed, wallGreen, wallBlue);
    
    // Pilar 2: Kanan Depan (Diletakkan di ujung batas kanan kanopi)
    drawBlock(-1.0f, startY, 7.7f, pillarThick, fasadHeight, pillarThick, wallRed, wallGreen, wallBlue);

    // =========================================================
    // 7. ATAP TEBAL
    // =========================================================
    // Warna fascia bisa dibuat sedikit lebih gelap dari atap agar ada kontras
    float fR = 0.65f, fG = 0.65f, fB = 0.65f;
    float fHeight = 0.8f; // Fascia sedikit lebih tinggi dari atap (0.5f)
    float fThick = 0.2f;  // Sedikit menjorok ke luar
    
    // Bingkai depan (Memanjang sepanjang fasad)
    drawBlock(-0.85f, startY + fasadHeight - 0.3f, -0.85f, 13.7f, fHeight, fThick, fR, fG, fB);
    
    // Bingkai samping kanan
    drawBlock(6.1f, startY + fasadHeight - 0.3f, -0.85f, fThick, fHeight, 8.7f, fR, fG, fB);
}
void Gedung::drawAll() {
    glPushMatrix();
    
    glScalef(buildingScale, buildingScale, buildingScale); 

   
    drawLantai1();
    drawLantai2(); 
    drawLantai3();
    drawFurnitureLantai1();    
    tangga.draw(-6.0f, 0.0f, 6.0f);
    tangga.draw(-6.0f, 4.0f, 6.0f);
    glPopMatrix();
}