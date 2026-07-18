#ifndef KURSI_H
#define KURSI_H

/**
 * @class Kursi
 * @brief Menggambar model kursi 3D hasil ekspor dari kursi_simple.stl.
 *
 * Vertex dan face mesh diambil dari kursi_simple.stl (lihat objects/kursi_data.h).
 * Panggil chair.draw() di dalam glPushMatrix()/glPopMatrix() setelah
 * glTranslatef untuk posisi dan glScalef untuk skala (mesh asli dalam satuan cm).
 */
class Kursi {
public:
    Kursi();

    /**
     * @brief Menggambar seluruh mesh kursi (triangle-by-triangle) menggunakan OpenGL fixed pipeline.
     */
    void draw();

private:
    float colorRed, colorGreen, colorBlue; ///< Warna default kursi
};

#endif
