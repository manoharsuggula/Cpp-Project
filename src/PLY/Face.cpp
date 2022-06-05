#include "../../include/PLY/Face.h"

Face::Face() {};

Face::Face(std::vector<int> vertices)
: _vertices(vertices) {}

Face::Face(Face& o) 
: _vertices(o._vertices) {}

Face::~Face() {};

void Face::addVertex(int idx) {
    _vertices.push_back(idx);
};

size_t Face::numVertices() {
    return _vertices.size();
}

std::vector<int> Face::vertices() {
    return _vertices;
}

FaceVectorType Face::process() {
    FaceVectorType faces;
    if (numVertices() < 3) return faces;
    if (numVertices() == 3) {
        faces.push_back(new Face(*this));
    } else {
        for (size_t i = 1; i < numVertices() - 1; i++) {
            faces.push_back(new Face(std::vector<int>{_vertices[0], _vertices[i], _vertices[i+1]}));
        }
    }
    return faces;
}

double distance(VertexType* v1, VertexType* v2) {
    double delX = v1->x() - v2->x();
    double delY = v1->y() - v2->y();
    double delZ = v1->z() - v2->z();
    double sqDist = delX * delX + delY * delY + delZ * delZ;
    return sqrt(sqDist);
}

double heron(VertexType* v1, VertexType* v2, VertexType* v3) {
    double a = distance(v1, v2);
    double b = distance(v2, v3);
    double c = distance(v3, v1);
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double area(VertexVectorType& vertices, Face* o) {
    if (o->numVertices() == 3) {
        VertexType* v1 = vertices[o->_vertices[0]];
        VertexType* v2 = vertices[o->_vertices[1]];
        VertexType* v3 = vertices[o->_vertices[2]];
        return heron(v1, v2, v3);
    }
    return UINT64_MAX;
}