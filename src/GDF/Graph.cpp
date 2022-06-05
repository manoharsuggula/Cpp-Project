//
// Created by SRI RAM on 21-11-2020.
//

#include "../../include/GDF/Graph.h"

//Main Constructor
Graph::Graph(int numberOfVertices) : numberOfVertices(numberOfVertices) {
    adjMatrix= new double*[numberOfVertices+1];
    for(int i=0;i<numberOfVertices+1;i++){
        adjMatrix[i]=new double [numberOfVertices+1];
    }
    for(int i=0;i<numberOfVertices+1;i++){
        for(int j=0;j<numberOfVertices+1;j++){
            adjMatrix[i][j]=0;
        }
    }

}

//Destructor
Graph::~Graph() {
    for(int i=0;i<numberOfVertices+1;i++){
        delete [] adjMatrix[i];
    }
    delete [] adjMatrix;
}

//Getters
double **Graph::getAdjMatrix() const {
    return adjMatrix;
}

int Graph::getNumberOfVertices() const {
    return numberOfVertices;
}