// include/objects/bingkai_data.h
// Auto-generated dari BingkaiGambar.stl -- JANGAN diedit manual
// Mesh dipisah 2 bagian berdasarkan geometri hasil analisis STL:
//   BingkaiFrame -> bagian luar bingkai (molding) -> warna coklat gelap
//   BingkaiFoto  -> bidang dalam/rabbet tempat foto -> ditekstur (assets/textures/faris.bmp)
// Sumbu asli file (satuan cm): X & Z = bidang lebar/tinggi bingkai (0..500, 0..250), Y = ketebalan (0..10)
#pragma once

struct BingkaiVertex { float x, y, z; };
struct BingkaiFace { unsigned int v0, v1, v2; float nx, ny, nz; };

const int BINGKAI_FRAME_VERTEX_COUNT = 16;
const int BINGKAI_FRAME_FACE_COUNT = 26;
static const BingkaiVertex BingkaiFrameVertices[BINGKAI_FRAME_VERTEX_COUNT] = {
    { 490.0000f, 5.0000f, 240.0000f },
    { 490.0000f, 5.0000f, 10.0000f },
    { 490.0000f, 0.0000f, 240.0000f },
    { 490.0000f, 0.0000f, 10.0000f },
    { 10.0000f, 5.0000f, 10.0000f },
    { 10.0000f, 0.0000f, 10.0000f },
    { 10.0000f, 5.0000f, 240.0000f },
    { 10.0000f, 0.0000f, 240.0000f },
    { 500.0000f, 10.0000f, 0.0000f },
    { 500.0000f, 10.0000f, 250.0000f },
    { 500.0000f, 0.0000f, 0.0000f },
    { 500.0000f, 0.0000f, 250.0000f },
    { 0.0000f, 10.0000f, 0.0000f },
    { 0.0000f, 0.0000f, 0.0000f },
    { 0.0000f, 10.0000f, 250.0000f },
    { 0.0000f, 0.0000f, 250.0000f },
};

static const BingkaiFace BingkaiFrameFaces[BINGKAI_FRAME_FACE_COUNT] = {
    { 0, 1, 2, -1.0000f, -0.0000f, -0.0000f },
    { 2, 1, 3, -1.0000f, -0.0000f, -0.0000f },
    { 1, 4, 3, 0.0000f, 0.0000f, 1.0000f },
    { 3, 4, 5, 0.0000f, 0.0000f, 1.0000f },
    { 6, 0, 7, 0.0000f, -0.0000f, -1.0000f },
    { 7, 0, 2, 0.0000f, 0.0000f, -1.0000f },
    { 4, 6, 5, 1.0000f, 0.0000f, -0.0000f },
    { 5, 6, 7, 1.0000f, 0.0000f, -0.0000f },
    { 8, 9, 10, 1.0000f, 0.0000f, -0.0000f },
    { 10, 9, 11, 1.0000f, 0.0000f, -0.0000f },
    { 12, 8, 13, 0.0000f, -0.0000f, -1.0000f },
    { 13, 8, 10, 0.0000f, 0.0000f, -1.0000f },
    { 14, 12, 15, -1.0000f, -0.0000f, -0.0000f },
    { 15, 12, 13, -1.0000f, -0.0000f, -0.0000f },
    { 9, 14, 11, 0.0000f, 0.0000f, 1.0000f },
    { 11, 14, 15, 0.0000f, 0.0000f, 1.0000f },
    { 14, 9, 12, -0.0000f, 1.0000f, 0.0000f },
    { 12, 9, 8, -0.0000f, 1.0000f, 0.0000f },
    { 3, 5, 13, -0.0000f, -1.0000f, 0.0000f },
    { 13, 5, 7, 0.0000f, -1.0000f, 0.0000f },
    { 13, 7, 15, 0.0000f, -1.0000f, 0.0000f },
    { 15, 7, 2, 0.0000f, -1.0000f, 0.0000f },
    { 15, 2, 11, 0.0000f, -1.0000f, 0.0000f },
    { 11, 2, 3, 0.0000f, -1.0000f, -0.0000f },
    { 11, 3, 10, 0.0000f, -1.0000f, -0.0000f },
    { 10, 3, 13, -0.0000f, -1.0000f, 0.0000f },
};

struct BingkaiFotoVertex { float x, y, z, u, v; };

const int BINGKAI_FOTO_VERTEX_COUNT = 4;
const int BINGKAI_FOTO_FACE_COUNT = 2;
static const BingkaiFotoVertex BingkaiFotoVertices[BINGKAI_FOTO_VERTEX_COUNT] = {
    { 10.0000f, 5.0000f, 240.0000f, 0.0000f, 1.0000f },
    { 10.0000f, 5.0000f, 10.0000f, 0.0000f, 0.0000f },
    { 490.0000f, 5.0000f, 240.0000f, 1.0000f, 1.0000f },
    { 490.0000f, 5.0000f, 10.0000f, 1.0000f, 0.0000f },
};

static const BingkaiFace BingkaiFotoFaces[BINGKAI_FOTO_FACE_COUNT] = {
    { 0, 1, 2, 0.0000f, -1.0000f, 0.0000f },
    { 2, 1, 3, 0.0000f, -1.0000f, -0.0000f },
};

