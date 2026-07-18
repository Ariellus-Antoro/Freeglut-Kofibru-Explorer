#ifndef RUMAH_H
#define RUMAH_H

#include "objects/ruko.h"

/**
 * @class Rumah
 * @brief Menggambar model rumah 3D hasil ekspor dari rumah.stl.
 *
 * Objek ini SENGAJA dibuat berdiri sendiri (bukan bagian dari class Gedung),
 * karena rumah ini posisinya di luar gedung Kofibru. Panggil rumah.draw() dari
 * main.cpp, di world space, terpisah dari transformasi lokal Gedung.
 *
 * Rumah::drawAll() JUGA otomatis memanggil Ruko::drawAll() di dalamnya,
 * jadi cukup panggil rumah.drawAll() sekali dari main.cpp untuk menampilkan
 * rumah dan ruko sekaligus.
 *
 * Vertex dan face mesh diambil dari rumah.stl (lihat objects/rumah_data.h).
 * Mesh dipisah 4 bagian berdasarkan geometri planar aslinya:
 *  - Atap    -> coklat gelap
 *  - Tembok  -> abu-abu
 *  - Pintu   -> coklat
 *  - Jendela -> biru
 *
 * Panggil rumah.draw() di dalam glPushMatrix()/glPopMatrix() setelah
 * glTranslatef untuk posisi (letakkan jauh dari footprint Gedung supaya
 * jelas berada di luar), glScalef untuk skala, dan glRotatef(-90, 1,0,0)
 * untuk mengoreksi orientasi Z-up (CAD) ke Y-up (OpenGL).
 */
class Rumah {
public:
    Rumah();

    /**
     * @brief Menggambar seluruh mesh rumah (atap, tembok, pintu, jendela dengan warna berbeda).
     * Tidak melakukan transformasi apa pun -- posisi/skala harus diatur oleh pemanggil.
     */
    void draw();

    /**
     * @brief Menggambar rumah + ruko lengkap dengan posisi, skala, dan rotasi koreksi
     * (Z-up CAD -> Y-up OpenGL) sudah otomatis diatur di dalam.
     * Cukup panggil rumah.drawAll() dari main.cpp, tanpa perlu
     * glPushMatrix/glTranslatef/glScalef/glRotatef manual di luar.
     */
    void drawAll();

private:
    float atapRed, atapGreen, atapBlue;
    float tembokRed, tembokGreen, tembokBlue;
    float pintuRed, pintuGreen, pintuBlue;
    float jendelaRed, jendelaGreen, jendelaBlue;

    Ruko ruko; ///< Ruko digambar otomatis bersamaan lewat drawAll()
};

#endif
