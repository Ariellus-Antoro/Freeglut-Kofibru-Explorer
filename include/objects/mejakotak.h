#ifndef MEJAKOTAK_H
#define MEJAKOTAK_H

/**
 * @class MejaKotak
 * @brief Menggambar model meja kotak 3D hasil ekspor dari mejakotak.stl.
 *
 * Vertex dan face mesh diambil dari mejakotak.stl (lihat objects/mejakotak_data.h).
 * Panggil mejaKotak.draw() di dalam glPushMatrix()/glPopMatrix() setelah
 * glTranslatef untuk posisi dan glScalef untuk skala (mesh asli dalam satuan cm),
 * persis seperti pemakaian MejaLt2 dan Kursi.
 */
class MejaKotak {
public:
    MejaKotak();

    /**
     * @brief Menggambar seluruh mesh meja kotak (triangle-by-triangle) menggunakan OpenGL fixed pipeline.
     */
    void draw();

private:
    float colorRed, colorGreen, colorBlue; ///< Warna default meja kotak
};

#endif
