//
// Created by SRI RAM on 21-11-2020.
//

#ifndef PROJECT_GRAPH_H
#define PROJECT_GRAPH_H



class Graph {
private:
    int numberOfVertices;
    double **adjMatrix;
public:
    Graph(int numberOfVertices);

    int getNumberOfVertices() const;

    double **getAdjMatrix() const;

    virtual ~Graph();
};


#endif //PROJECT_GRAPH_H
