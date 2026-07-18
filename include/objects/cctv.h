#ifndef CCTV_H
#define CCTV_H

/**
 * @class CCTV
 * @brief Menggambar model kamera CCTV dome 3D hasil ekspor dari CCTV.stl.
 *
 * Vertex dan face mesh diambil dari CCTV.stl (lihat objects/cctv_data.h).
 * Mesh dipisah 2 bagian berdasarkan geometri aslinya:
 *  - Kubah/setengah lingkaran (lensa)  -> digambar gelap
 *  - Dudukan/mounting atas             -> digambar terang
 *
 * Panggil cctv.draw() di dalam glPushMatrix()/glPopMatrix() setelah
 * glTranslatef untuk posisi (menempel di plafon/dinding dekat AC),
 * glScalef untuk skala, dan glRotatef(-90, 1,0,0) untuk mengoreksi
 * orientasi Z-up (CAD) ke Y-up (OpenGL) -- persis seperti pemakaian AC.
 */
class CCTV {
public:
    CCTV();

    /**
     * @brief Menggambar seluruh mesh CCTV (kubah gelap + dudukan terang).
     */
    void draw();

private:
    float domeRed, domeGreen, domeBlue;    ///< Warna bagian kubah/lensa (gelap)
    float mountRed, mountGreen, mountBlue; ///< Warna bagian dudukan atas (terang)
};

#endif
