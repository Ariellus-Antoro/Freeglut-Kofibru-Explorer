// include/objects/ac_data.h
// Auto-generated dari AC.stl -- JANGAN diedit manual
// 10 vertex unik, 16 triangle (face)
// Satuan koordinat mengikuti file asli (cm)
#pragma once

struct ACVertex {
    float x, y, z;
};

struct ACFace {
    unsigned int v0, v1, v2;
    float nx, ny, nz;
};

const int AC_VERTEX_COUNT = 10;
const int AC_FACE_COUNT = 16;

static const ACVertex ACVertices[AC_VERTEX_COUNT] = {
    { 0.0000f, 0.0000f, 30.0000f },
    { 0.0000f, 0.0000f, 0.0000f },
    { 100.0000f, 0.0000f, 30.0000f },
    { 100.0000f, 0.0000f, 0.0000f },
    { 0.0000f, 30.0000f, 30.0000f },
    { 100.0000f, 30.0000f, 30.0000f },
    { 0.0000f, 30.0000f, 15.0000f },
    { 100.0000f, 30.0000f, 15.0000f },
    { 0.0000f, 15.0000f, 0.0000f },
    { 100.0000f, 15.0000f, 0.0000f },
};

static const ACFace ACFaces[AC_FACE_COUNT] = {
    { 0, 1, 2, 0.0000f, -1.0000f, 0.0000f },
    { 2, 1, 3, 0.0000f, -1.0000f, -0.0000f },
    { 4, 0, 5, -0.0000f, 0.0000f, 1.0000f },
    { 5, 0, 2, -0.0000f, 0.0000f, 1.0000f },
    { 6, 4, 7, -0.0000f, 1.0000f, 0.0000f },
    { 7, 4, 5, 0.0000f, 1.0000f, -0.0000f },
    { 8, 6, 9, 0.0000f, 0.7071f, -0.7071f },
    { 9, 6, 7, 0.0000f, 0.7071f, -0.7071f },
    { 1, 8, 3, 0.0000f, 0.0000f, -1.0000f },
    { 3, 8, 9, 0.0000f, 0.0000f, -1.0000f },
    { 3, 9, 2, 1.0000f, 0.0000f, -0.0000f },
    { 2, 9, 7, 1.0000f, -0.0000f, 0.0000f },
    { 2, 7, 5, 1.0000f, -0.0000f, 0.0000f },
    { 1, 0, 8, -1.0000f, 0.0000f, 0.0000f },
    { 8, 0, 6, -1.0000f, 0.0000f, 0.0000f },
    { 6, 0, 4, -1.0000f, 0.0000f, 0.0000f },
};