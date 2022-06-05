#pragma once

#include <string>

#define VertexType Vertex<double,double,double>
#define VertexVectorType std::vector<VertexType*>

template<typename T, typename U, typename V>
class Vertex {
private:
    T _x;
    U _y;
    V _z;

public:
    Vertex();
    Vertex(T, U, V);
    Vertex(Vertex<T, U, V>&);
    ~Vertex();

    T x();
    U y();
    V z();
};

template class VertexType;