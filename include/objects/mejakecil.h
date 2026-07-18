#ifndef MEJAKECIL_H
#define MEJAKECIL_H

/**
 * @class MejaKecil
 * @brief Menggambar model meja kecil 3D hasil ekspor dari meja_kecil.stl.
 *
 * Vertex dan face mesh diambil dari meja_kecil.stl (lihat objects/mejakecil_data.h).
 * Panggil mejaKecil.draw() di dalam glPushMatrix()/glPopMatrix() setelah
 * glTranslatef untuk posisi dan glScalef untuk skala (mesh asli dalam satuan cm),
 * persis seperti pemakaian Kursi dan MejaLt2.
 */
class MejaKecil {
public:
    MejaKecil();

    /**
     * @brief Menggambar seluruh mesh meja kecil (triangle-by-triangle) menggunakan OpenGL fixed pipeline.
     */
    void draw();

private:
    float colorRed, colorGreen, colorBlue; ///< Warna default meja kecil
};

#endif
