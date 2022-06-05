#include "../../include/PLY/Vertex.h"

template<typename T, typename U, typename V>
Vertex<T, U, V>::Vertex() {}

template<typename T, typename U, typename V>
Vertex<T, U, V>::Vertex(T x, U y, V z) 
: _x(x), _y(y), _z(z) {}

template<typename T, typename U, typename V>
Vertex<T, U, V>::Vertex(Vertex<T, U, V>& o) 
: _x(o._x), _y(o._y), _z(o._z) {}

template<typename T, typename U, typename V>
Vertex<T, U, V>::~Vertex() {}

template<typename T, typename U, typename V>
T Vertex<T, U, V>::x() {
    return _x;
}

template<typename T, typename U, typename V>
U Vertex<T, U, V>::y() {
    return _y;
}

template<typename T, typename U, typename V>
V Vertex<T, U, V>::z() {
    return _z;
}