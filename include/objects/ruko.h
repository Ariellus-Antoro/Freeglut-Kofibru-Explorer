#ifndef RUKO_H
#define RUKO_H

/**
 * @class Ruko
 * @brief Menggambar model ruko (rumah toko) 3D hasil ekspor dari ruko.stl.
 *
 * Vertex dan face mesh diambil dari ruko.stl (lihat objects/ruko_data.h).
 * Mesh dipisah 3 bagian berdasarkan geometri planar aslinya:
 *  - Tembok  -> biru tua
 *  - Pintu   -> coklat
 *  - Jendela -> biru muda (mayoritas di lantai atas)
 *
 * Class ini HANYA punya draw() (tanpa transformasi apa pun). Posisi, skala,
 * dan rotasi ruko diatur langsung di dalam Rumah::drawAll() (rumah.cpp),
 * persis seperti Gedung.cpp mengatur posisi kasir/chair/dll lewat
 * glPushMatrix/glTranslatef/glScalef/glRotatef manual.
 */
class Ruko {
public:
    Ruko();

    /**
     * @brief Menggambar seluruh mesh ruko (tembok, pintu, jendela dengan warna berbeda).
     * Tidak melakukan transformasi apa pun -- posisi/skala diatur oleh pemanggil.
     */
    void draw();

private:
    float tembokRed, tembokGreen, tembokBlue;
    float pintuRed, pintuGreen, pintuBlue;
    float jendelaRed, jendelaGreen, jendelaBlue;
};

#endif
