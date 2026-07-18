#ifndef KTEMBOK_H
#define KTEMBOK_H

/**
 * @class KTembok
 * @brief Menggambar model tembok 3D hasil ekspor dari KTembok.stl.
 *
 * Vertex dan face mesh diambil dari KTembok.stl (lihat objects/ktembok_data.h).
 * Panggil tembok.draw() di dalam glPushMatrix()/glPopMatrix() setelah
 * glTranslatef untuk posisi dan glScalef untuk skala (mesh asli dalam satuan cm),
 * persis seperti pemakaian Kursi.
 */
class KTembok {
public:
    KTembok();

    /**
     * @brief Menggambar seluruh mesh tembok (triangle-by-triangle) menggunakan OpenGL fixed pipeline.
     */
    void draw();

private:
    float colorRed, colorGreen, colorBlue; ///< Warna default tembok
};

#endif
