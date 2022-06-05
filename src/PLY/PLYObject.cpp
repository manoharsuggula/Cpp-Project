#include "../../include/PLY/PLYObject.h"

PLYObject::PLYObject() {}

PLYObject::PLYObject(VertexVectorType vertices, FaceVectorType faces) 
: _vertices(vertices), _faces(faces) {}

PLYObject::PLYObject(PLYObject& o)
: _faces(o._faces) {
    for (VertexType* vertex: o._vertices) {
        _vertices.push_back(new VertexType(vertex->x(), vertex->y(), vertex->z()));
    }
}

PLYObject::~PLYObject() {
    for (auto vertex: _vertices) delete vertex;
    _vertices.clear();
    for (auto face: _faces) delete face;
    _faces.clear();
}

VertexVectorType PLYObject::vertices() {
    return _vertices;
}

FaceVectorType PLYObject::faces() {
    return _faces;
}

void PLYObject::process() {
    FaceVectorType newFaces;
    for (auto face: _faces) {
        FaceVectorType faceVect = face->process();
        for (auto newFace: faceVect) {
            newFaces.push_back(newFace);
        }
        delete face;
    }/*
    _faces.clear();
    _faces = newFaces;
    */
    std::sort(newFaces.begin(), newFaces.end(), [this](Face* f1, Face* f2) {
        return area(_vertices, f1) > area(_vertices, f2);
    });
    size_t numDrop = newFaces.size() / 10;
    for (size_t i = 0; i < numDrop; i++) {
        delete newFaces[newFaces.size() - 1];
        newFaces.pop_back();
    }
    std::set<int> vertIdx;
    std::set<int> recheck;
    for (auto face: newFaces) {
        for (auto i: face->vertices()) vertIdx.insert(i);
    }
    VertexVectorType finalVertices;
    int totVertices = _vertices.size();
    for (int i = 0; i < totVertices; i++) {
        if (vertIdx.find(i) == vertIdx.end()) {
            delete _vertices[i];
            recheck.insert(i);
        } else {
            finalVertices.push_back(_vertices[i]);
        }
    }
    FaceVectorType newFaces2;
    for (auto face: newFaces) {
        std::vector<int> v = face->vertices();
        for (int i = 0; i < v.size(); i++) {
            v[i] -= std::distance(recheck.begin(), recheck.lower_bound(v[i]));
        }
        newFaces2.push_back(new Face(v));
        delete face;
    }
    _faces.clear();
    _faces = newFaces2;
    _vertices.clear();
    _vertices = finalVertices;
}