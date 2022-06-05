#include "../../include/CSV/csvFileReaderWriter.h"
#include"../../include/CSV/csv.h"

csvFileReaderWriter::csvFileReaderWriter() {}

csvFileReaderWriter::~csvFileReaderWriter(){
    delete (csv*)object();
}
void csvFileReaderWriter::setReadFile(std::fstream *o){
    csvFileReader *reader = new csvFileReader(o);
    setReader(reader);
}

void csvFileReaderWriter::setWriteFile(std::fstream *o){
    csvFileWriter *writer = new csvFileWriter(o);
    setWriter(writer);
}

void csvFileReaderWriter::process(){
    csv *csvfile = (csv*)object();
    vector<vector<string>> TransposeTable;
    int max=csvfile->getTable()[0].size();
    for(int i=0;i<csvfile->getTable().size();i++){
        if(max<csvfile->getTable()[i].size()){
            max = csvfile->getTable()[i].size();
        }
    }
    for(int i=0;i<max;i++){
        vector<string> str;
        TransposeTable.push_back(str);
    }
    for(int i=0;i<csvfile->getTable().size();i++){
        for(int j=0;j<csvfile->getTable()[i].size();j++)
        {
            TransposeTable[j].push_back(csvfile->getTable()[i][j]);
        }
    }
    
    csvfile->setCopyTable(TransposeTable);
}