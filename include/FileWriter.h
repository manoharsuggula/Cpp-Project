#pragma once

#include <iostream>
#include <fstream>
#include <sstream>

class FileWriter {
private:
    std::fstream* _writeFile;

public:
    FileWriter();
    FileWriter(std::fstream* o);
    virtual ~FileWriter();

    virtual void write(void*) = 0;
    std::fstream* writeFile();
};