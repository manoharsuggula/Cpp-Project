#pragma once

#include "FileReader.h"
#include "FileWriter.h"

class FileReaderWriter {
private:
    FileReader* _reader;
    FileWriter* _writer;
    void* _object;

public:
    FileReaderWriter();
    virtual ~FileReaderWriter();
    
    virtual void setReadFile(std::fstream* o) = 0;
    virtual void setWriteFile(std::fstream* o) = 0;
    virtual void process() = 0;

    FileReader* reader();
    FileWriter* writer();
    void* object();
    void setReader(FileReader*);
    void setWriter(FileWriter*);
    void setObject(void*);

    void read();
    void write();
};