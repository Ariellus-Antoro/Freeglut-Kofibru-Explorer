#include "objects/Gedung.h"
#include "objects/KursiBulat.h"
#include "objects/MejaKasir.h"
#include "objects/Tangga.h"
#include "objects/ktembok.h"
#include "objects/mejakecil.h"
#include "objects/gelas.h"
#include "objects/ac.h"
#include "objects/cctv.h"
#include "objects/kursi.h"
#include "objects/mejalt2.h"
#include "objects/mejakotak.h"
#include "objects/botolsirup.h"


#include "utils/Helper.h"
#include "objects/Wastafel.h"
#include "objects/Toilet.h"
#include "objects/MesinKopi.h"
#include "objects/TabungKopi.h"
#include "objects/Orang.h"

Orang orang;
MesinKopi mesinKopi;
TabungKopi tabungkopi;
Wastafel wastafel;
Toilet toilet;

#include <math.h>

#include "utils/loadBMP_custom.h"

Gedung::Gedung() {
    // skala bangunan
    buildingScale = 1.5f; 
}

void Gedung::init(){
    concreteTexture = loadBMP_custom("assets/textures/smooth-concrete.bmp");
    floorTexture = loadBMP_custom("assets/textures/ceramic-white.bmp");
}

void Gedung::drawLantai1() {
    float startY = 0.0f;
    float wallHeight = 3.5f; 
    float wallThickness = 0.5f; 
    float wallRed = 0.88f, wallGreen = 0.88f, wallBlue = 0.88f;

    // =========================================================
    // 0. Ubin
    // ========================================================
    drawTexturedKeramik(-7.5f, -5.0f, 6.0f, 5.0f, -0.05f, 1.2f, floorTexture);

    // =========================================================
    // 1. DINDING EKSTERIOR
    // =========================================================
    // Dinding Eksterior Kiri (Sumbu Z)
    drawBlock(-7.5f, startY, 0.0f, wallThickness, wallHeight, 10.0f, wallRed, wallGreen, wallBlue); 
    float offsetKiri = -7.5f - (wallThickness / 2.0f) - 0.001f;
    drawTexturedSurfaceZ(offsetKiri, startY, 0.0f, 10.0f, wallHeight, concreteTexture, false);

    // Dinding Eksterior Belakang (Sumbu X)
    drawBlock(-0.75f, startY, -5.0f, 13.5f, wallHeight, wallThickness, wallRed, wallGreen, wallBlue);
    float offsetBelakang = -5.0f - (wallThickness / 2.0f) - 0.001f;
    drawTexturedSurfaceX(-0.75f, startY, offsetBelakang, 13.5f, wallHeight, concreteTexture, false);

    // =========================================================
    // 2. AREA TOILET & LORONG
    // =========================================================
    // Dinding Eksterior Kanan (Sumbu Z)
    drawBlock(6.0f, startY, -2.0f, wallThickness, wallHeight, 6.0f, wallRed, wallGreen, wallBlue);
    float offsetKanan = 6.0f + (wallThickness / 2.0f) + 0.001f;
    drawTexturedSurfaceZ(offsetKanan, startY, -2.0f, 6.0f, wallHeight, concreteTexture, true);
    
    // Dinding Eksterior Depan Lorong (Sumbu X)
    drawBlock(5.0f, startY, 1.0f, 2.0f, wallHeight, wallThickness, wallRed, wallGreen, wallBlue);
    float offsetDepanLorong = 1.0f + (wallThickness / 2.0f) + 0.001f;
    drawTexturedSurfaceX(5.0f, startY, offsetDepanLorong, 2.0f, wallHeight, concreteTexture, true);
    
    // Dinding Sekat Depan Toilet (Interior)
    drawWallWithHole(2.0f, startY, -1.0f, 4.0f, wallHeight, wallThickness, 
                     0.2f, 0.0f, 1.5f, 2.5f, 
                     wallRed, wallGreen, wallBlue);

    // =========================================================
    // 3. DINDING SEKAT INTERNAL (PEMBAGI RUANGAN)
    // =========================================================
    // Dinding Sekat Vertikal
    drawWallWithHoleZ(2.0f, startY, -5.0f, 7.0f, wallHeight, wallThickness, 
                      4.5f, 0.0f, 1.5f, 2.5f, 
                      wallRed, wallGreen, wallBlue);

    // =========================================================
    // AREA FASAD DEPAN & PINTU UTAMA
    // =========================================================
    // Dinding Sudut Dalam Horizontal
    drawWallWithHole(-2.0f, startY, 2.0f, 4.0f, wallHeight, wallThickness, 
                     0.5f, 0.0f, 3.0f, 2.5f, 
                     wallRed, wallGreen, wallBlue);
    drawConcreteSurfaceWallWithHole(-2.0f, startY, 2.0f, 4.0f, wallHeight, wallThickness, 
                                    0.5f, 0.0f, 3.0f, 2.5f, 
                                    concreteTexture, true); // True = Hadap depan
    
    // Dinding Sudut Dalam Vertikal
    drawBlock(-2.0f, startY, 3.5f, wallThickness, wallHeight, 3.0f, wallRed, wallGreen, wallBlue);
    float offsetSudutVertikal = -2.0f + (wallThickness / 2.0f) + 0.001f;
    drawTexturedSurfaceZ(offsetSudutVertikal, startY, 3.5f, 3.0f, wallHeight, concreteTexture, true);

    // Dinding Fasad Pintu Masuk Paling Depan
    drawWallWithHole(-7.5f, startY, 5.0f, 5.5f, wallHeight, wallThickness, 
                     3.8f, 0.0f, 1.2f, 2.5f, 
                     wallRed, wallGreen, wallBlue);
    drawConcreteSurfaceWallWithHole(-7.5f, startY, 5.0f, 5.5f, wallHeight, wallThickness, 
                                    3.8f, 0.0f, 1.2f, 2.5f, 
                                    concreteTexture, true);
    
    // =========================================================
    // PENUTUP SUDUT
    // =========================================================
    float halfThick = wallThickness / 2.0f;
    float offsetCap = halfThick + 0.001f;

    // A. Sudut Siku Menjorok
    drawTexturedSurfaceX(-2.0f, startY, 5.0f + offsetCap, wallThickness, wallHeight, concreteTexture, true);
    drawTexturedSurfaceZ(-2.0f + 0.001f, startY, 5.0f, wallThickness, wallHeight, concreteTexture, true);

    // B. Sudut Kiri Depan
    drawTexturedSurfaceX(-7.5f, startY, 5.0f + offsetCap, wallThickness, wallHeight, concreteTexture, true); 
    drawTexturedSurfaceZ(-7.5f - offsetCap, startY, 5.0f, wallThickness, wallHeight, concreteTexture, false); 
    
    // C. Sudut Kiri Belakang
    drawTexturedSurfaceX(-7.5f, startY, -5.0f - offsetCap, wallThickness, wallHeight, concreteTexture, false); 
    drawTexturedSurfaceZ(-7.5f - offsetCap, startY, -5.0f, wallThickness, wallHeight, concreteTexture, false); 

    // D. Sudut Kanan Belakang
    drawTexturedSurfaceX(6.0f, startY, -5.0f - offsetCap, wallThickness, wallHeight, concreteTexture, false); 
    drawTexturedSurfaceZ(6.0f + offsetCap, startY, -5.0f, wallThickness, wallHeight, concreteTexture, true); 

    // E. Sudut Kanan Depan
    drawTexturedSurfaceX(6.0f, startY, 1.0f + offsetCap, wallThickness, wallHeight, concreteTexture, true); 
    drawTexturedSurfaceZ(6.0f + offsetCap, startY, 1.0f, wallThickness, wallHeight, concreteTexture, true);     

    // =========================================================
    // 5. AREA BOOTH SEATING (SISI KIRI MAIN AREA)
    // =========================================================
    float protrusion = 2.5f; // Seberapa jauh dinding menjorok ke tengah ruangan
    float boothX = -7.25f + (protrusion / 2.0f);
    
    float greyColor = 0.45f; 
    float whiteColor = 0.95f;

    // Pembatas dekat meja kasir
    float depthPartisiDepan = 0.3f;
    drawBlock(boothX, startY, 2.5f, protrusion, wallHeight, depthPartisiDepan,wallRed,wallGreen,wallBlue);

    // 2. Pilar Putih Memanjang (Diperpanjang sampai mentok dinding belakang)
    float depthPilarTengah = 5.35f;
    float zPilarTengah = -2.075f; 
    drawBlock(boothX, startY, zPilarTengah, protrusion, wallHeight, depthPilarTengah, wallRed,wallGreen,wallBlue);

    // =========================================================
    // 6. ATAP LANTAI 1 / PLAFON 
    // =========================================================
    drawBlock(-0.75f, wallHeight-0.09f, 0.0f, 13.5f, 0.5f, 10.0f, 0.8f, 0.8f, 0.8f);

    // =========================================================
    // 7. PINTU KACA (TRANSPARAN)
    // =========================================================
    float glassR = 0.82f, glassG = 0.84f, glassB = 0.86f;
    float alphaKaca = 0.35f;
    float kacaThick = 0.1f; 
    float doorHeight = 2.5f; // Sesuai dengan tinggi lubang pintu (holeH)


    // Pintu Kiri (Tertutup)
    glPushMatrix();
    glTranslatef(-1.5f, startY, 2.0f);   
    drawBlock(0.75f, 0.0f, 0.0f, 1.5f, doorHeight, kacaThick, glassR, glassG, glassB, alphaKaca);
    glPopMatrix();

    // Pintu Kanan (Buka 30 derajat ke dalam)
    glPushMatrix();
    glTranslatef(1.5f, startY, 2.0f);    // Posisikan engsel di ujung kanan lubang
    glRotatef(30.0f, 0.0f, 1.0f, 0.0f);  // Putar ke dalam ruangan
    drawBlock(-0.75f, 0.0f, 0.0f, 1.5f, doorHeight, kacaThick, glassR, glassG, glassB, alphaKaca);
    glPopMatrix();

    // ---------------------------------------------------------
    // B. PINTU KACA Fasad Paling Depan (Lebar 1.2f)
    // ---------------------------------------------------------
    // Posisi X awal = -3.1f. Kita letakkan engsel di sisi kiri (X = -3.7f)
    glPushMatrix();
    glTranslatef(-3.7f, startY, 5.0f);
    glRotatef(-30.0f, 0.0f, 1.0f, 0.0f); // Putar terbuka ke dalam 30 derajat
    drawBlock(0.6f, 0.0f, 0.0f, 1.2f, doorHeight, kacaThick, glassR, glassG, glassB, alphaKaca);
    glPopMatrix();

    // ---------------------------------------------------------
    // C. PINTU KACA Sekat Internal / Dekat Tangga (Lebar 1.5f)
    // ---------------------------------------------------------
    // Dinding di Sumbu Z. Titik Z awal = 0.25f. Engsel di belakang (Z = -0.5f)
    glPushMatrix();
    glTranslatef(2.0f, startY, -0.5f);
    glRotatef(30.0f, 0.0f, 1.0f, 0.0f);  // Putar terbuka 30 derajat
    // Karena ini sumbu Z, titik offset-nya ada di parameter ketiga (Z)
    drawBlock(0.0f, 0.0f, 0.75f, kacaThick, doorHeight, 1.5f, glassR, glassG, glassB, alphaKaca);
    glPopMatrix();

    // ---------------------------------------------------------
    // D. PINTU KACA Lorong Toilet (Lebar 1.5f)
    // ---------------------------------------------------------
    // Posisi X awal = 2.95f. Engsel di sisi kiri (X = 2.2f)
    glPushMatrix();
    glTranslatef(2.2f, startY, -1.0f);
    glRotatef(-30.0f, 0.0f, 1.0f, 0.0f); // Putar terbuka ke dalam arah toilet
    drawBlock(0.75f, 0.0f, 0.0f, 1.5f, doorHeight, kacaThick, glassR, glassG, glassB, alphaKaca);
    glPopMatrix();
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

    // sofa 1
    glPushMatrix();
    glTranslatef(-7.2f, 0.0f, 4.7f);  
    glScalef(0.01f, 0.01f, 0.02f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); // tegakkan model
    sofa.draw();
    glPopMatrix();

    // meja kecil 1
    glPushMatrix();
    glTranslatef(-6.3f, 0.0f, 4.0f);  
    glScalef(0.02f, 0.01f, 0.02f);
    mejaKecil.draw();
    glPopMatrix();

    //kursi sebelah meja 1
    glPushMatrix();

    glTranslatef(-5.9f, 0.1f, 4.3f);
    glRotatef(-120.0f, 0.0f, 1.0f, 0.0f);
    glScalef(0.1f, 0.1f, 0.1f);

    chair.draw();
    glPopMatrix();

    glPushMatrix();

    glTranslatef(-5.9f, 0.1f, 3.0f);
    glRotatef(-70.0f, 0.0f, 1.0f, 0.0f);
    glScalef(0.1f, 0.1f, 0.1f);

    chair.draw();
    glPopMatrix();

     // gelas
    glPushMatrix();
    glTranslatef(-6.0f, 0.6f, 3.5f);  // X,Z sama dengan kasir; Y sedikit di atas permukaan meja kasir
    glScalef(0.03f, 0.03f, 0.03f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); // tegakkan model
    gelas.draw();
    glPopMatrix();

    // botol sirup (sebelahan dengan gelas, di atas meja kasir yang sama)
    glPushMatrix();
    glTranslatef(-6.35f, 0.6f, 3.5f);   // digeser sedikit di X supaya sebelahan, bukan menumpuk, dengan gelas
    glScalef(0.01f, 0.01f, 0.01f);       // mesh asli satuan cm; botol lebih tinggi dari gelas
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); // tegakkan model (Z-up mesh -> Y-up)
    botolSirup.draw();
    glPopMatrix();

    //sofa 2
    glPushMatrix();
    glTranslatef(-7.2f, 0.0f, 2.5f);  
    glScalef(0.01f, 0.01f, 0.02f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); // tegakkan model
    sofa.draw();
    glPopMatrix();

    // meja kecil 2
    glPushMatrix();
    glTranslatef(-6.3f, 0.0f, 1.8f);  
    glScalef(0.02f, 0.01f, 0.02f);
    mejaKecil.draw();
    glPopMatrix();

    //kursi sebelah meja 2
    glPushMatrix();

    glTranslatef(-5.9f, 0.1f, 2.1f);
    glRotatef(-20.0f, 0.0f, 1.0f, 0.0f);
    glScalef(0.1f, 0.1f, 0.1f);

    chair.draw();
    glPopMatrix();

    glPushMatrix();

    glTranslatef(-5.9f, 0.1f, 0.8f);
    glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
    glScalef(0.1f, 0.1f, 0.1f);

    chair.draw();
    glPopMatrix();

    //ac
    glPushMatrix();
    glTranslatef(-2.0f, 3.5f, -4.4f);   // Y mendekati wallHeight (3.5f), X/Z geser sesuai dinding yang dituju
    glScalef(0.02f, 0.01f, 0.01f);
    glRotatef(-180.0f, 1.0f, 0.0f, 0.0f);
    ac.draw();
    glPopMatrix();

    // CCTV (menempel plafon, di sebelah AC)
    glPushMatrix();
    glTranslatef(1.5f, 3.4f, -4.6f);   // sama Y & Z dengan AC, X digeser supaya di sebelahnya
    glScalef(0.03f, 0.03f, 0.03f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    cctv.draw();
    glPopMatrix();
}

