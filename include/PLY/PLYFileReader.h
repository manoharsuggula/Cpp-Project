#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

#include "../FileReader.h"
#include "PLYObject.h"

class PLYFileReader: public FileReader {
private:
    std::vector<std::vector<std::string>> _instructions;
    PLYObject* _getPLYObject();

public:
    PLYFileReader();
    PLYFileReader(std::fstream* o);
    virtual ~PLYFileReader();

    virtual void* read();
};