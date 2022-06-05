#include <iostream>
#include "../FileReader.h"
// #include "variables.h"

class txtfilereader : public FileReader{
public:
    void* read();
    txtfilereader(std::fstream* o);
};
