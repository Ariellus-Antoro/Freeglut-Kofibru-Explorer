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


    void drawTexturedBlock(float x, float y, float z, float width, float height, float depth, GLuint textureID) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textureID);

        glColor3f(1.0f, 1.0f, 1.0f); 

        // Kalkulasi pengulangan tekstur agar tidak melar/stretched
        // Angka 2.0f adalah skala pembagi, bisa dibesarkan/dikecilkan agar tekstur semen terlihat pas
        float repX = width / 2.0f; 
        float repY = height / 2.0f;
        float repZ = depth / 2.0f;

        glBegin(GL_QUADS);

            // 1. SISI DEPAN (Menghadap sumbu Z positif)
            glNormal3f(0.0f, 0.0f, 1.0f); 
            // Perhatikan Y sekarang dimulai dari 'y' hingga 'y + height'
            glTexCoord2f(0.0f, 0.0f); glVertex3f(x - width/2, y, z + depth/2);
            glTexCoord2f(repX, 0.0f); glVertex3f(x + width/2, y, z + depth/2);
            glTexCoord2f(repX, repY); glVertex3f(x + width/2, y + height, z + depth/2);
            glTexCoord2f(0.0f, repY); glVertex3f(x - width/2, y + height, z + depth/2);

            // 2. SISI BELAKANG (Menghadap sumbu Z negatif)
            glNormal3f(0.0f, 0.0f, -1.0f);
            glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width/2, y, z - depth/2);
            glTexCoord2f(repX, 0.0f); glVertex3f(x - width/2, y, z - depth/2);
            glTexCoord2f(repX, repY); glVertex3f(x - width/2, y + height, z - depth/2);
            glTexCoord2f(0.0f, repY); glVertex3f(x + width/2, y + height, z - depth/2);

            // 3. SISI KIRI (Menghadap sumbu X negatif)
            glNormal3f(-1.0f, 0.0f, 0.0f);
            glTexCoord2f(0.0f, 0.0f); glVertex3f(x - width/2, y, z - depth/2);
            glTexCoord2f(repZ, 0.0f); glVertex3f(x - width/2, y, z + depth/2);
            glTexCoord2f(repZ, repY); glVertex3f(x - width/2, y + height, z + depth/2);
            glTexCoord2f(0.0f, repY); glVertex3f(x - width/2, y + height, z - depth/2);

            // 4. SISI KANAN (Menghadap sumbu X positif)
            glNormal3f(1.0f, 0.0f, 0.0f);
            glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width/2, y, z + depth/2);
            glTexCoord2f(repZ, 0.0f); glVertex3f(x + width/2, y, z - depth/2);
            glTexCoord2f(repZ, repY); glVertex3f(x + width/2, y + height, z - depth/2);
            glTexCoord2f(0.0f, repY); glVertex3f(x + width/2, y + height, z + depth/2);

            // 5. SISI ATAS (Menghadap sumbu Y positif)
            glNormal3f(0.0f, 1.0f, 0.0f);
            glTexCoord2f(0.0f, 0.0f); glVertex3f(x - width/2, y + height, z + depth/2);
            glTexCoord2f(repX, 0.0f); glVertex3f(x + width/2, y + height, z + depth/2);
            glTexCoord2f(repX, repZ); glVertex3f(x + width/2, y + height, z - depth/2);
            glTexCoord2f(0.0f, repZ); glVertex3f(x - width/2, y + height, z - depth/2);

            // 6. SISI BAWAH (Menghadap sumbu Y negatif)
            glNormal3f(0.0f, -1.0f, 0.0f);
            glTexCoord2f(0.0f, 0.0f); glVertex3f(x - width/2, y, z - depth/2);
            glTexCoord2f(repX, 0.0f); glVertex3f(x + width/2, y, z - depth/2);
            glTexCoord2f(repX, repZ); glVertex3f(x + width/2, y, z + depth/2);
            glTexCoord2f(0.0f, repZ); glVertex3f(x - width/2, y, z + depth/2);

        glEnd();

        glDisable(GL_TEXTURE_2D); 
    }

    void drawConcreteWallWithHole(float posX, float posY, float posZ, 
                                float wallW, float wallH, float thickness, 
                                float holeX, float holeY, float holeW, float holeH, 
                                GLuint textureID) {
        
        // 1. Bagian Kiri (Tembok dari ujung kiri sampai batas mulai lubang)
        if (holeX > 0) {
            float leftWidth = holeX;
            float centerLeftX = posX + (leftWidth / 2.0f);
            drawTexturedBlock(centerLeftX, posY, posZ, leftWidth, wallH, thickness, textureID);
        }
        
        // 2. Bagian Kanan (Tembok dari batas akhir lubang sampai ujung kanan)
        float rightWidth = wallW - (holeX + holeW);
        if (rightWidth > 0) {
            float centerRightX = posX + holeX + holeW + (rightWidth / 2.0f);
            drawTexturedBlock(centerRightX, posY, posZ, rightWidth, wallH, thickness, textureID);
        }
        
        // 3. Bagian Bawah (Tembok penahan di bawah jendela/lubang, dilewati jika ini adalah pintu)
        if (holeY > 0) {
            float centerHoleX = posX + holeX + (holeW / 2.0f);
            drawTexturedBlock(centerHoleX, posY, posZ, holeW, holeY, thickness, textureID);
        }
        
        // 4. Bagian Atas / Lintel (Tembok penghubung di atas pintu/jendela)
        float topHeight = wallH - (holeY + holeH);
        if (topHeight > 0) {
            float centerHoleX = posX + holeX + (holeW / 2.0f);
            float topY = posY + holeY + holeH;
            drawTexturedBlock(centerHoleX, topY, posZ, holeW, topHeight, thickness, textureID);
        }
    }

    void drawConcreteWallWithHoleZ(float positionX, float positionY, float positionZ, 
                               float wallDepth, float wallHeight, float wallThickness, 
                               float holeZ, float holeY, float holeDepth, float holeHeight, 
                               GLuint textureID) {
    
        // 1. Bagian Belakang (Tembok pada sumbu Z sebelum lubang)
        if (holeZ > 0) {
            float backDepth = holeZ;
            float centerZ = positionZ + (backDepth / 2.0f);
            drawTexturedBlock(positionX, positionY, centerZ, wallThickness, wallHeight, backDepth, textureID);
        }
        
        // 2. Bagian Depan (Tembok pada sumbu Z setelah lubang)
        float frontDepth = wallDepth - (holeZ + holeDepth);
        if (frontDepth > 0) {
            float centerZ = positionZ + holeZ + holeDepth + (frontDepth / 2.0f);
            drawTexturedBlock(positionX, positionY, centerZ, wallThickness, wallHeight, frontDepth, textureID);
        }
        
        // 3. Bagian Bawah (Dilewati jika yang dibuat adalah pintu)
        if (holeY > 0) {
            float centerZ = positionZ + holeZ + (holeDepth / 2.0f);
            drawTexturedBlock(positionX, positionY, centerZ, wallThickness, holeY, holeDepth, textureID);
        }
        
        // 4. Bagian Atas / Lintel (Tembok di atas lubang pada sumbu Z)
        float topHeight = wallHeight - (holeY + holeHeight);
        if (topHeight > 0) {
            float centerZ = positionZ + holeZ + (holeDepth / 2.0f);
            float topY = positionY + holeY + holeHeight;
            drawTexturedBlock(positionX, topY, centerZ, wallThickness, topHeight, holeDepth, textureID);
        }
    }

    void drawTexturedKeramik(float startX, float startZ, float endX, float endZ, float posY, float tileSize, GLuint textureID) {
        float width = endX - startX;
        float depth = endZ - startZ;
        float repX = width / tileSize;
        float repZ = depth / tileSize;

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textureID);
        
        glColor3f(1.0f, 1.0f, 1.0f); 

        glPushMatrix();
        glTranslatef(0.0f, posY, 0.0f); 

        glBegin(GL_QUADS);
            glNormal3f(0.0f, 1.0f, 0.0f); 
            glTexCoord2f(0.0f, 0.0f); glVertex3f(startX, 0.0f, startZ);
            glTexCoord2f(repX, 0.0f); glVertex3f(endX,   0.0f, startZ);
            glTexCoord2f(repX, repZ); glVertex3f(endX,   0.0f, endZ);
            glTexCoord2f(0.0f, repZ); glVertex3f(startX, 0.0f, endZ);
        glEnd();

        glPopMatrix();
        glDisable(GL_TEXTURE_2D);
    }

    void drawTexturedSurfaceX(float x, float y, float z, float width, float height, GLuint textureID, bool facingFront) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textureID);
        glColor3f(1.0f, 1.0f, 1.0f); 

        float repX = width / 2.0f;
        float repY = height / 2.0f;

        glBegin(GL_QUADS);
        if (facingFront) {
            glNormal3f(0.0f, 0.0f, 1.0f); // Hadap Z Positif (Depan)
            glTexCoord2f(0.0f, 0.0f); glVertex3f(x - width/2, y, z);
            glTexCoord2f(repX, 0.0f); glVertex3f(x + width/2, y, z);
            glTexCoord2f(repX, repY); glVertex3f(x + width/2, y + height, z);
            glTexCoord2f(0.0f, repY); glVertex3f(x - width/2, y + height, z);
        } else {
            glNormal3f(0.0f, 0.0f, -1.0f); // Hadap Z Negatif (Belakang)
            glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width/2, y, z);
            glTexCoord2f(repX, 0.0f); glVertex3f(x - width/2, y, z);
            glTexCoord2f(repX, repY); glVertex3f(x - width/2, y + height, z);
            glTexCoord2f(0.0f, repY); glVertex3f(x + width/2, y + height, z);
        }
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }

    // Tekstur untuk Tembok Sumbu Z
    void drawTexturedSurfaceZ(float x, float y, float z, float depth, float height, GLuint textureID, bool facingRight) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textureID);
        glColor3f(1.0f, 1.0f, 1.0f); 

        float repY = height / 2.0f;
        float repZ = depth / 2.0f;

        glBegin(GL_QUADS);
        if (facingRight) {
            glNormal3f(1.0f, 0.0f, 0.0f); // Hadap X Positif (Kanan)
            glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z + depth/2);
            glTexCoord2f(repZ, 0.0f); glVertex3f(x, y, z - depth/2);
            glTexCoord2f(repZ, repY); glVertex3f(x, y + height, z - depth/2);
            glTexCoord2f(0.0f, repY); glVertex3f(x, y + height, z + depth/2);
        } else {
            glNormal3f(-1.0f, 0.0f, 0.0f); // Hadap X Negatif (Kiri)
            glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z - depth/2);
            glTexCoord2f(repZ, 0.0f); glVertex3f(x, y, z + depth/2);
            glTexCoord2f(repZ, repY); glVertex3f(x, y + height, z + depth/2);
            glTexCoord2f(0.0f, repY); glVertex3f(x, y + height, z - depth/2);
        }
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }

    void drawConcreteSurfaceWallWithHole(float posX, float posY, float posZ, 
                                        float wallW, float wallH, float thickness, 
                                        float holeX, float holeY, float holeW, float holeH, 
                                        GLuint textureID, bool facingFront) {
        
        // Hitung posisi Z terluar tempat lembaran tekstur akan ditempel
        float surfaceZ = posZ + (facingFront ? (thickness / 2.0f + 0.001f) : -(thickness / 2.0f + 0.001f));

        // 1. Bagian Kiri 
        if (holeX > 0) {
            float leftWidth = holeX;
            float centerLeftX = posX + (leftWidth / 2.0f);
            drawTexturedSurfaceX(centerLeftX, posY, surfaceZ, leftWidth, wallH, textureID, facingFront);
        }
        
        // 2. Bagian Kanan
        float rightWidth = wallW - (holeX + holeW);
        if (rightWidth > 0) {
            float centerRightX = posX + holeX + holeW + (rightWidth / 2.0f);
            drawTexturedSurfaceX(centerRightX, posY, surfaceZ, rightWidth, wallH, textureID, facingFront);
        }
        
        // 3. Bagian Bawah
        if (holeY > 0) {
            float centerHoleX = posX + holeX + (holeW / 2.0f);
            drawTexturedSurfaceX(centerHoleX, posY, surfaceZ, holeW, holeY, textureID, facingFront);
        }
        
        // 4. Bagian Atas / Lintel 
        float topHeight = wallH - (holeY + holeH);
        if (topHeight > 0) {
            float centerHoleX = posX + holeX + (holeW / 2.0f);
            float topY = posY + holeY + holeH;
            drawTexturedSurfaceX(centerHoleX, topY, surfaceZ, holeW, topHeight, textureID, facingFront);
        }
    }

    //Tembok Berlubang Sumbu Z 
    void drawConcreteSurfaceWallWithHoleZ(float positionX, float positionY, float positionZ, 
                                        float wallDepth, float wallHeight, float wallThickness, 
                                        float holeZ, float holeY, float holeDepth, float holeHeight, 
                                        GLuint textureID, bool facingRight) {
        
        // Hitung posisi X terluar tempat lembaran tekstur akan ditempel
        float surfaceX = positionX + (facingRight ? (wallThickness / 2.0f + 0.001f) : -(wallThickness / 2.0f + 0.001f));

        // 1. Bagian Belakang 
        if (holeZ > 0) {
            float backDepth = holeZ;
            float centerZ = positionZ + (backDepth / 2.0f);
            drawTexturedSurfaceZ(surfaceX, positionY, centerZ, backDepth, wallHeight, textureID, facingRight);
        }
        
        // 2. Bagian Depan 
        float frontDepth = wallDepth - (holeZ + holeDepth);
        if (frontDepth > 0) {
            float centerZ = positionZ + holeZ + holeDepth + (frontDepth / 2.0f);
            drawTexturedSurfaceZ(surfaceX, positionY, centerZ, frontDepth, wallHeight, textureID, facingRight);
        }
        
        // 3. Bagian Bawah 
        if (holeY > 0) {
            float centerZ = positionZ + holeZ + (holeDepth / 2.0f);
            drawTexturedSurfaceZ(surfaceX, positionY, centerZ, holeDepth, holeY, textureID, facingRight);
        }
        
        // 4. Bagian Atas / Lintel 
        float topHeight = wallHeight - (holeY + holeHeight);
        if (topHeight > 0) {
            float centerZ = positionZ + holeZ + (holeDepth / 2.0f);
            float topY = positionY + holeY + holeHeight;
            drawTexturedSurfaceZ(surfaceX, topY, centerZ, holeDepth, topHeight, textureID, facingRight);
        }
    }

    void drawCeilingWithHole(float startX, float startZ, float endX, float endZ, 
                            float posY, float thickness, float r, float g, float b,
                            float holeStartX, float holeStartZ, float holeEndX, float holeEndZ) {
        
        // 1. Bagian Belakang
        if (holeStartZ > startZ) {
            float w = endX - startX;
            float d = holeStartZ - startZ;
            drawBlock(startX + w/2.0f, posY, startZ + d/2.0f, w, thickness, d, r, g, b);
        }
        // 2. Bagian Depan
        if (holeEndZ < endZ) {
            float w = endX - startX;
            float d = endZ - holeEndZ;
            drawBlock(startX + w/2.0f, posY, holeEndZ + d/2.0f, w, thickness, d, r, g, b);
        }
        // 3. Bagian Kiri
        if (holeStartX > startX) {
            float w = holeStartX - startX;
            float d = holeEndZ - holeStartZ;
            drawBlock(startX + w/2.0f, posY, holeStartZ + d/2.0f, w, thickness, d, r, g, b);
        }
        // 4. Bagian Kanan
        if (holeEndX < endX) {
            float w = endX - holeEndX;
            float d = holeEndZ - holeStartZ;
            drawBlock(holeEndX + w/2.0f, posY, holeStartZ + d/2.0f, w, thickness, d, r, g, b);
        }
    }

    void drawTexturedKeramikWithHole(float startX, float startZ, float endX, float endZ, 
                                 float posY, float tileSize, GLuint textureID,
                                 float holeStartX, float holeStartZ, float holeEndX, float holeEndZ) {
    
        // 1. Bagian Belakang (Lantai sebelum lubang pada sumbu Z)
        if (holeStartZ > startZ) {
            drawTexturedKeramik(startX, startZ, endX, holeStartZ, posY, tileSize, textureID);
        }
        
        // 2. Bagian Depan (Lantai setelah lubang pada sumbu Z)
        if (holeEndZ < endZ) {
            drawTexturedKeramik(startX, holeEndZ, endX, endZ, posY, tileSize, textureID);
        }
        
        // 3. Bagian Kiri (Lantai di sisi kiri lubang, diapit oleh Z lubang)
        if (holeStartX > startX) {
            drawTexturedKeramik(startX, holeStartZ, holeStartX, holeEndZ, posY, tileSize, textureID);
        }
        
        // 4. Bagian Kanan (Lantai di sisi kanan lubang, diapit oleh Z lubang)
        if (holeEndX < endX) {
            drawTexturedKeramik(holeEndX, holeStartZ, endX, holeEndZ, posY, tileSize, textureID);
        }
    }

    void drawGlassPanel(float x, float y, float z, float width, float height, float depth, float r, float g, float b, float alpha)
    {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glDepthMask(GL_FALSE);

        drawBlock(
            x, y, z,
            width, height, depth,
            r, g, b,
            alpha
        );

        glDepthMask(GL_TRUE);
        glDisable(GL_BLEND);
    }

    void drawTexturedCylinder(float x, float y, float z, float radius, float height, GLuint textureID) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textureID);
        glColor3f(1.0f, 1.0f, 1.0f); // Reset warna agar tekstur tidak gelap
        
        glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); // Tegakkan silinder ke atas (sumbu Y)
        
        GLUquadric* quad = gluNewQuadric();
        gluQuadricTexture(quad, GL_TRUE); // Wajib: Aktifkan mode tekstur untuk quadric
        
        // Gambar selimut tabung
        gluCylinder(quad, radius, radius, height, 32, 1);
        
        // Gambar tutup atas tabung agar tidak bolong
        glTranslatef(0.0f, 0.0f, height);
        gluDisk(quad, 0.0f, radius, 32, 1);
        
        gluDeleteQuadric(quad);
        glPopMatrix();
        
        glDisable(GL_TEXTURE_2D);
    }

    void drawTexturedCurvedWall(float cx, float cy, float cz, float radius, float thickness, float height, float startAngle, float endAngle, int segments, GLuint textureID) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textureID);
        glColor3f(1.0f, 1.0f, 1.0f);

        float rOut = radius + (thickness / 2.0f);
        float rIn = radius - (thickness / 2.0f);
        float pi = 3.14159265f;

        // 1. Gambar Dinding Sisi Luar
        glBegin(GL_QUAD_STRIP);
        for (int i = 0; i <= segments; i++) {
            float angle = startAngle + (endAngle - startAngle) * i / segments;
            float rad = angle * pi / 180.0f;
            float x = cx + rOut * cos(rad);
            float z = cz + rOut * sin(rad);
            float u = (float)i / segments * 2.0f; 
            
            glNormal3f(cos(rad), 0.0f, sin(rad));
            glTexCoord2f(u, 0.0f); glVertex3f(x, cy, z);
            glTexCoord2f(u, height/2.0f); glVertex3f(x, cy + height, z);
        }
        glEnd();

        // 2. Gambar Dinding Sisi Dalam
        glBegin(GL_QUAD_STRIP);
        for (int i = 0; i <= segments; i++) {
            float angle = startAngle + (endAngle - startAngle) * i / segments;
            float rad = angle * pi / 180.0f;
            float x = cx + rIn * cos(rad);
            float z = cz + rIn * sin(rad);
            float u = (float)i / segments * 2.0f;
            
            glNormal3f(-cos(rad), 0.0f, -sin(rad));
            glTexCoord2f(u, 0.0f); glVertex3f(x, cy, z);
            glTexCoord2f(u, height/2.0f); glVertex3f(x, cy + height, z);
        }
        glEnd();

        // 3. Gambar Tutup Atas (Bibir Dinding)
        glBegin(GL_QUAD_STRIP);
        for (int i = 0; i <= segments; i++) {
            float angle = startAngle + (endAngle - startAngle) * i / segments;
            float rad = angle * pi / 180.0f;
            float xOut = cx + rOut * cos(rad);
            float zOut = cz + rOut * sin(rad);
            float xIn = cx + rIn * cos(rad);
            float zIn = cz + rIn * sin(rad);
            float u = (float)i / segments * 2.0f;
            
            glNormal3f(0.0f, 1.0f, 0.0f);
            glTexCoord2f(u, 0.0f); glVertex3f(xIn, cy + height, zIn);
            glTexCoord2f(u, 1.0f); glVertex3f(xOut, cy + height, zOut);
        }
        glEnd();

        glDisable(GL_TEXTURE_2D);
    }