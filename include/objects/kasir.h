#ifndef KASIR_H
#define KASIR_H

/**
 * @class Kasir
 * @brief Menggambar model meja/counter kasir 3D hasil ekspor dari kasir.stl.
 *
 * Vertex dan face mesh diambil dari kasir.stl (lihat objects/kasir_data.h).
 * Panggil kasir.draw() di dalam glPushMatrix()/glPopMatrix() setelah
 * glTranslatef untuk posisi, glScalef untuk skala, dan glRotatef(-90, 1,0,0)
 * untuk mengoreksi orientasi Z-up (CAD) ke Y-up (OpenGL) -- persis seperti
 * pemakaian Kursi, KTembok, dan MejaLt2 di Gedung.cpp.
 */
class Kasir {
public:
    Kasir();

    /**
     * @brief Menggambar seluruh mesh kasir (triangle-by-triangle) menggunakan OpenGL fixed pipeline.
     */
    void draw();

private:
    float colorRed, colorGreen, colorBlue; ///< Warna default kasir
};

#endif
