#include "../../include/PLY/PLYFileReaderWriter.h"

PLYFileReaderWriter::PLYFileReaderWriter()
: FileReaderWriter() {}

void PLYFileReaderWriter::setReadFile(std::fstream* o) {
    PLYFileReader* reader = new PLYFileReader(o);
    setReader(reader);
}

void PLYFileReaderWriter::setWriteFile(std::fstream* o) {
    PLYFileWriter* writer = new PLYFileWriter(o);
    setWriter(writer);
}

void PLYFileReaderWriter::process() {
    PLYObject* obj = (PLYObject*)object();
    obj->process();
}