#pragma once

#include "../FileReaderWriter.h"
#include "PLYFileReader.h"
#include "PLYFileWriter.h"

class PLYFileReaderWriter: public FileReaderWriter {
private:
public:
    PLYFileReaderWriter();

    virtual void setReadFile(std::fstream* o);
    virtual void setWriteFile(std::fstream* o);
    virtual void process();
};