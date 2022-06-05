#pragma once

#include <iostream>
#include <fstream>
#include <sstream>

class FileReader {
private:
    std::fstream* _readFile;

public:
    FileReader();
    FileReader(std::fstream* o);
    virtual ~FileReader();

    virtual void* read() = 0;
    std::fstream* readFile();
};