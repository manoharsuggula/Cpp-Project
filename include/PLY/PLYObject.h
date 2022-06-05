#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include <set>

#include "Vertex.h"
#include "Face.h"


class PLYObject {
private:
    VertexVectorType _vertices;
    FaceVectorType _faces;

public:
    PLYObject();
    PLYObject(VertexVectorType vertices, FaceVectorType faces);
    PLYObject(PLYObject& o);
    ~PLYObject();

    VertexVectorType vertices();
    FaceVectorType faces();
    void process();
};