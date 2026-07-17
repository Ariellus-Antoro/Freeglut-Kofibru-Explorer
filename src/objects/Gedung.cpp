#include "objects/Gedung.h"
#include "objects/KursiBulat.h"

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

void Gedung::drawLantai1() {
    float startY = 0.0f;
    float wallHeight = 3.5f; 
    float wallThickness = 0.5f; 
    float wallRed = 0.75f, wallGreen = 0.75f, wallBlue = 0.75f; // Warna dinding abu-abu standar

    // Alas / Pijakan Lantai 1 (Lebar diperluas untuk menutupi seluruh area bangunan)
    drawBlock(-0.75f, -0.1f, 0.0f, 13.5f, 0.1f, 10.0f, 0.5f, 0.5f, 0.5f);

    // =========================================================
    // 1. DINDING EKSTERIOR (BATAS LUAR BANGUNAN)
    // =========================================================
    // Dinding Eksterior Kiri (Sisi dalam berada di X = -7.25f)
    drawBlock(-7.5f, startY, 0.0f, wallThickness, wallHeight, 10.0f, wallRed, wallGreen, wallBlue); 
    
    // Dinding Eksterior Belakang
    drawBlock(-0.75f, startY, -5.0f, 13.5f, wallHeight, wallThickness, wallRed, wallGreen, wallBlue);
    
    // =========================================================
    // 2. AREA TOILET & LORONG (SUDUT KANAN ATAS)
    // =========================================================
    drawBlock(6.0f, startY, -2.0f, wallThickness, wallHeight, 6.0f, wallRed, wallGreen, wallBlue); 
    drawBlock(5.0f, startY, 1.0f, 2.0f, wallHeight, wallThickness, wallRed, wallGreen, wallBlue);
    drawWallWithHole(2.0f, startY, -1.0f, 4.0f, wallHeight, wallThickness, 
                     0.2f, 0.0f, 1.5f, 2.5f, 
                     wallRed, wallGreen, wallBlue);

    // =========================================================
    // 3. DINDING SEKAT INTERNAL (PEMBAGI RUANGAN)
    // =========================================================
    drawWallWithHoleZ(2.0f, startY, -5.0f, 7.0f, wallHeight, wallThickness, 
                      4.5f, 0.0f, 1.5f, 2.5f, 
                      wallRed, wallGreen, wallBlue);

    // =========================================================
    // 4. AREA FASAD DEPAN & PINTU UTAMA
    // =========================================================
    drawWallWithHole(-2.0f, startY, 2.0f, 4.0f, wallHeight, wallThickness, 
                     0.5f, 0.0f, 3.0f, 2.5f, 
                     wallRed, wallGreen, wallBlue);
    
    drawBlock(-2.0f, startY, 3.5f, wallThickness, wallHeight, 3.0f, wallRed, wallGreen, wallBlue);

    // Pintu Utama berada di Z = 5.0f
    drawWallWithHole(-7.5f, startY, 5.0f, 5.5f, wallHeight, wallThickness, 
                     3.8f, 0.0f, 1.2f, 2.5f, 
                     wallRed, wallGreen, wallBlue);

    // =========================================================
    // 5. PILAR DALAM (RUANG UTAMA)
    // =========================================================
    float pillarDepth = 1.0f; // Ukuran tebal pilar
    
    // PILAR 1: Paling dekat dengan pintu depan (Z = 4.0f)
    // Menjorok ke dalam ruangan sebesar 1.0f
    // Posisi X = Batas dinding (-7.25f) + Setengah dari lebar (0.5f) = -6.75f
    float pilar1Width = 1.0f;
    drawBlock(-6.75f, startY, 4.0f, pilar1Width, wallHeight, pillarDepth, wallRed, wallGreen, wallBlue);
    
    // PILAR 2: Berada di tengah (Z = 0.0f)
    // Menjorok lebih jauh ke dalam ruangan sebesar 2.5f
    // Posisi X = Batas dinding (-7.25f) + Setengah dari lebar (1.25f) = -6.0f
    float pilar23Width = 2.5f;
    drawBlock(-6.0f, startY, 0.0f, pilar23Width, wallHeight, pillarDepth, wallRed, wallGreen, wallBlue);
    
    // PILAR 3: Paling jauh dari pintu depan / Area belakang (Z = -4.0f)
    // Ukuran dan panjang tonjolan disamakan dengan Pilar 2
    drawBlock(-6.0f, startY, -4.0f, pilar23Width, wallHeight, pillarDepth, wallRed, wallGreen, wallBlue);

    // =========================================================
    // 6. ATAP LANTAI 1 / PLAFON
    // =========================================================
    drawBlock(-0.75f, wallHeight, 0.0f, 13.5f, 0.5f, 10.0f, 0.8f, 0.8f, 0.8f);
}

void Gedung::drawFurnitureLantai1(){
    // Kursi 1
    glPushMatrix();

    glTranslatef(-3.0f, 0.2f, 2.0f);  // Posisi
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f); // Rotasi
    glScalef(0.1f, 0.1f, 0.1f);         // Ukuran 50%

    chair.draw();

    glPopMatrix();

    // Kursi 2
    glPushMatrix();

   glTranslatef(-3.0f, 0.2f, 2.0f);
    glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
    glScalef(0.1f, 0.1f, 0.1f);

    chair.draw();

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
    // 1. LANTAI / PIJAKAN LANTAI 2 (Menopang Overhang)
    // =========================================================
    drawBlock(-0.75f, startY - 0.05f, 0.5f, 13.5f, 0.1f, 11.0f, 0.7f, 0.7f, 0.7f);

    // =========================================================
    // 2. DINDING BELAKANG, KIRI, & KANAN
    // =========================================================
    // Dinding Belakang
    drawBlock(-0.75f, startY, -5.0f, 13.5f, wallHeight, wallThickness, wallRed, wallGreen, wallBlue);

    // Dinding Kiri 
    drawBlock(-7.5f, startY, 0.5f, wallThickness, wallHeight, 11.0f, wallRed, wallGreen, wallBlue);

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
    drawWallWithHole(-7.5f, startY, 6.0f, 11.0f, wallHeight, wallThickness,
                     1.0f, 0.5f, 6.0f, 2.5f, // Lubang jendela selebar 6.0
                     wallRed, wallGreen, wallBlue);
                     
    drawBlock(-3.5f, startY + 0.5f, 6.0f, 0.5f, 2.5f, wallThickness, wallRed, wallGreen, wallBlue);

    // =========================================================
    // 5. ATAP LANTAI 2 / PLAFON
    // =========================================================
    drawBlock(-0.75f, startY + wallHeight, 0.5f, 13.5f, 0.5f, 11.0f, 0.8f, 0.8f, 0.8f);
}


void Gedung::drawLantai3() {
}

void Gedung::drawAll() {
    glPushMatrix();
    
    glScalef(buildingScale, buildingScale, buildingScale); 
    
    drawLantai1();
    drawLantai2(); 
    drawFurnitureLantai1();    
    glPopMatrix();
}