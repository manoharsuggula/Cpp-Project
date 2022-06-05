#include "../include/FileWriter.h"

FileWriter::FileWriter() {}

FileWriter::FileWriter(std::fstream* o)
: _writeFile(o) {}

FileWriter::~FileWriter() {
    _writeFile->close();
}

std::fstream* FileWriter::writeFile() {
    return _writeFile;
}