void Gedung::drawLantai2() {

    float stairMinX = -7.5f;
    float stairMaxX = -4.5f;

    float stairMinZ = 4.5f;
    float stairMaxZ = 8.0f;
    // Elevasi lantai 2
    float startY = 4.0f; 
    float wallHeight = 3.5f; 
    float wallThickness = 0.5f; 

    float glassR = 0.78f;
    float glassG = 0.84f;
    float glassB = 0.90f;
    float alphaKaca = 0.35f;

    float pagarHeight = 1.2f;
    float pagarThickness = 0.08f;
    
    float wallRed = 0.88f, wallGreen = 0.88f, wallBlue = 0.88f;

    // =========================================================
    // LANTAI
    // =========================================================

    float posY = startY - 0.05f;
    float tileSize = 1.2f;

    // Area utama
    drawTexturedKeramik(-4.5f, -5.0f, 6.0f, 6.0f,
                        posY, tileSize, floorTexture);

    // Balkon
    drawTexturedKeramik(-4.5f, 6.0f, 3.5f, 8.0f,
                        posY, tileSize, floorTexture);

    // Kiri belakang
    drawTexturedKeramik(-7.5f, -5.0f, -4.5f, 5.0f,
                        posY, tileSize, floorTexture);

    // Kiri depan
    drawTexturedKeramik(-7.5f, 7.0f, -4.5f, 8.0f,
                        posY, tileSize, floorTexture);

    // Koridor
    drawTexturedKeramik(-4.5f, -5.0f, -3.0f, 3.5f,
                        posY, tileSize, floorTexture);

    // Ruang kanan depan
    drawTexturedKeramik(3.0f, -3.0f, 6.0f, 3.5f,
                        posY, tileSize, floorTexture);

    // Smoking Room
    drawTexturedKeramik(3.0f, -5.0f, 6.0f, -3.0f,
                        posY, tileSize, floorTexture);

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
    
    drawGlassPanel(-2.0f, startY, 8.0f, 11.0f, pagarHeight, pagarThickness, glassR, glassG, glassB, alphaKaca);
    drawGlassPanel(3.25f, startY, 7.0f, pagarThickness, pagarHeight, 2.0f, glassR, glassG, glassB, alphaKaca);

    // 2. Kaca Jendela Dinding Kanan Luar
    // X = 6.0, Y = startY + 0.7, Center Z = -2.5, Lebar X = 0.1, Tinggi = 1.5, Panjang Z = 3.0
    drawGlassPanel(6.0f, startY + 0.7f, -2.5f, 0.1f, 1.5f, 3.0f, glassR, glassG, glassB, alphaKaca);


    drawGlassPanel(-2.0f, startY, 8.0f, 11.0f, pagarHeight, pagarThickness, glassR, glassG, glassB, alphaKaca);
    drawGlassPanel(3.25f, startY, 7.0f, pagarThickness, pagarHeight, 2.0f, glassR, glassG, glassB, alphaKaca);

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
    // Atap Bagian Kanan (Utama) - Kembali menjadi solid
    drawBlock(0.75f, startY + wallHeight, 1.5f, 10.5f, 0.5f, 13.0f, 0.8f, 0.8f, 0.8f);

    // Atap Bagian Kiri Dalam (Z = -5.0 sampai 5.0)
    drawBlock(-6.0f, startY + wallHeight, 0.0f, 3.0f, 0.5f, 10.0f, 0.8f, 0.8f, 0.8f);

    // Atap Bagian Kiri Depan (Z = 7.0 sampai 8.0)
    drawBlock(-6.0f, startY + wallHeight, 7.5f, 3.0f, 0.5f, 1.0f, 0.8f, 0.8f, 0.8f);
    
    // =========================================================
    // TEMBOK SEKAT INTERNAL
    // =========================================================

    // =========================================================
    // DUA PINTU TERPISAH 
    // =========================================================
    float tinggi = 3.5f;
    float thickness = 0.3f;
    float pHeight = 2.5f;

    drawWallWithHole(-7.5f, startY, 3.5f, 4.0f, tinggi, thickness, 1.0f, 0.0f, 1.0f, pHeight, wallRed, wallGreen, wallBlue);

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

void Gedung::drawFurnitureLantai2(){

    // =====================
    // Meja 1 
    // =====================
    glPushMatrix();
    glTranslatef(-3.5f, 3.9f, -1.3f);   // posisi Meja 1 (digeser lebih jauh dari Meja 2)
    glScalef(0.01f, 0.01f, 0.01f);      // mesh asli satuan cm
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f); // arah hadap: 90/270 utk tukar sisi panjang
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); // berdiri tegak 
    mejaLt2.draw();
    glPopMatrix();

    // Kursi 1 (Meja 1) - sisi kiri, depan - menghadap ke meja (arah +X)
    glPushMatrix();
    glTranslatef(-4.7f, 3.9f, -2.2f);
    glScalef(0.01f, 0.01f, 0.01f);
    glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    chair2.draw();
    glPopMatrix();

    // Kursi 2 (Meja 1) - sisi kiri, belakang - menghadap ke meja (arah +X)
    glPushMatrix();
    glTranslatef(-4.7f, 3.9f, -1.6f);
    glScalef(0.01f, 0.01f, 0.01f);
    glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    chair2.draw();
    glPopMatrix();

    // Kursi 3 (Meja 1) - sisi kanan, depan - menghadap ke meja (arah -X)
    glPushMatrix();
    glTranslatef(-2.9f, 3.9f, -2.6f);
    glScalef(0.01f, 0.01f, 0.01f);
    glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    chair2.draw();
    glPopMatrix();

    // Kursi 4 (Meja 1) - sisi kanan, belakang - menghadap ke meja (arah -X)
    glPushMatrix();
    glTranslatef(-2.9f, 3.9f, -2.0f);
    glScalef(0.01f, 0.01f, 0.01f);
    glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    chair2.draw();
    glPopMatrix();


    // =====================
    // Meja 2
    // =====================
    glPushMatrix();
    glTranslatef(-0.8f, 3.9f, -1.3f);   // posisi Meja 1 (digeser lebih jauh dari Meja 2)
    glScalef(0.01f, 0.01f, 0.01f);      // mesh asli satuan cm
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f); // arah hadap: 90/270 utk tukar sisi panjang
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); // berdiri tegak (Z-up mesh -> Y-up), jangan diubah
    mejaLt2.draw();
    glPopMatrix();

    // Kursi 1 (Meja 1) - sisi kiri, depan - menghadap ke meja (arah +X)
    glPushMatrix();
    glTranslatef(-2.0f, 3.9f, -2.2f);
    glScalef(0.01f, 0.01f, 0.01f);
    glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    chair2.draw();
    glPopMatrix();

    // Kursi 2 (Meja 1) - sisi kiri, belakang - menghadap ke meja (arah +X)
    glPushMatrix();
    glTranslatef(-2.0f, 3.9f, -1.6f);
    glScalef(0.01f, 0.01f, 0.01f);
    glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    chair2.draw();
    glPopMatrix();

    // Kursi 3 (Meja 1) - sisi kanan, depan - menghadap ke meja (arah -X)
    glPushMatrix();
    glTranslatef(-0.2f, 3.9f, -2.6f);
    glScalef(0.01f, 0.01f, 0.01f);
    glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    chair2.draw();
    glPopMatrix();

    // Kursi 4 (Meja 1) - sisi kanan, belakang - menghadap ke meja (arah -X)
    glPushMatrix();
    glTranslatef(-0.2f, 3.9f, -2.0f);
    glScalef(0.01f, 0.01f, 0.01f);
    glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    chair2.draw();
    glPopMatrix();

    // =====================
    // Meja 3
    // =====================
    glPushMatrix();
    glTranslatef(1.9f, 3.9f, -1.3f);   // posisi Meja 1 (digeser lebih jauh dari Meja 2)
    glScalef(0.01f, 0.01f, 0.01f);      // mesh asli satuan cm
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f); // arah hadap: 90/270 utk tukar sisi panjang
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); // berdiri tegak (Z-up mesh -> Y-up), jangan diubah
    mejaLt2.draw();
    glPopMatrix();

    // Kursi 1 (Meja 1) - sisi kiri, depan - menghadap ke meja (arah +X)
    glPushMatrix();
    glTranslatef(0.7f, 3.9f, -2.2f);
    glScalef(0.01f, 0.01f, 0.01f);
    glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    chair2.draw();
    glPopMatrix();

    // Kursi 2 (Meja 1) - sisi kiri, belakang - menghadap ke meja (arah +X)
    glPushMatrix();
    glTranslatef(0.7f, 3.9f, -1.6f);
    glScalef(0.01f, 0.01f, 0.01f);
    glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    chair2.draw();
    glPopMatrix();

    // Kursi 3 (Meja 1) - sisi kanan, depan - menghadap ke meja (arah -X)
    glPushMatrix();
    glTranslatef(2.5f, 3.9f, -2.6f);
    glScalef(0.01f, 0.01f, 0.01f);
    glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    chair2.draw();
    glPopMatrix();

    // Kursi 4 (Meja 1) - sisi kanan, belakang - menghadap ke meja (arah -X)
    glPushMatrix();
    glTranslatef(2.5f, 3.9f, -2.0f);
    glScalef(0.01f, 0.01f, 0.01f);
    glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    chair2.draw();
    glPopMatrix();

    // =====================
    // Meja 4 
    // =====================
    glPushMatrix();
    glTranslatef(-3.5f, 3.9f, 1.3f);   // posisi Meja 1 (digeser lebih jauh dari Meja 2)
    glScalef(0.01f, 0.01f, 0.01f);      // mesh asli satuan cm
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f); // arah hadap: 90/270 utk tukar sisi panjang
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); // berdiri tegak (Z-up mesh -> Y-up), jangan diubah
    mejaLt2.draw();
    glPopMatrix();

    // Kursi 1 (Meja 1) - sisi kiri, depan - menghadap ke meja (arah +X)
    glPushMatrix();
    glTranslatef(-4.7f, 3.9f, 0.5f);
    glScalef(0.01f, 0.01f, 0.01f);
    glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    chair2.draw();
    glPopMatrix();

    // Kursi 2 (Meja 1) - sisi kiri, belakang - menghadap ke meja (arah +X)
    glPushMatrix();
    glTranslatef(-4.7f, 3.9f, 1.0f);
    glScalef(0.01f, 0.01f, 0.01f);
    glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    chair2.draw();
    glPopMatrix();

    // Kursi 3 (Meja 1) - sisi kanan, depan - menghadap ke meja (arah -X)
    glPushMatrix();
    glTranslatef(-2.9f, 3.9f, 0.6f);
    glScalef(0.01f, 0.01f, 0.01f);
    glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    chair2.draw();
    glPopMatrix();

    // Kursi 4 (Meja 1) - sisi kanan, belakang - menghadap ke meja (arah -X)
    glPushMatrix();
    glTranslatef(-2.9f, 3.9f, 0.0f);
    glScalef(0.01f, 0.01f, 0.01f);
    glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    chair2.draw();
    glPopMatrix();

    // =====================
    // Meja Ruang Rokok
    // =====================
    glPushMatrix();
    glTranslatef(5.9f, 3.9f, 2.3f);   // posisi Meja 1 (digeser lebih jauh dari Meja 2)
    glScalef(0.01f, 0.01f, 0.05f);      // mesh asli satuan cm
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f); // arah hadap: 90/270 utk tukar sisi panjang
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); // berdiri tegak (Z-up mesh -> Y-up), jangan diubah
    mejaLt2.draw();
    glPopMatrix();

    // Kursi 1 (Meja ruang rokok) - sisi kiri, depan - menghadap ke meja (arah +X)
    glPushMatrix();
    glTranslatef(4.7f, 3.9f, -2.8f);
    glScalef(0.01f, 0.01f, 0.01f);
    glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    chair2.draw();
    glPopMatrix();

    // Kursi 2 (Meja ruang rokok) - sisi kiri, depan - menghadap ke meja (arah +X)
    glPushMatrix();
    glTranslatef(4.7f, 3.9f, -2.2f);
    glScalef(0.01f, 0.01f, 0.01f);
    glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    chair2.draw();
    glPopMatrix();

    // Kursi 3 (Meja ruang rokok) - sisi kiri, belakang - menghadap ke meja (arah +X)
    glPushMatrix();
    glTranslatef(4.7f, 3.9f, -1.6f);
    glScalef(0.01f, 0.01f, 0.01f);
    glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    chair2.draw();
    glPopMatrix();

    //ac
    glPushMatrix();
    glTranslatef(-2.0f, 7.5f, -2.52f);   // Y mendekati wallHeight (3.5f), X/Z geser sesuai dinding yang dituju
    glScalef(0.02f, 0.01f, 0.01f);
    glRotatef(-180.0f, 1.0f, 0.0f, 0.0f);
    ac.draw();
    glPopMatrix();

    // CCTV (menempel plafon, di sebelah AC)
    glPushMatrix();
    glTranslatef(1.5f, 7.4f, -2.52f);   // sama Y & Z dengan AC, X digeser supaya di sebelahnya
    glScalef(0.03f, 0.03f, 0.03f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    cctv.draw();
    glPopMatrix();
    
    // Kursi luar 1
    glPushMatrix();
    glTranslatef(1.5f, 4.12f, 7.0f);
    glRotatef(-40.0f, 0.0f, 1.0f, 0.0f);
    glScalef(0.1f, 0.1f, 0.1f);
    chair.draw();
    glPopMatrix();

    // Kursi luar 2
    glPushMatrix();
    glTranslatef(0.5f, 4.12f, 7.0f);
    glRotatef(-40.0f, 0.0f, 1.0f, 0.0f);
    glScalef(0.1f, 0.1f, 0.1f);
    chair.draw();
    glPopMatrix();

    // Kursi luar 3
    glPushMatrix();
    glTranslatef(0.5f, 4.12f, 5.5f);
    glRotatef(-40.0f, 0.0f, 1.0f, 0.0f);
    glScalef(0.1f, 0.1f, 0.1f);
    chair.draw();
    glPopMatrix();

    // meja kecil luar
    glPushMatrix();
    glTranslatef(0.5f, 3.9f, 6.5f);  
    glScalef(0.02f, 0.01f, 0.02f);
    mejaKecil.draw();
    glPopMatrix();
}


