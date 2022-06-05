//
// Created by SRI RAM on 21-11-2020.
//

#include "../../include/GDF/GdfFileReader.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "../../include/GDF/Graph.h"
using namespace std;

void *GdfFileReader::read() {
    fstream *reader=readFile();
    string line;
    vector<int> vertices;
    //Check if the file is opened or not
    if(reader->is_open()){
        getline(*reader,line);
        while (!reader->eof()){
            getline(*reader,line);
            if(line.at(0)!='s'){
                break;
            }
            int vertex=stoi(line.substr(line.find_last_of(' ')+1));
            cout<<line<<" "<<vertex<<endl;
            if(!binary_search(vertices.begin(),vertices.end(),vertex)){
                vertices.push_back(vertex);
            }
        }

        auto *graph=new Graph{static_cast<int>(vertices.size())};

        double **matrix=graph->getAdjMatrix();
        while (!reader->eof()){
            getline(*reader,line);
            int count=0;
            //Loop to check if a graph is weighted or unweighted
            for(char i : line){
                if(i==','){
                    count++;
                }
            }
            int u,v;
            double weight;
            u=stoi(line.substr(1,line.find(',')));
            line=line.substr(line.find(',')+1);
            v=stoi(line.substr(1,line.find(',')));
            line=line.substr(line.find(',')+1);
            //If it is weighted the if condition is executed,
            //If it is unweighted the else condition is executed.
            if(count==3){
                weight=stod(line.substr(0,line.find(',')));
                line=line.substr(line.find(',')+1);
                cout<<u<<" "<<v<<" "<<weight<<endl;
                matrix[u][v]=weight;
                if(line=="false"){
                    matrix[v][u]=weight;
                }
            }else{
                matrix[u][v]=1;
                if(line=="false"){
                    matrix[v][u]=1;
                }
            }


        }
        //Return the graph by casting it to a null pointer.
        return static_cast<void*>(graph);
    }
    return nullptr;


}

GdfFileReader::GdfFileReader(std::fstream *o) : FileReader(o) {}
