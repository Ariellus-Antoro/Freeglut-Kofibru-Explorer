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

/**
 * @class Gedung
 * @brief Menangani seluruh logika rendering untuk struktur 3D bangunan Kofibru.
 */
class Gedung {
public:
    Gedung();
    
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

    float buildingScale; ///< Faktor pengali skala gedung (1.0 = normal, 1.5 = 50% lebih besar)

    // =========================================================================
    // PRIMITIVE HELPERS
    // =========================================================================
    
    /**
     * @brief Menggambar balok padat. Titik acuan (pivot) berada di TENGAH BAWAH balok.
     * @param positionX Koordinat X titik tengah bawah balok.
     * @param positionY Koordinat Y titik tengah bawah balok.
     * @param positionZ Koordinat Z titik tengah bawah balok.
     * @param width Lebar balok (membentang di sumbu X).
     * @param height Tinggi balok (membentang di sumbu Y).
     * @param depth Panjang/kedalaman balok (membentang di sumbu Z).
     * @param colorRed Nilai warna merah (0.0f - 1.0f).
     * @param colorGreen Nilai warna hijau (0.0f - 1.0f).
     * @param colorBlue Nilai warna biru (0.0f - 1.0f).
     */
    void drawBlock(float positionX, float positionY, float positionZ, float width, float height, float depth, float colorRed, float colorGreen, float colorBlue);
    
    /**
     * @brief Menggambar bentuk silinder tegak (berguna untuk fasad melengkung).
     * @param positionX Koordinat X titik tengah bawah silinder.
     * @param positionY Koordinat Y titik tengah bawah silinder.
     * @param positionZ Koordinat Z titik tengah bawah silinder.
     * @param radius Jari-jari alas silinder.
     * @param height Tinggi silinder.
     * @param colorRed Nilai warna merah (0.0f - 1.0f).
     * @param colorGreen Nilai warna hijau (0.0f - 1.0f).
     * @param colorBlue Nilai warna biru (0.0f - 1.0f).
     */
    void drawCylinder(float positionX, float positionY, float positionZ, float radius, float height, float colorRed, float colorGreen, float colorBlue);

    // =========================================================================
    // ADVANCED HELPERS
    // =========================================================================
    
    /**
     * @brief Menggambar dinding horizontal (sepanjang sumbu X) yang memiliki lubang (pintu/jendela).
     * @param positionX Koordinat X titik awal dinding (ujung kiri bawah).
     * @param positionY Koordinat Y titik awal dinding (bawah lantai).
     * @param positionZ Koordinat Z titik tengah kedalaman dinding.
     * @param wallWidth Lebar total dinding (sumbu X).
     * @param wallHeight Tinggi total dinding (sumbu Y).
     * @param wallThickness Ketebalan dinding (sumbu Z).
     * @param holeX Jarak lubang dihitung dari ujung kiri dinding.
     * @param holeY Jarak bagian bawah lubang dari lantai (isi 0.0f jika berupa pintu).
     * @param holeWidth Lebar lubang (sumbu X).
     * @param holeHeight Tinggi lubang (sumbu Y).
     * @param colorRed Nilai warna merah (0.0f - 1.0f).
     * @param colorGreen Nilai warna hijau (0.0f - 1.0f).
     * @param colorBlue Nilai warna biru (0.0f - 1.0f).
     */
    void drawWallWithHole(float positionX, float positionY, float positionZ, 
                          float wallWidth, float wallHeight, float wallThickness, 
                          float holeX, float holeY, float holeWidth, float holeHeight, 
                          float colorRed, float colorGreen, float colorBlue);

    /**
     * @brief Menggambar dinding vertikal (sepanjang sumbu Z) yang memiliki lubang (pintu/jendela).
     * @param positionX Koordinat X titik tengah ketebalan dinding.
     * @param positionY Koordinat Y titik awal dinding (bawah lantai).
     * @param positionZ Koordinat Z titik awal dinding (ujung belakang bawah).
     * @param wallDepth Panjang total dinding (sumbu Z).
     * @param wallHeight Tinggi total dinding (sumbu Y).
     * @param wallThickness Ketebalan dinding (sumbu X).
     * @param holeZ Jarak lubang dihitung dari ujung belakang dinding.
     * @param holeY Jarak bagian bawah lubang dari lantai (isi 0.0f jika berupa pintu).
     * @param holeDepth Panjang lubang (sumbu Z).
     * @param holeHeight Tinggi lubang (sumbu Y).
     * @param colorRed Nilai warna merah (0.0f - 1.0f).
     * @param colorGreen Nilai warna hijau (0.0f - 1.0f).
     * @param colorBlue Nilai warna biru (0.0f - 1.0f).
     */
    void drawWallWithHoleZ(float positionX, float positionY, float positionZ, 
                           float wallDepth, float wallHeight, float wallThickness, 
                           float holeZ, float holeY, float holeDepth, float holeHeight, 
                           float colorRed, float colorGreen, float colorBlue);

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

    // =========================================================================
    // FLOOR ASSEMBLY
    // =========================================================================

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
};

#endif