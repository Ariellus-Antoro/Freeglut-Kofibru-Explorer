#include "utils/Helper.h"
#include <GL/freeglut.h>

    void drawBlock(float posX, float posY, float posZ, float w, float h, float d, float r, float g, float b, float alpha) {
        if (alpha < 1.0f) {
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glDepthMask(GL_FALSE); 
        }
        glPushMatrix();
        glColor4f(r, g, b, alpha);
        glTranslatef(posX, posY + (h / 2.0f), posZ); // Pivot di tengah bawah
        glScalef(w, h, d);
        glutSolidCube(1.0);
        glPopMatrix();

        if (alpha < 1.0f) {
            glDisable(GL_BLEND);
            glDepthMask(GL_TRUE);
        }
    }

    void drawCylinder(float posX, float posY, float posZ, float radius, float h, float r, float g, float b) {
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

    void drawWallWithHole(float posX, float posY, float posZ, 
                                float wallW, float wallH, float thickness, 
                                float holeX, float holeY, float holeW, float holeH, 
                                float r, float g, float b, float alpha) {
        
        // 1. Bagian Kiri (Tembok dari ujung kiri sampai batas mulai lubang)
        if (holeX > 0) {
            float leftWidth = holeX;
            float centerLeftX = posX + (leftWidth / 2.0f);
            drawBlock(centerLeftX, posY, posZ, leftWidth, wallH, thickness, r, g, b,alpha);
        }
        
        // 2. Bagian Kanan (Tembok dari batas akhir lubang sampai ujung kanan)
        float rightWidth = wallW - (holeX + holeW);
        if (rightWidth > 0) {
            float centerRightX = posX + holeX + holeW + (rightWidth / 2.0f);
            drawBlock(centerRightX, posY, posZ, rightWidth, wallH, thickness, r, g, b, alpha);
        }
        
        // 3. Bagian Bawah (Tembok penahan di bawah jendela/lubang, dilewati jika ini adalah pintu)
        if (holeY > 0) {
            float centerHoleX = posX + holeX + (holeW / 2.0f);
            drawBlock(centerHoleX, posY, posZ, holeW, holeY, thickness, r, g, b,alpha);
        }
        
        // 4. Bagian Atas / Lintel (Tembok penghubung di atas pintu/jendela)
        float topHeight = wallH - (holeY + holeH);
        if (topHeight > 0) {
            float centerHoleX = posX + holeX + (holeW / 2.0f);
            float topY = posY + holeY + holeH;
            drawBlock(centerHoleX, topY, posZ, holeW, topHeight, thickness, r, g, b, alpha);
        }
    }

    void drawWallWithHoleZ(float positionX, float positionY, float positionZ, 
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
    
    void drawWindow(float posX, float posY, float posZ, float w, float h, float d) {
        // 1. Pengaturan Warna
        // Warna Kusen (Misalnya: Abu-abu tua/Aluminium)
        float frameR = 0.3f, frameG = 0.3f, frameB = 0.3f;
        // Warna Kaca (Misalnya: Biru gelap keabu-abuan / Kaca Film)
        float glassR = 0.15f, glassG = 0.2f, glassB = 0.25f;

        float frameThick = 0.15f;  // Lebar batangan kusen
        float glassDepth = 0.05f;  // Ketebalan kaca (sangat tipis)

        // 2. Gambar Bingkai Bawah & Atas
        drawBlock(posX, posY, posZ, w, frameThick, d, frameR, frameG, frameB); // Bawah
        drawBlock(posX, posY + h - frameThick, posZ, w, frameThick, d, frameR, frameG, frameB); // Atas

        // 3. Gambar Bingkai Kiri & Kanan
        drawBlock(posX - (w / 2.0f) + (frameThick / 2.0f), posY, posZ, frameThick, h, d, frameR, frameG, frameB); // Kiri
        drawBlock(posX + (w / 2.0f) - (frameThick / 2.0f), posY, posZ, frameThick, h, d, frameR, frameG, frameB); // Kanan

        // 4. Gambar Kaca di Tengah
        // Kaca diletakkan pas di dalam bingkai, lebarnya dikurangi ketebalan bingkai kiri-kanan
        drawBlock(posX, posY + frameThick, posZ, 
                w - (frameThick * 2.0f), h - (frameThick * 2.0f), glassDepth, 
                glassR, glassG, glassB);
    }