void Gedung::drawLantai3() {
    float startY = 8.0f; 
    
    float wallHeight = 3.5f;    
    float fasadHeight = 5.8f;   
    float wallThickness = 0.5f;
    
    float wallRed = 0.88f, wallGreen = 0.88f, wallBlue = 0.88f;
    float glassR = 0.82f, glassG = 0.84, glassB=0.86f;

    // =========================================================
    // LANTAI BERTEKSTUR
    // =========================================================
    float posY = startY + 0.002f;
    float tileSize = 1.2f;

    // 1. INDOOR (Lantai tengah yang sebelumnya tidak sengaja terhapus)
    drawTexturedKeramik(-4.5f, -4.0f, 3.5f,  2.0f, posY, tileSize, floorTexture);

    // 2. Balkon depan
    drawTexturedKeramik(-4.5f, 2.0f, 3.5f, 8.0f, posY, tileSize, floorTexture);

    // 3. SISI KIRI (Di sinilah lokasi tangga sebenarnya berada!)
    // Kita lubangi area X: -7.5 s/d -4.5, dan Z: 5.0 s/d 7.0
    drawTexturedKeramikWithHole(-7.5f, -5.0f, -4.5f, 8.0f, posY, tileSize, floorTexture, 
                                -7.5f, 5.0f, -4.5f, 7.0f);

    // 4. Sisi kanan
    drawTexturedKeramik(3.5f, -5.0f, 6.0f, 6.0f, posY, tileSize, floorTexture);

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

    // Dinding Depan Indoor 
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

    glDisable(GL_BLEND);
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

void Gedung::drawFurnitureLantai3(){
    // =====================
    // Meja 1.1
    // =====================
    glPushMatrix();
    glTranslatef(-2.8f, 8.0f, -1.3f);   // posisi Meja 1 (digeser lebih jauh dari Meja 2)
    glScalef(0.01f, 0.01f, 0.01f);      // mesh asli satuan cm
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f); // arah hadap: 90/270 utk tukar sisi panjang
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); // berdiri tegak (Z-up mesh -> Y-up), jangan diubah
    mejaLt2.draw();
    glPopMatrix();

    // Kursi 1 (Meja 1) - sisi kiri, depan - menghadap ke meja (arah +X)
    glPushMatrix();
    glTranslatef(-4.0f, 8.0f, -2.2f);
    glScalef(0.01f, 0.01f, 0.01f);
    glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    chair2.draw();
    glPopMatrix();

    // Kursi 2 (Meja 1) - sisi kiri, belakang - menghadap ke meja (arah +X)
    glPushMatrix();
    glTranslatef(-4.0f, 8.0f, -1.6f);
    glScalef(0.01f, 0.01f, 0.01f);
    glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    chair2.draw();
    glPopMatrix();

    // Kursi 3 (Meja 1) - sisi kanan, depan - menghadap ke meja (arah -X)
    glPushMatrix();
    glTranslatef(-2.2f, 8.0f, -2.6f);
    glScalef(0.01f, 0.01f, 0.01f);
    glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    chair2.draw();
    glPopMatrix();

    // Kursi 4 (Meja 1) - sisi kanan, belakang - menghadap ke meja (arah -X)
    glPushMatrix();
    glTranslatef(-2.2f, 8.0f, -2.0f);
    glScalef(0.01f, 0.01f, 0.01f);
    glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    chair2.draw();
    glPopMatrix();

    // =====================
    // Meja 1.2
    // =====================
    glPushMatrix();
    glTranslatef(-2.8f, 8.0f, 1.3f);   // posisi Meja 1 (digeser lebih jauh dari Meja 2)
    glScalef(0.01f, 0.01f, 0.01f);      // mesh asli satuan cm
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f); // arah hadap: 90/270 utk tukar sisi panjang
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); // berdiri tegak (Z-up mesh -> Y-up), jangan diubah
    mejaLt2.draw();
    glPopMatrix();

    // Kursi 1 (Meja 1) - sisi kiri, depan - menghadap ke meja (arah +X)
    glPushMatrix();
    glTranslatef(-4.0f, 8.0f, 0.4f);
    glScalef(0.01f, 0.01f, 0.01f);
    glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    chair2.draw();
    glPopMatrix();

    // Kursi 2 (Meja 1) - sisi kiri, belakang - menghadap ke meja (arah +X)
    glPushMatrix();
    glTranslatef(-4.0f, 8.0f, 1.0f);
    glScalef(0.01f, 0.01f, 0.01f);
    glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    chair2.draw();
    glPopMatrix();

    // Kursi 3 (Meja 1) - sisi kanan, depan - menghadap ke meja (arah -X)
    glPushMatrix();
    glTranslatef(-2.2f, 8.0f, 0.0f);
    glScalef(0.01f, 0.01f, 0.01f);
    glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    chair2.draw();
    glPopMatrix();

    // Kursi 4 (Meja 1) - sisi kanan, belakang - menghadap ke meja (arah -X)
    glPushMatrix();
    glTranslatef(-2.2f, 8.0f, 0.6f);
    glScalef(0.01f, 0.01f, 0.01f);
    glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    chair2.draw();
    glPopMatrix();

    // ======================================

    // =====================
    // Meja 2.1
    // =====================
    glPushMatrix();
    glTranslatef(2.4f, 8.0f, -1.3f);   // posisi Meja 1 (digeser lebih jauh dari Meja 2)
    glScalef(0.01f, 0.01f, 0.01f);      // mesh asli satuan cm
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f); // arah hadap: 90/270 utk tukar sisi panjang
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); // berdiri tegak (Z-up mesh -> Y-up), jangan diubah
    mejaLt2.draw();
    glPopMatrix();

    // Kursi 1 (Meja 1) - sisi kiri, depan - menghadap ke meja (arah +X)
    glPushMatrix();
    glTranslatef(1.0f, 8.0f, -2.2f);
    glScalef(0.01f, 0.01f, 0.01f);
    glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    chair2.draw();
    glPopMatrix();

    // Kursi 2 (Meja 1) - sisi kiri, belakang - menghadap ke meja (arah +X)
    glPushMatrix();
    glTranslatef(1.0f, 8.0f, -1.6f);
    glScalef(0.01f, 0.01f, 0.01f);
    glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    chair2.draw();
    glPopMatrix();

    // Kursi 3 (Meja 1) - sisi kanan, depan - menghadap ke meja (arah -X)
    glPushMatrix();
    glTranslatef(3.2f, 8.0f, -2.6f);
    glScalef(0.01f, 0.01f, 0.01f);
    glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    chair2.draw();
    glPopMatrix();

    // Kursi 4 (Meja 1) - sisi kanan, belakang - menghadap ke meja (arah -X)
    glPushMatrix();
    glTranslatef(3.2f, 8.0f, -2.0f);
    glScalef(0.01f, 0.01f, 0.01f);
    glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    chair2.draw();
    glPopMatrix();

    // =====================
    // Meja 2.2
    // =====================
    glPushMatrix();
    glTranslatef(2.4f, 8.0f, 1.3f);   // posisi Meja 1 (digeser lebih jauh dari Meja 2)
    glScalef(0.01f, 0.01f, 0.01f);      // mesh asli satuan cm
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f); // arah hadap: 90/270 utk tukar sisi panjang
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); // berdiri tegak (Z-up mesh -> Y-up), jangan diubah
    mejaLt2.draw();
    glPopMatrix();

    // Kursi 1 (Meja 1) - sisi kiri, depan - menghadap ke meja (arah +X)
    glPushMatrix();
    glTranslatef(1.0f, 8.0f, 0.4f);
    glScalef(0.01f, 0.01f, 0.01f);
    glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    chair2.draw();
    glPopMatrix();

    // Kursi 2 (Meja 1) - sisi kiri, belakang - menghadap ke meja (arah +X)
    glPushMatrix();
    glTranslatef(1.0f, 8.0f, 1.0f);
    glScalef(0.01f, 0.01f, 0.01f);
    glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    chair2.draw();
    glPopMatrix();

    // Kursi 3 (Meja 1) - sisi kanan, depan - menghadap ke meja (arah -X)
    glPushMatrix();
    glTranslatef(3.2f, 8.0f, 0.0f);
    glScalef(0.01f, 0.01f, 0.01f);
    glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    chair2.draw();
    glPopMatrix();

    // Kursi 4 (Meja 1) - sisi kanan, belakang - menghadap ke meja (arah -X)
    glPushMatrix();
    glTranslatef(3.2f, 8.0f, 0.6f);
    glScalef(0.01f, 0.01f, 0.01f);
    glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    chair2.draw();
    glPopMatrix();

    // =====================================================
    // Meja Kotak 1
    // =====================================================
    glPushMatrix();
    glTranslatef(-2.8f, 8.0f, 4.0f);      // posisi di area balkon outdoor
    glScalef(0.01f, 0.01f, 0.01f);       // mesh asli satuan cm
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);  // arah hadap meja
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); // berdiri tegak (Z-up mesh -> Y-up), jangan diubah
    mejaKotak.draw();
    glPopMatrix();

    // Kursi 2 (Meja 1) - sisi kiri, belakang - menghadap ke meja (arah +X)
    glPushMatrix();
    glTranslatef(-4.0f, 8.0f, 3.0f);
    glScalef(0.01f, 0.01f, 0.01f);
    glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    chair2.draw();
    glPopMatrix();

    // Kursi 4 (Meja 1) - sisi kanan, belakang - menghadap ke meja (arah -X)
    glPushMatrix();
    glTranslatef(-2.2f, 8.0f, 2.6f);
    glScalef(0.01f, 0.01f, 0.01f);
    glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    chair2.draw();
    glPopMatrix();

    // =====================================================
    // Meja Kotak 2
    // =====================================================
    glPushMatrix();
    glTranslatef(2.4f, 8.0f, 4.0f);      // posisi di area balkon outdoor
    glScalef(0.01f, 0.01f, 0.01f);       // mesh asli satuan cm
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);  // arah hadap meja
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); // berdiri tegak (Z-up mesh -> Y-up), jangan diubah
    mejaKotak.draw();
    glPopMatrix();

    // Kursi 2 (Meja 1) - sisi kiri, belakang - menghadap ke meja (arah +X)
    glPushMatrix();
    glTranslatef(1.0f, 8.0f, 3.0f);
    glScalef(0.01f, 0.01f, 0.01f);
    glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    chair2.draw();
    glPopMatrix();

    // Kursi 4 (Meja 1) - sisi kanan, belakang - menghadap ke meja (arah -X)
    glPushMatrix();
    glTranslatef(3.2f, 8.0f, 2.6f);
    glScalef(0.01f, 0.01f, 0.01f);
    glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    chair2.draw();
    glPopMatrix();

    // =============================
    // meja kecil luar 1
    glPushMatrix();
    glTranslatef(1.5f, 8.0f, 6.5f);  
    glScalef(0.02f, 0.01f, 0.02f);
    mejaKecil.draw();
    glPopMatrix();

    // Kursi luar 1
    glPushMatrix();
    glTranslatef(2.5f, 8.0f, 7.0f);
    glRotatef(-40.0f, 0.0f, 1.0f, 0.0f);
    glScalef(0.1f, 0.1f, 0.1f);
    chair.draw();
    glPopMatrix();

    // Kursi luar 2
    glPushMatrix();
    glTranslatef(1.5f, 8.0f, 7.0f);
    glRotatef(-40.0f, 0.0f, 1.0f, 0.0f);
    glScalef(0.1f, 0.1f, 0.1f);
    chair.draw();
    glPopMatrix();

    // Kursi luar 3
    glPushMatrix();
    glTranslatef(1.5f, 8.0f, 5.5f);
    glRotatef(-40.0f, 0.0f, 1.0f, 0.0f);
    glScalef(0.1f, 0.1f, 0.1f);
    chair.draw();
    glPopMatrix();

    // =============================
    // meja kecil luar 2
    glPushMatrix();
    glTranslatef(-1.5f, 8.0f, 6.5f);  
    glScalef(0.02f, 0.01f, 0.02f);
    mejaKecil.draw();
    glPopMatrix();

    // Kursi luar 1
    glPushMatrix();
    glTranslatef(-0.5f, 8.0f, 7.0f);
    glRotatef(-40.0f, 0.0f, 1.0f, 0.0f);
    glScalef(0.1f, 0.1f, 0.1f);
    chair.draw();
    glPopMatrix();

    // Kursi luar 2
    glPushMatrix();
    glTranslatef(-1.5f, 8.0f, 7.0f);
    glRotatef(-40.0f, 0.0f, 1.0f, 0.0f);
    glScalef(0.1f, 0.1f, 0.1f);
    chair.draw();
    glPopMatrix();

    // Kursi luar 3
    glPushMatrix();
    glTranslatef(-1.5f, 8.0f, 5.5f);
    glRotatef(-40.0f, 0.0f, 1.0f, 0.0f);
    glScalef(0.1f, 0.1f, 0.1f);
    chair.draw();
    glPopMatrix();
}
void Gedung::drawAll() {
    glPushMatrix();
    
    glScalef(buildingScale, buildingScale, buildingScale); 

   
    drawLantai1();
    drawLantai2(); 
    drawLantai3();
    drawFurnitureLantai1();    
    drawFurnitureLantai2();    
    drawFurnitureLantai3();    
    tangga.draw(-6.0f, 0.0f, 6.0f);
    tangga.draw(-6.0f, 4.0f, 6.0f);
    wastafel.drawAll();
    toilet.drawAll();
    mesinKopi.drawAll();
    tabungkopi.drawAll();
    orang.drawAll();
    glPopMatrix();
}