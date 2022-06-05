#ifndef PPMFILEREADER_H
#define PPMFILEREADER_H

#include "../FileReader.h"
#include <string>
#include<iostream>
#include<fstream>
#include<vector>
#include "../../include/PPM/PPM.h"

class PPMFileReader : public FileReader
{
    private:

    public:
    PPMFileReader();
    PPMFileReader(std::fstream* o);
    virtual void* read();
};

#endif