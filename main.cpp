#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "include/FileReaderWriter.h"
#include "include/PLY/PLYFileReaderWriter.h"
#include "include/GDF/GdfFileReaderWriter.h"
#include "include/PPM/PPMFileReaderWriter.h"
#include "include/CSV/csvFileReaderWriter.h"
#include "include/TXT/txtfilereaderwriter.h"

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "Given extra command line arguments.\n";
        std::cerr << "Expected input of format <input-file> <output-file>";
        return -1;
    }
    std::fstream input(argv[1]);
    std::fstream output(argv[2], ios::trunc | ios::in | ios::out);
    FileReaderWriter* obj;
    if ((std::string(argv[1]).find(".ply") != std::string::npos)) {
        obj = new PLYFileReaderWriter();
        obj->setReadFile(&input);
        obj->setWriteFile(&output);
    } else if ((std::string(argv[1]).find(".gdf") != std::string::npos)) {
        obj = new GdfFileReaderWriter();
        obj->setReadFile(&input);
        obj->setWriteFile(&output);
    } else if ((std::string(argv[1]).find(".ppm") != std::string::npos)) {
        obj = new PPMFileReaderWriter();
        obj->setReadFile(&input);
        obj->setWriteFile(&output);
    } else if ((std::string(argv[1]).find(".csv") != std::string::npos)) {
        obj = new csvFileReaderWriter();
        obj->setReadFile(&input);
        obj->setWriteFile(&output);
    } else if ((std::string(argv[1]).find(".txt") != std::string::npos)) {
        obj = new txtfilereaderwriter(argv[1]);
        obj->setReadFile(&input);
        obj->setWriteFile(&output);
    }
    try {
        obj->read();
    } catch (const char* e) {
        std::cout << e << std::endl;
    }
    obj->process();
    obj->write();
}