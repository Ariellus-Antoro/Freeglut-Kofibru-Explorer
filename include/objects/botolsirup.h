#ifndef BOTOLSIRUP_H
#define BOTOLSIRUP_H

/**
 * @class BotolSirup
 * @brief Menggambar model botol sirup 3D hasil ekspor dari botolSirup.stl.
 *
 * Vertex dan face mesh diambil dari botolSirup.stl (lihat objects/botolsirup_data.h).
 * Body bagian bawah (dekat dasar botol) digambar transparan (kesan kaca/plastik
 * bening berisi sirup), sedangkan body bagian atas (bahu, leher, hingga tutup)
 * digambar hitam pekat (kesan tutup botol).
 *
 * Panggil botolSirup.draw() di dalam glPushMatrix()/glPopMatrix() setelah
 * glTranslatef untuk posisi, glScalef untuk skala (mesh asli dalam satuan cm),
 * dan glRotatef(-90, 1,0,0) untuk mengoreksi orientasi Z-up (CAD) ke Y-up
 * (OpenGL) -- persis seperti pemakaian Gelas di Gedung.cpp.
 */
class BotolSirup {
public:
    BotolSirup();

    /**
     * @brief Menggambar seluruh mesh botol sirup (triangle-by-triangle) menggunakan
     * OpenGL fixed pipeline. Bagian bawah transparan digambar belakangan (setelah
     * bagian atas hitam) supaya blending alpha tampil benar.
     */
    void draw();

private:
    float capRed, capGreen, capBlue;                 ///< Warna body bagian atas (hitam pekat)
    float bodyRed, bodyGreen, bodyBlue, bodyAlpha;    ///< Warna & transparansi body bagian bawah
    float splitZ;                                     ///< Batas ketinggian (mesh lokal) antara body bawah & atas
};

#endif
