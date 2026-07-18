#ifndef GEDUNG_H
#define GEDUNG_H

#include <GL/freeglut.h>
#include "../utils/ModelLoader.h"

/**
 * @class Gedung
 * @brief Menangani seluruh logika rendering untuk struktur 3D bangunan Kofibru.
 */
class Gedung
{
public:
    Gedung();

    void drawAll();

private:
    float buildingScale;
    ModelLoader logoKofibru; ///< Model 3D logo Kofibru hasil export Fusion 360

    // =========================================================================
    // PRIMITIVE HELPERS
    // =========================================================================
    void drawBlock(float positionX, float positionY, float positionZ, float width, float height, float depth, float colorRed, float colorGreen, float colorBlue);
    void drawCylinder(float positionX, float positionY, float positionZ, float radius, float height, float colorRed, float colorGreen, float colorBlue);

    // =========================================================================
    // ADVANCED HELPERS
    // =========================================================================
    void drawWallWithHole(float positionX, float positionY, float positionZ,
                          float wallWidth, float wallHeight, float wallThickness,
                          float holeX, float holeY, float holeWidth, float holeHeight,
                          float colorRed, float colorGreen, float colorBlue);

    void drawWallWithHoleZ(float positionX, float positionY, float positionZ,
                           float wallDepth, float wallHeight, float wallThickness,
                           float holeZ, float holeY, float holeDepth, float holeHeight,
                           float colorRed, float colorGreen, float colorBlue);

    // =========================================================================
    // FLOOR ASSEMBLY
    // =========================================================================
    void drawLantai1();
    void drawLantai2();
    void drawLantai3();

    // =========================================================================
    // LOGO
    // =========================================================================
    /**
     * @brief Menggambar model 3D logo Kofibru hasil import dari Fusion 360.
     */
    void drawLogo();
};

#endif