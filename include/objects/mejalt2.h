#ifndef MEJALT2_H
#define MEJALT2_H

/**
 * @class MejaLt2
 * @brief Menggambar model meja 3D hasil ekspor dari mejaLt2.stl.
 *
 * Vertex dan face mesh diambil dari mejaLt2.stl (lihat objects/mejalt2_data.h).
 * Panggil meja.draw() di dalam glPushMatrix()/glPopMatrix() setelah
 * glTranslatef untuk posisi dan glScalef untuk skala (mesh asli dalam satuan cm),
 * persis seperti pemakaian Kursi dan KTembok.
 */
class MejaLt2 {
public:
    MejaLt2();

    /**
     * @brief Menggambar seluruh mesh meja (triangle-by-triangle) menggunakan OpenGL fixed pipeline.
     */
    void draw();

private:
    float colorRed, colorGreen, colorBlue; ///< Warna default meja
};

#endif
