#include "../include/FileReader.h"

FileReader::FileReader() {}

FileReader::FileReader(std::fstream* o)
: _readFile(o) {}

FileReader::~FileReader() {
    _readFile->close();
}

std::fstream* FileReader::readFile() {
    return _readFile;
}