#ifndef MODELLOADER_H
#define MODELLOADER_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <limits>
#include <GL/freeglut.h>

struct Vector3 { float x, y, z; };

class ModelLoader {
public:
    void loadOBJ(const std::string& path) {
        std::ofstream log("debug_log.txt", std::ios::app);

        std::ifstream file(path);
        if (!file.is_open()) {
            log << "Error: Tidak bisa membuka file " << path << std::endl;
            return;
        }

        std::vector<Vector3> tempVertices;
        std::string line;

        minX = minY = minZ = std::numeric_limits<float>::max();
        maxX = maxY = maxZ = std::numeric_limits<float>::lowest();

        while (std::getline(file, line)) {
            if (line.substr(0, 2) == "v ") {
                std::istringstream s(line.substr(2));
                Vector3 v;
                s >> v.x >> v.y >> v.z;
                tempVertices.push_back(v);

                if (v.x < minX) minX = v.x;
                if (v.x > maxX) maxX = v.x;
                if (v.y < minY) minY = v.y;
                if (v.y > maxY) maxY = v.y;
                if (v.z < minZ) minZ = v.z;
                if (v.z > maxZ) maxZ = v.z;
            }
            else if (line.substr(0, 2) == "f ") {
                std::istringstream s(line.substr(2));
                std::vector<int> faceIndices;
                std::string token;

                while (s >> token) {
                    int slashPos = (int)token.find('/');
                    std::string idxStr = (slashPos == (int)std::string::npos) ? token : token.substr(0, slashPos);
                    int idx = std::stoi(idxStr);

                    if (idx < 0) idx = (int)tempVertices.size() + idx + 1;
                    faceIndices.push_back(idx - 1);
                }

                for (size_t i = 1; i + 1 < faceIndices.size(); i++) {
                    faces.push_back(tempVertices[faceIndices[0]]);
                    faces.push_back(tempVertices[faceIndices[i]]);
                    faces.push_back(tempVertices[faceIndices[i + 1]]);
                }
            }
        }
        file.close();

        log << "Berhasil load: " << path << " -> "
            << tempVertices.size() << " vertices, "
            << (faces.size() / 3) << " triangles | "
            << "BBox W=" << (maxX - minX) << " H=" << (maxY - minY) << " D=" << (maxZ - minZ)
            << std::endl;
    }

    void draw() {
        glBegin(GL_TRIANGLES);
        for (const auto& v : faces) {
            glVertex3f(v.x, v.y, v.z);
        }
        glEnd();
    }

    float getWidth()  const { return maxX - minX; }
    float getHeight() const { return maxY - minY; }
    float getDepth()  const { return maxZ - minZ; }
    float getMinX()   const { return minX; }
    float getMinY()   const { return minY; }
    float getMinZ()   const { return minZ; }

private:
    std::vector<Vector3> faces;
    float minX = 0, minY = 0, minZ = 0;
    float maxX = 0, maxY = 0, maxZ = 0;
};

#endif