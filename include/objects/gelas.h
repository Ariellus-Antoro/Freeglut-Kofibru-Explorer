#ifndef GELAS_H
#define GELAS_H

/**
 * @class Gelas
 * @brief Menggambar model gelas 3D hasil ekspor dari gelas.stl.
 *
 * Vertex dan face mesh diambil dari gelas.stl (lihat objects/gelas_data.h).
 * Panggil gelas.draw() di dalam glPushMatrix()/glPopMatrix() setelah
 * glTranslatef untuk posisi, glScalef untuk skala, dan glRotatef(-90, 1,0,0)
 * untuk mengoreksi orientasi Z-up (CAD) ke Y-up (OpenGL) -- persis seperti
 * pemakaian Kursi dan Kasir di Gedung.cpp.
 */
class Gelas {
public:
    Gelas();

    /**
     * @brief Menggambar seluruh mesh gelas (triangle-by-triangle) menggunakan OpenGL fixed pipeline.
     */
    void draw();

private:
    float colorRed, colorGreen, colorBlue; ///< Warna default gelas
};

#endif
