#include "../../include/CSV/csvFileWriter.h"
#include<iostream>
#include<iomanip>
#include "../../include/CSV/csv.h"
csvFileWriter::csvFileWriter(std::fstream *o):FileWriter(o){}

void csvFileWriter::write(void *csvf){
    std::fstream *fout = writeFile();
    csv* csvfile = (csv*)csvf;
    //fout.open("transposeFile.csv",ios::app | ios::out);
    for(int i=0;i<csvfile->getCopyTable().size();i++){
        for(int j=0;j<csvfile->getCopyTable()[i].size();j++){
            if(j!=csvfile->getCopyTable()[i].size()-1){
                (*fout)<<csvfile->getCopyTable()[i][j]<<",";
            }
            else{
                (*fout)<<csvfile->getCopyTable()[i][j];
            }
        }
        if(i!=csvfile->getCopyTable().size()-1){
            (*fout)<<"\n";
        }
    }
}