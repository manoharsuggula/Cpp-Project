//
// Created by SRI RAM on 21-11-2020.
//

#include "../../include/GDF/GdfFileWriter.h"
#include <vector>
#include <fstream>
#include <iostream>
#include "../../include/GDF/Graph.h"
#include <iomanip>
using namespace std;

void GdfFileWriter::write(void *pVoid) {
    //Check whether pointer is a null pointer or not
    if(pVoid== nullptr){
        return;
    }
    //Cast the object to custom created object which in this case is a Graph Object.
    auto *g=static_cast<Graph*>(pVoid);
    cout<<g->getNumberOfVertices()<<endl;
    double ** matrix=g->getAdjMatrix();
        fstream *writer=writeFile();
   //Write into the output file:
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    string line="; ";
    for(int i=1;i<g->getNumberOfVertices();i++){
        line+="s";
        line+=to_string(i);
        line+="; ";
    }
    line+="s"+to_string(g->getNumberOfVertices());
    (*writer)<<line+"\n";
    for(int i=1;i<g->getNumberOfVertices()+1;i++){
        (*writer)<<"s"+to_string(i);
        for(int j=1;j<g->getNumberOfVertices()+1;j++){
            (*writer)<<"; ";
            (*writer)<<setprecision(3)<<matrix[i][j];
        }
        (*writer)<<"\n";
    }
}

GdfFileWriter::GdfFileWriter(std::fstream *o) : FileWriter(o) {}
