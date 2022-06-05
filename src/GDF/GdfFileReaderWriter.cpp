//
// Created by SRI RAM on 21-11-2020.
//

#include "../../include/GDF/GdfFileReaderWriter.h"
#include "../../include/GDF/GdfFileReader.h"
#include "../../include/GDF/GdfFileWriter.h"

void GdfFileReaderWriter::setReadFile(std::fstream *o) {
    setReader(new GdfFileReader(o));
}

void GdfFileReaderWriter::setWriteFile(std::fstream *o) {
    setWriter(new GdfFileWriter(o));
}

void GdfFileReaderWriter::process() {}
