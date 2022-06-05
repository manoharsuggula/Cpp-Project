#include "../include/FileReaderWriter.h"

FileReaderWriter::FileReaderWriter() {};

FileReaderWriter::~FileReaderWriter() {}

void FileReaderWriter::read() {
    _object = _reader->read();
}

void FileReaderWriter::write() {
    _writer->write(_object);
}

FileReader* FileReaderWriter::reader() {
    return _reader;
}

FileWriter* FileReaderWriter::writer() {
    return _writer;
}

void* FileReaderWriter::object() {
    return _object;
}

void FileReaderWriter::setWriter(FileWriter* o) {
    _writer = o;
}

void FileReaderWriter::setReader(FileReader* o) {
    _reader = o;
}