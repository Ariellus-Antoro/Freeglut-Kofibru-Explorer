// include/objects/ktembok_data.h
// Auto-generated dari KTembok.stl -- JANGAN diedit manual
// 12 vertex unik, 20 triangle (face)
// Satuan koordinat mengikuti file asli (cm)
#pragma once

struct KTembokVertex {
    float x, y, z;
};

struct KTembokFace {
    unsigned int v0, v1, v2; // index ke array KTembokVertices
    float nx, ny, nz;        // normal permukaan
};

const int KTEMBOK_VERTEX_COUNT = 12;
const int KTEMBOK_FACE_COUNT = 20;

static const KTembokVertex KTembokVertices[KTEMBOK_VERTEX_COUNT] = {
    { 45.0000f, 0.0000f, 0.0000f },
    { 0.0000f, 0.0000f, 0.0000f },
    { 45.0000f, 100.0000f, 0.0000f },
    { 0.0000f, 100.0000f, 0.0000f },
    { 45.0000f, 0.0000f, 45.0000f },
    { 45.0000f, 100.0000f, 45.0000f },
    { 5.0000f, 0.0000f, 45.0000f },
    { 5.0000f, 100.0000f, 45.0000f },
    { 5.0000f, 0.0000f, 80.0000f },
    { 5.0000f, 100.0000f, 80.0000f },
    { 0.0000f, 0.0000f, 80.0000f },
    { 0.0000f, 100.0000f, 80.0000f },
};

static const KTembokFace KTembokFaces[KTEMBOK_FACE_COUNT] = {
    { 0, 1, 2, 0.0000f, 0.0000f, -1.0000f },
    { 2, 1, 3, 0.0000f, 0.0000f, -1.0000f },
    { 4, 0, 5, 1.0000f, 0.0000f, 0.0000f },
    { 5, 0, 2, 1.0000f, 0.0000f, 0.0000f },
    { 6, 4, 7, 0.0000f, 0.0000f, 1.0000f },
    { 7, 4, 5, 0.0000f, 0.0000f, 1.0000f },
    { 8, 6, 9, 1.0000f, 0.0000f, 0.0000f },
    { 9, 6, 7, 1.0000f, 0.0000f, 0.0000f },
    { 10, 8, 11, 0.0000f, 0.0000f, 1.0000f },
    { 11, 8, 9, 0.0000f, 0.0000f, 1.0000f },
    { 1, 10, 3, -1.0000f, 0.0000f, 0.0000f },
    { 3, 10, 11, -1.0000f, 0.0000f, 0.0000f },
    { 2, 3, 7, 0.0000f, 1.0000f, 0.0000f },
    { 7, 3, 11, 0.0000f, 1.0000f, 0.0000f },
    { 7, 11, 9, 0.0000f, 1.0000f, 0.0000f },
    { 7, 5, 2, 0.0000f, 1.0000f, 0.0000f },
    { 8, 10, 6, 0.0000f, -1.0000f, 0.0000f },
    { 6, 10, 1, 0.0000f, -1.0000f, 0.0000f },
    { 6, 1, 0, 0.0000f, -1.0000f, 0.0000f },
    { 0, 4, 6, 0.0000f, -1.0000f, 0.0000f },
};
