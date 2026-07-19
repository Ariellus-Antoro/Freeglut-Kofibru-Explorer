#ifndef GEDUNG_H
#define GEDUNG_H



#include <GL/freeglut.h>
#include "objects/KursiBulat.h"
#include "objects/MejaKasir.h"
#include "objects/Menu.h"
#include "objects/Tangga.h"
#include "objects/RakKasir.h"
#include "objects/ktembok.h"
#include "objects/mejakecil.h"
#include "objects/gelas.h"
#include "objects/ac.h"
#include "objects/cctv.h"
#include "objects/kursi.h"
#include "objects/mejalt2.h"
#include "objects/mejakotak.h"
#include "objects/botolsirup.h"





/**
 * @class Gedung
 * @brief Menangani seluruh logika rendering untuk struktur 3D bangunan Kofibru.
 */
class Gedung {
public:
    Gedung();
    GLuint concreteTexture;
    GLuint floorTexture;
    void init();
    
    /**
     * @brief Fungsi utama untuk me-render seluruh gedung.
     * Panggil fungsi ini di dalam loop display utama (main.cpp).
     */
    void drawAll();

private:
    MejaKasir cashierTable;
    KursiBulat chair;
    Menu menu;
    Tangga tangga;
    RakKasir rakKasir;
    KTembok sofa;
    MejaKecil mejaKecil;
    Gelas gelas;
    AC ac;
    CCTV cctv;
    MejaLt2 mejaLt2;
    Kursi chair2;
    MejaKotak mejaKotak;
    BotolSirup botolSirup;


    float buildingScale; ///< Faktor pengali skala gedung (1.0 = normal, 1.5 = 50% lebih besar)

    /**
     * @brief Menggambar lantai dengan pola kotak-kotak (checkerboard) untuk interior gedung.
     * @param startX Batas awal sumbu X.
     * @param startZ Batas awal sumbu Z.
     * @param endX Batas akhir sumbu X.
     * @param endZ Batas akhir sumbu Z.
     * @param posY Ketinggian/elevasi lantai pada sumbu Y.
     * @param tileSize Ukuran satu kotak keramik.
     */
    void drawKeramik(float startX, float startZ, float endX, float endZ, float posY, float tileSize);

    
    /**
     * @brief Merakit dan menggambar seluruh struktur Lantai 1 (Main, Toilet, Teras, Kanopi).
     */
    void drawLantai1();
    
    /**
     * @brief Merakit dan menggambar seluruh struktur Lantai 2 (Area fasad melengkung).
     */
    void drawLantai2();
    
    /**
     * @brief Merakit dan menggambar seluruh struktur Lantai 3 beserta atap utama gedung.
     */
    void drawLantai3();

    // =========================================================================
    // FLOOR Furniture
    // ===================

    /**
     * @brief Merakit dan menggambar seluruh furniture pada Lantai 1 seperti meja, kursi, dan dekorasi.
     */
     void drawFurnitureLantai1();
     void drawFurnitureLantai2();
     void drawFurnitureLantai3();
};

#endif