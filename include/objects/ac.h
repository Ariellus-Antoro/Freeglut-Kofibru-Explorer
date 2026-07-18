#ifndef AC_H
#define AC_H

/**
 * @class AC
 * @brief Menggambar model unit AC (indoor) 3D hasil ekspor dari AC.stl.
 *
 * Vertex dan face mesh diambil dari AC.stl (lihat objects/ac_data.h).
 * Panggil ac.draw() di dalam glPushMatrix()/glPopMatrix() setelah
 * glTranslatef untuk posisi (biasanya menempel di dekat plafon/wallHeight),
 * glScalef untuk skala, dan glRotatef(-90, 1,0,0) untuk mengoreksi orientasi
 * Z-up (CAD) ke Y-up (OpenGL) -- persis seperti pemakaian Kursi dan Kasir
 * di Gedung.cpp.
 */
class AC {
public:
    AC();

    /**
     * @brief Menggambar seluruh mesh AC (triangle-by-triangle) menggunakan OpenGL fixed pipeline.
     */
    void draw();

private:
    float colorRed, colorGreen, colorBlue; ///< Warna default body AC
};

#endif
