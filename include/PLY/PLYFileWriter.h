#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

#include "../FileWriter.h"
#include "PLYObject.h"

class PLYFileWriter: public FileWriter {
private:
public:
    PLYFileWriter();
    PLYFileWriter(std::fstream* o);
    virtual ~PLYFileWriter();

    virtual void write(void*);
};