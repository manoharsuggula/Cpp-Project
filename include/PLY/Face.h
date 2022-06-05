#pragma once

#include "Vertex.h"
#define FaceVectorType std::vector<Face*>

#include <vector>
#include <cmath>

class Face {
private:
    std::vector<int> _vertices;

public:
    Face();
    Face(std::vector<int>);
    Face(Face&);
    ~Face();

    void addVertex(int idx);
    std::vector<int> vertices();
    size_t numVertices();
    FaceVectorType process();

friend double area(VertexVectorType& vertices, Face* o);
};