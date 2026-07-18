#include "objects/Gedung.h"
#include "objects/KursiBulat.h"
#include "objects/MejaKasir.h"
#include "objects/Tangga.h"


Gedung::Gedung() {
    // skala bangunan
    buildingScale = 1.5f; 
}

void Gedung::drawBlock(float posX, float posY, float posZ, float w, float h, float d, float r, float g, float b) {
    glPushMatrix();
    glColor3f(r, g, b);
    glTranslatef(posX, posY + (h / 2.0f), posZ); // Pivot di tengah bawah
    glScalef(w, h, d);
    glutSolidCube(1.0);
    glPopMatrix();
}

void Gedung::drawCylinder(float posX, float posY, float posZ, float radius, float h, float r, float g, float b) {
    glPushMatrix();
    glColor3f(r, g, b);
    glTranslatef(posX, posY, posZ);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    
    GLUquadric* quad = gluNewQuadric();
    gluCylinder(quad, radius, radius, h, 32, 1);
    glTranslatef(0.0f, 0.0f, h);
    gluDisk(quad, 0.0, radius, 32, 1);
    
    gluDeleteQuadric(quad);
    glPopMatrix();
}

void Gedung::drawWallWithHole(float posX, float posY, float posZ, 
                              float wallW, float wallH, float thickness, 
                              float holeX, float holeY, float holeW, float holeH, 
                              float r, float g, float b) {
    
    // 1. Bagian Kiri (Tembok dari ujung kiri sampai batas mulai lubang)
    if (holeX > 0) {
        float leftWidth = holeX;
        float centerLeftX = posX + (leftWidth / 2.0f);
        drawBlock(centerLeftX, posY, posZ, leftWidth, wallH, thickness, r, g, b);
    }
    
    // 2. Bagian Kanan (Tembok dari batas akhir lubang sampai ujung kanan)
    float rightWidth = wallW - (holeX + holeW);
    if (rightWidth > 0) {
        float centerRightX = posX + holeX + holeW + (rightWidth / 2.0f);
        drawBlock(centerRightX, posY, posZ, rightWidth, wallH, thickness, r, g, b);
    }
    
    // 3. Bagian Bawah (Tembok penahan di bawah jendela/lubang, dilewati jika ini adalah pintu)
    if (holeY > 0) {
        float centerHoleX = posX + holeX + (holeW / 2.0f);
        drawBlock(centerHoleX, posY, posZ, holeW, holeY, thickness, r, g, b);
    }
    
    // 4. Bagian Atas / Lintel (Tembok penghubung di atas pintu/jendela)
    float topHeight = wallH - (holeY + holeH);
    if (topHeight > 0) {
        float centerHoleX = posX + holeX + (holeW / 2.0f);
        float topY = posY + holeY + holeH;
        drawBlock(centerHoleX, topY, posZ, holeW, topHeight, thickness, r, g, b);
    }
}

void Gedung::drawWallWithHoleZ(float positionX, float positionY, float positionZ, 
                               float wallDepth, float wallHeight, float wallThickness, 
                               float holeZ, float holeY, float holeDepth, float holeHeight, 
                               float colorRed, float colorGreen, float colorBlue) {
    
    // 1. Bagian Belakang (Tembok pada sumbu Z sebelum lubang)
    if (holeZ > 0) {
        float backDepth = holeZ;
        float centerZ = positionZ + (backDepth / 2.0f);
        drawBlock(positionX, positionY, centerZ, wallThickness, wallHeight, backDepth, colorRed, colorGreen, colorBlue);
    }
    
    // 2. Bagian Depan (Tembok pada sumbu Z setelah lubang)
    float frontDepth = wallDepth - (holeZ + holeDepth);
    if (frontDepth > 0) {
        float centerZ = positionZ + holeZ + holeDepth + (frontDepth / 2.0f);
        drawBlock(positionX, positionY, centerZ, wallThickness, wallHeight, frontDepth, colorRed, colorGreen, colorBlue);
    }
    
    // 3. Bagian Bawah (Dilewati jika yang dibuat adalah pintu)
    if (holeY > 0) {
        float centerZ = positionZ + holeZ + (holeDepth / 2.0f);
        drawBlock(positionX, positionY, centerZ, wallThickness, holeY, holeDepth, colorRed, colorGreen, colorBlue);
    }
    
    // 4. Bagian Atas / Lintel (Tembok di atas lubang pada sumbu Z)
    float topHeight = wallHeight - (holeY + holeHeight);
    if (topHeight > 0) {
        float centerZ = positionZ + holeZ + (holeDepth / 2.0f);
        float topY = positionY + holeY + holeHeight;
        drawBlock(positionX, topY, centerZ, wallThickness, topHeight, holeDepth, colorRed, colorGreen, colorBlue);
    }
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
    // Kedalaman 13.0 (Z: -5.0 sampai 8.0 -> Center = 1.5)
    drawBlock(0.75f, startY - 0.05f, 1.5f, 10.5f, 0.1f, 13.0f, 0.7f, 0.7f, 0.7f);
    
    // Sisi Kiri Dalam (Lantai interior di atas ruang utama L1)
    // Kedalaman 10.0 (Z: -5.0 sampai 5.0 -> Center = 0.0)
    drawBlock(-6.0f, startY - 0.05f, 0.0f, 3.0f, 0.1f, 10.0f, 0.7f, 0.7f, 0.7f);
    
    // Area Z=5.0 hingga Z=7.0 dibiarkan KOSONG sebagai void tangga

    // Sisi Kiri Depan (Pijakan Balkon di depan void tangga)
    // Kedalaman 1.0 (Z: 7.0 sampai 8.0 -> Center = 7.5)
    drawBlock(-6.0f, startY - 0.05f, 7.5f, 3.0f, 0.1f, 1.0f, 0.7f, 0.7f, 0.7f);

    // =========================================================
    // 2. DINDING BELAKANG, KIRI, & KANAN
    // =========================================================
    drawBlock(-0.75f, startY, -5.0f, 13.5f, wallHeight, wallThickness, wallRed, wallGreen, wallBlue);

    // Dinding Kiri (Dimajukan sampai overhang Z=8.0 -> Kedalaman 13.0, Center = 1.5)
    drawBlock(-7.5f, startY, 1.5f, wallThickness, wallHeight, 13.0f, wallRed, wallGreen, wallBlue);

    // Dinding Kanan 
    drawBlock(6.0f, startY, -0.75f, wallThickness, wallHeight, 8.5f, wallRed, wallGreen, wallBlue);

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

    // =========================================================
    // 5. ATAP LANTAI 2 / PLAFON
    // =========================================================
    drawBlock(0.75f, startY + wallHeight, 1.5f, 10.5f, 0.5f, 13.0f, 0.8f, 0.8f, 0.8f);
    drawBlock(-6.0f, startY + wallHeight, 1.5f, 3.0f, 0.5f, 13.0f, 0.8f, 0.8f, 0.8f);
    
}


void Gedung::drawLantai3() {
}

void Gedung::drawAll() {
    glPushMatrix();
    
    glScalef(buildingScale, buildingScale, buildingScale); 

   
    drawLantai1();
    drawLantai2(); 
    drawFurnitureLantai1();    
    tangga.draw(-6.0f, 0.0f, 6.0f);
    glPopMatrix();
}