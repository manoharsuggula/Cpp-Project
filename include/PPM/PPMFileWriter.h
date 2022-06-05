#ifndef FILEWRITER_H
#define FILEWRITER_H

#include "../FileWriter.h"
#include "../../include/PPM/PPM.h"
#include<fstream>


class PPMFileWriter : public FileWriter
{
    public:
    PPMFileWriter();
    PPMFileWriter(std::fstream*);
    virtual void write(void*);
};

#endif