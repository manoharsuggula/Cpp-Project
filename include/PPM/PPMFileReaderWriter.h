#ifndef PPPMFILEREADERWRITER_H
#define PPPMFILEREADERWRITER_H

#include "../FileReaderWriter.h"
#include "../../include/PPM/PPM.h"
#include "PPMFileReader.h"
#include "PPMFileWriter.h"
#include<fstream>

class PPMFileReaderWriter : public FileReaderWriter
{
    public:
    PPMFileReaderWriter();
    virtual ~PPMFileReaderWriter();
    virtual void setReadFile(std::fstream* o);
    virtual void setWriteFile(std::fstream* o);
    virtual void process();
};

#endif