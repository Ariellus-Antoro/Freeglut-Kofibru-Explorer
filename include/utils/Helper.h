// Helper.h
#ifndef HELPER_H
#define HELPER_H

#include <GL/freeglut.h> 

// Deklarasikan semua fungsi helper yang kamu miliki
    /**
     * @brief Menggambar balok padat. Titik acuan (pivot) berada di TENGAH BAWAH balok.
     * @param positionX Koordinat X titik tengah bawah balok.
     * @param positionY Koordinat Y titik tengah bawah balok.
     * @param positionZ Koordinat Z titik tengah bawah balok.
     * @param width Lebar balok (membentang di sumbu X).
     * @param height Tinggi balok (membentang di sumbu Y).
     * @param depth Panjang/kedalaman balok (membentang di sumbu Z).
     * @param colorRed Nilai warna merah (0.0f - 1.0f).
     * @param colorGreen Nilai warna hijau (0.0f - 1.0f).
     * @param colorBlue Nilai warna biru (0.0f - 1.0f).
     */
    void drawBlock(float posX, float posY, float posZ, float w, float h, float d, float r, float g, float b,float alpha = 1.0f);


    /**
     * @brief Menggambar dinding horizontal (sepanjang sumbu X) yang memiliki lubang (pintu/jendela).
     * @param positionX Koordinat X titik awal dinding (ujung kiri bawah).
     * @param positionY Koordinat Y titik awal dinding (bawah lantai).
     * @param positionZ Koordinat Z titik tengah kedalaman dinding.
     * @param wallWidth Lebar total dinding (sumbu X).
     * @param wallHeight Tinggi total dinding (sumbu Y).
     * @param wallThickness Ketebalan dinding (sumbu Z).
     * @param holeX Jarak lubang dihitung dari ujung kiri dinding.
     * @param holeY Jarak bagian bawah lubang dari lantai (isi 0.0f jika berupa pintu).
     * @param holeWidth Lebar lubang (sumbu X).
     * @param holeHeight Tinggi lubang (sumbu Y).
     * @param colorRed Nilai warna merah (0.0f - 1.0f).
     * @param colorGreen Nilai warna hijau (0.0f - 1.0f).
     * @param colorBlue Nilai warna biru (0.0f - 1.0f).
     */
    void drawWallWithHole(float posX, float posY, float posZ, float wallW, float wallH, float thickness, float holeX, float holeY, float holeW, float holeH, float r, float g, float b,float alpha = 1.0f);


    /**
     * @brief Menggambar dinding vertikal (sepanjang sumbu Z) yang memiliki lubang (pintu/jendela).
     * @param positionX Koordinat X titik tengah ketebalan dinding.
     * @param positionY Koordinat Y titik awal dinding (bawah lantai).
     * @param positionZ Koordinat Z titik awal dinding (ujung belakang bawah).
     * @param wallDepth Panjang total dinding (sumbu Z).
     * @param wallHeight Tinggi total dinding (sumbu Y).
     * @param wallThickness Ketebalan dinding (sumbu X).
     * @param holeZ Jarak lubang dihitung dari ujung belakang dinding.
     * @param holeY Jarak bagian bawah lubang dari lantai (isi 0.0f jika berupa pintu).
     * @param holeDepth Panjang lubang (sumbu Z).
     * @param holeHeight Tinggi lubang (sumbu Y).
     * @param colorRed Nilai warna merah (0.0f - 1.0f).
     * @param colorGreen Nilai warna hijau (0.0f - 1.0f).
     * @param colorBlue Nilai warna biru (0.0f - 1.0f).
     */
    void drawWallWithHoleZ(float posX, float posY, float posZ, float wallDepth, float wallH, float thickness, float holeZ, float holeY, float holeDepth, float holeH, float r, float g, float b);


    void drawWindow(float posX, float posY, float posZ, float w, float h, float d);

    /**
     * @brief Menggambar bentuk silinder tegak (berguna untuk fasad melengkung).
     * @param positionX Koordinat X titik tengah bawah silinder.
     * @param positionY Koordinat Y titik tengah bawah silinder.
     * @param positionZ Koordinat Z titik tengah bawah silinder.
     * @param radius Jari-jari alas silinder.
     * @param height Tinggi silinder.
     * @param colorRed Nilai warna merah (0.0f - 1.0f).
     * @param colorGreen Nilai warna hijau (0.0f - 1.0f).
     * @param colorBlue Nilai warna biru (0.0f - 1.0f).
     */
    void drawCylinder(float posX, float posY, float posZ, float radius, float h, float r, float g, float b);


    void drawTexturedBlock(float x, float y, float z, float width, float height, float depth, GLuint textureID);
    void drawConcreteWallWithHole(float posX, float posY, float posZ, 
                                float wallW, float wallH, float thickness, 
                                float holeX, float holeY, float holeW, float holeH, 
                                GLuint textureID);
    
    void drawConcreteWallWithHoleZ(float positionX, float positionY, float positionZ, 
                               float wallDepth, float wallHeight, float wallThickness, 
                               float holeZ, float holeY, float holeDepth, float holeHeight, 
                               GLuint textureID);
    
    void drawTexturedKeramik(float startX, float startZ, float endX, float endZ, float posY, float tileSize, GLuint textureID);

    void drawTexturedSurfaceX(float x, float y, float z, float width, float height, GLuint textureID, bool facingFront);

    void drawTexturedSurfaceZ(float x, float y, float z, float depth, float height, GLuint textureID, bool facingRight);

    void drawConcreteSurfaceWallWithHole(float posX, float posY, float posZ, 
                                        float wallW, float wallH, float thickness, 
                                        float holeX, float holeY, float holeW, float holeH, 
                                        GLuint textureID, bool facingFront);

    void drawConcreteSurfaceWallWithHoleZ(float positionX, float positionY, float positionZ, 
                                        float wallDepth, float wallHeight, float wallThickness, 
                                        float holeZ, float holeY, float holeDepth, float holeHeight, 
                                        GLuint textureID, bool facingRight);
#endif