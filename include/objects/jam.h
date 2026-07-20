#ifndef JAM_H
#define JAM_H

/**
 * @class Jam
 * @brief Menggambar model jam dinding 3D hasil ekspor dari jam.stl.
 *
 * Vertex dan face mesh diambil dari jam.stl (lihat objects/jam_data.h),
 * dipisah menjadi 3 bagian berdasarkan geometri aslinya:
 *   - Casing/bezel luar  -> warna coklat tua
 *   - Dial (pelat muka)  -> warna putih
 *   - Angka & jarum      -> warna gelap
 *
 * Panggil jam.draw() di dalam glPushMatrix()/glPopMatrix() setelah
 * glTranslatef untuk posisi, glScalef untuk skala, dan glRotatef
 * untuk mengoreksi orientasi model (bidang muka jam ada pada sumbu
 * Y-Z file asli, ketebalan pada sumbu X) -- persis seperti pemakaian
 * AC dan CCTV di Gedung.cpp.
 */
class Jam {
public:
    Jam();

    /**
     * @brief Menggambar seluruh mesh jam (casing, dial, angka/jarum) triangle-by-triangle.
     */
    void draw();

private:
    // Warna casing/bezel luar (coklat tua)
    float caseRed, caseGreen, caseBlue;

    // Warna dial/pelat muka (putih)
    float dialRed, dialGreen, dialBlue;

    // Warna angka & jarum (gelap)
    float markRed, markGreen, markBlue;
};

#endif
