#include <iostream>
#include <fstream>
#include "../../include/TXT/txtfilereaderwriter.h"

txtfilereaderwriter::txtfilereaderwriter(char* fileName)
: FileReaderWriter() {
    _fileName = fileName;
}

txtfilereaderwriter::~txtfilereaderwriter() {}

void txtfilereaderwriter::setReadFile(std::fstream* o) {
    setReader(new txtfilereader(o));
}

void txtfilereaderwriter::setWriteFile(std::fstream* o) {
    txtfilewriter* writer = new txtfilewriter(o);
    writer->setInpFileName(_fileName);
    setWriter(writer);
}

void txtfilereaderwriter::process() {}
