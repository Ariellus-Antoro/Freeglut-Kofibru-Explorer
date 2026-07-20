#ifndef BINGKAI_H
#define BINGKAI_H

#include <GL/freeglut.h>

/**
 * @class Bingkai
 * @brief Menggambar model bingkai foto 3D hasil ekspor dari BingkaiGambar.stl.
 *
 * Vertex dan face mesh diambil dari BingkaiGambar.stl (lihat objects/bingkai_data.h),
 * dipisah menjadi 2 bagian berdasarkan geometri aslinya:
 *   - Bingkai luar (molding)       -> warna coklat gelap (solid color)
 *   - Bidang dalam (rabbet/foto)   -> ditekstur dengan gambar (assets/textures/faris.bmp)
 *
 * Texture ID gambar di-load sekali di Gedung::init() lalu di-passing ke draw().
 * Panggil bingkai.draw(fotoTexture) di dalam glPushMatrix()/glPopMatrix() setelah
 * glTranslatef untuk posisi, glScalef untuk skala, dan glRotatef untuk mengoreksi
 * orientasi model (bidang bingkai ada pada sumbu X-Z file asli, ketebalan pada
 * sumbu Y) -- persis seperti pemakaian Jam di Gedung.cpp.
 */
class Bingkai {
public:
    Bingkai();

    /**
     * @brief Menggambar seluruh mesh bingkai (frame luar + bidang foto bertekstur).
     * @param fotoTexture GLuint texture ID hasil load faris.bmp (dari Gedung::init()).
     */
    void draw(GLuint fotoTexture);

private:
    // Warna bingkai luar (coklat gelap)
    float frameRed, frameGreen, frameBlue;
};

#endif
