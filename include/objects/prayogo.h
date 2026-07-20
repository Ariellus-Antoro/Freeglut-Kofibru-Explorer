#ifndef PRAYOGO_H
#define PRAYOGO_H

/**
 * @class Prayogo
 * @brief Menggambar model rumah "Prayogo" hasil ekspor dari Prayogo.stl.
 *
 * Vertex dan face mesh diambil dari Prayogo.stl (lihat objects/prayogo_data.h).
 * Mesh dipisah 10 bagian (body) berdasarkan segmentasi geometri aslinya:
 *  - Body 1        (bangunan bagian bawah)                -> biru gelap
 *  - Body 2 & 3    (atap/kanopi yang menonjol ke bawah)    -> biru muda
 *  - Body 4        (ornamen tengah, antara bangunan atas
 *                    dan bawah)                            -> pink
 *  - Body 5        (bangunan bagian atas)                  -> abu-abu terang
 *  - Body 6 & 7    (2 jendela atas)                         -> hitam
 *  - Body 8, 9, 10 (pintu bangunan bawah)                   -> kuning gelap
 *
 * Class ini HANYA punya draw() (tanpa transformasi apa pun), persis seperti
 * class Ruko. Posisi, skala, dan rotasi Prayogo diatur langsung di dalam
 * Rumah::drawAll() (rumah.cpp), di sebelah Ruko.
 */
class Prayogo {
public:
    Prayogo();

    /**
     * @brief Menggambar seluruh mesh Prayogo (10 body dengan warna berbeda).
     * Tidak melakukan transformasi apa pun -- posisi/skala diatur oleh pemanggil.
     */
    void draw();

private:
    // Body 1 -- bangunan bagian bawah (abu-abu terang)
    float body1Red, body1Green, body1Blue;

    // Body 2 & 3 -- atap/kanopi menonjol bawah (abu-abu gelap)
    float body23Red, body23Green, body23Blue;

    // Body 4 -- ornamen tengah (abu-abu gelap)
    float body4Red, body4Green, body4Blue;

    // Body 5 -- bangunan bagian atas (abu-abu terang)
    float body5Red, body5Green, body5Blue;

    // Body 6 & 7 -- 2 jendela atas (hitam)
    float body67Red, body67Green, body67Blue;

    // Body 8, 9, 10 -- pintu bangunan bawah (kuning gelap)
    float body8910Red, body8910Green, body8910Blue;
};

#endif
