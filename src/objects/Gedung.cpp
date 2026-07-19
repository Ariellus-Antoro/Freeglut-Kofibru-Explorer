#include "objects/Gedung.h"
#include "objects/KursiBulat.h"
#include "objects/MejaKasir.h"
#include "objects/Tangga.h"
#include "objects/ktembok.h"
#include "objects/mejakecil.h"
#include "objects/gelas.h"
#include "utils/Helper.h"
#include "objects/Wastafel.h"
#include "objects/Toilet.h"
#include "objects/MesinKopi.h"
#include "objects/TabungKopi.h"

MesinKopi mesinKopi;
TabungKopi tabungkopi;
Wastafel wastafel;
Toilet toilet;

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
    // 1. DINDING EKSTERIOR
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
    float protrusion = 2.5f; // Seberapa jauh dinding menjorok ke tengah ruangan
    float boothX = -7.25f + (protrusion / 2.0f);
    
    float greyColor = 0.45f; 
    float whiteColor = 0.95f;

    // Pembatas dekat meja kasir
    float depthPartisiDepan = 0.3f;
    drawBlock(boothX, startY, 2.5f, protrusion, wallHeight, depthPartisiDepan, greyColor, greyColor, greyColor);

    // Tebal & Berwarna Putih
    float depthPilarTengah = 1.2f;
    drawBlock(boothX, startY, 0.0f, protrusion, wallHeight, depthPilarTengah, whiteColor, whiteColor, whiteColor);

    // Menempel ke sudut belakang
    float depthPartisiBelakang = 1.5f;
    float zPartisiBelakang = -4.75f + (depthPartisiBelakang / 2.0f);  
    drawBlock(boothX, startY, zPartisiBelakang, protrusion, wallHeight, depthPartisiBelakang, greyColor, greyColor, greyColor);

    // =========================================================
    // 6. ATAP LANTAI 1 / PLAFON 
    // =========================================================
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
    // Elevasi lantai 2
    float startY = 4.0f; 
    float wallHeight = 3.5f; 
    float wallThickness = 0.5f; 
    
    float wallRed = 0.95f, wallGreen = 0.95f, wallBlue = 0.95f; 

    // =========================================================
    // 1. LANTAI / PIJAKAN LANTAI 2 (Menjorok ke Z = 8.0)
    // =========================================================
    drawBlock(0.75f, startY - 0.05f, 0.5f, 10.5f, 0.1f, 11.0f, 0.7f, 0.7f, 0.7f);
    
    // Ekstensi Balkon Tengah
    drawBlock(-0.5f, startY - 0.05f, 7.0f, 8.0f, 0.1f, 2.0f, 0.7f, 0.7f, 0.7f);

    // Sisi Kiri Dalam (Lantai interior di atas ruang utama L1)
    drawBlock(-6.0f, startY - 0.05f, 0.0f, 3.0f, 0.1f, 10.0f, 0.7f, 0.7f, 0.7f);
    

    // Sisi Kiri Depan
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
    // 3. MELENGKUNG (SUDUT KANAN DEPAN)
    // =========================================================
    float radius = 2.5f;
    drawCylinder(3.5f, startY, 3.5f, radius, wallHeight, wallRed, wallGreen, wallBlue);

    // =========================================================
    // 4. DINDING DEPAN
    // =========================================================
    drawWallWithHole(-7.5f, startY, 8.0f, 11.0f, wallHeight, wallThickness,
                     1.0f, 0.5f, 6.0f, 2.5f, 
                     wallRed, wallGreen, wallBlue);
                     
    // Tiang pemisah 
    drawBlock(-3.5f, startY + 0.5f, 8.0f, 0.5f, 2.5f, wallThickness, wallRed, wallGreen, wallBlue);

    // Dinding penyambung
    drawBlock(3.25f, startY, 7.0f, wallThickness, wallHeight, 2.0f, wallRed, wallGreen, wallBlue);

    // =========================================================
    // 5. ATAP LANTAI 2 / PLAFON 
    // =========================================================
    // Atap Bagian Kanan
    drawBlock(0.75f, startY + wallHeight, 1.5f, 10.5f, 0.5f, 13.0f, 0.8f, 0.8f, 0.8f);

    // Atap Bagian Kiri Dalam 
    drawBlock(-6.0f, startY + wallHeight, 0.0f, 3.0f, 0.5f, 10.0f, 0.8f, 0.8f, 0.8f);

    // Atap Bagian Kiri Depan 
    drawBlock(-6.0f, startY + wallHeight, 7.5f, 3.0f, 0.5f, 1.0f, 0.8f, 0.8f, 0.8f);

    // =========================================================
    // TEMBOK SEKAT INTERNAL
    // =========================================================

    // =========================================================
    // DUA PINTU TERPISAH (Sesuai Sketsa)
    // =========================================================
    float tinggi = 3.5f;
    float thickness = 0.3f;
    float pHeight = 2.5f;

    drawWallWithHole(
    -7.5f, startY, 3.5f,
    4.0f, tinggi, thickness,
    1.0f, 0.0f, 1.0f, pHeight,
    wallRed, wallGreen, wallBlue
    );

    // Dinding pemisah
    drawBlock(
        -3.25f, startY, 3.5f,
        0.5f, tinggi, thickness,
        wallRed, wallGreen, wallBlue
    );

    // Kanan (pintu besar)
    drawWallWithHole(
        -3.0f, startY, 3.5f,
        6.0f, tinggi, thickness,
        1.0f, 0.0f, 1.5f, pHeight,
        wallRed, wallGreen, wallBlue
    );

    float lorongZ_depan = 3.5f;
    float lorongZ_belakang = -5.0f; // Sesuaikan jika dinding belakangmu berbeda
    float lorongPanjang = lorongZ_depan - lorongZ_belakang; // Total panjang 8.5f
    
    // Mepet di dinding pemisah pintu
    float lorongX = -5.0f; 
    // Titik tengah balok Z agar pas terhubung dari depan ke belakang
    float lorongZ = (lorongZ_depan + lorongZ_belakang) / 2.0f; 
    
    drawBlock(
        lorongX, startY, lorongZ, 
        thickness, tinggi, lorongPanjang, 
        wallRed, wallGreen, wallBlue
    );

    // =========================================================
    // TEMBOK HORIZONTAL (Kiri ke Kanan)
    // =========================================================
    float panjangTembokH = 8.3f; // Atur seberapa panjang tembok horizontal ini
    
    float posisiX_TembokH = -1.3f; 
    
    // Geser Z maju mendekati kamera (+) atau mundur (-)
    float posisiZ_TembokH = -3.0f; 
    
    drawBlock(
        posisiX_TembokH, startY, posisiZ_TembokH, 
        panjangTembokH, tinggi, thickness, // Perhatikan: X (lebar) panjang, Z (kedalaman) tipis
        wallRed, wallGreen, wallBlue
    );

    // Tembok Smoking Room
    drawWallWithHoleZ(3.0f, startY, -5.0f, 
                      8.5f, wallHeight, 0.3f, 
                      3.25f, 0.0f, 2.0f, 2.5f, 
                      wallRed, wallGreen, wallBlue);
    
}


void Gedung::drawLantai3() {
    float startY = 8.0f; 
    
    float wallHeight = 3.5f;    
    float fasadHeight = 5.8f;   
    float wallThickness = 0.5f;
    
    float wallRed = 0.95f, wallGreen = 0.95f, wallBlue = 0.95f; 
    float glassR = 0.85f, glassG = 0.85f, glassB = 0.85f;

    // =========================================================
    // 1. DINDING EKSTERIOR
    // =========================================================
    drawBlock(-0.75f, startY, -5.0f, 13.5f, fasadHeight, wallThickness, wallRed, wallGreen, wallBlue); // Belakang
    drawBlock(-7.5f, startY, 1.5f, wallThickness, fasadHeight, 13.0f, wallRed, wallGreen, wallBlue);   // Kiri

    //DINDING KANAN Rakitan 3 Jendela-
    // Tembok Bawah dan Tembok Atas 
    float windowBottom = 1.0f;
    float windowHeight = 1.5f;
    drawBlock(6.0f, startY, -0.75f, wallThickness, 1.0f, 8.5f, wallRed, wallGreen, wallBlue); 
    drawBlock(6.0f, startY + windowBottom + windowHeight, -0.75f, wallThickness, fasadHeight - (windowBottom + windowHeight),8.5f, wallRed, wallGreen, wallBlue);
    
    // Pilar-pilar pemisah jendela
    drawBlock(6.0f, startY + 1.0f, -4.25f, wallThickness, 1.5f, 1.5f, wallRed, wallGreen, wallBlue); // Pilar 1 (Paling Belakang)
    drawBlock(6.0f, startY + 1.0f, -2.0f, wallThickness, 1.5f, 1.0f, wallRed, wallGreen, wallBlue);  // Pilar 2
    drawBlock(6.0f, startY + 1.0f, 0.0f, wallThickness, 1.5f, 1.0f, wallRed, wallGreen, wallBlue);   // Pilar 3
    drawBlock(6.0f, startY + 1.0f, 2.5f, wallThickness, 1.5f, 2.0f, wallRed, wallGreen, wallBlue);   // Pilar 4 (Paling Depan)

    // =========================================================
    // IMPLEMENTASI 3 JENDELA
    // =========================================================
    float winWidth = 1.0f; 
    float winHeight = 1.5f; 
    float winThick = 0.3f; 

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
    // 2. RUANG INDOOR 
    // =========================================================

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


    glPushMatrix();
    glTranslatef(3.5f, startY, 3.5f); // Titik pusat lengkungan

    glEnable(GL_BLEND); //Kaca
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);  //Kaca
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

    glDisable(GL_BLEND); //Disable kaca
    glDepthMask(GL_TRUE);
    
    glPopMatrix();

    // =========================================================
    // 5. ATAP UTAMA GEDUNG & KANOPI DEPAN
    // =========================================================
    // Atap Utama 
    drawBlock(-0.75f, startY + fasadHeight, -0.75f, 13.5f, 0.5f, 8.5f, 0.8f, 0.8f, 0.8f);
    
    // Atap Kanopi Ekstensi
    drawBlock(-4.0f, startY + fasadHeight, 5.75f, 7.0f, 0.5f, 4.5f, 0.8f, 0.8f, 0.8f);

    // =========================================================
    // 6. PILAR PENYANGGA KANOPI (Agar tidak mengambang)
    // =========================================================
    // Ketebalan pilar
    float pillarThick = 0.4f; 

    // Pilar 1: Kiri Depan 
    drawBlock(-7.2f, startY, 7.7f, pillarThick, fasadHeight, pillarThick, wallRed, wallGreen, wallBlue);
    
    // Pilar 2: Kanan Depan 
    drawBlock(-1.0f, startY, 7.7f, pillarThick, fasadHeight, pillarThick, wallRed, wallGreen, wallBlue);

    // =========================================================
    // 7. ATAP TEBAL
    // =========================================================
    float fR = 0.65f, fG = 0.65f, fB = 0.65f;
    float fHeight = 0.8f;
    float fThick = 0.2f; 
    
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
    wastafel.drawAll();
    toilet.drawAll();
    mesinKopi.drawAll();
    tabungkopi.drawAll();
    glPopMatrix();
}