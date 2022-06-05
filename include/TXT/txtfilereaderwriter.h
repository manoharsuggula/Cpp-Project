#include <iostream>
#include "../FileReaderWriter.h"
#include "txtfilereader.h"
#include "txtfilewriter.h"

class txtfilereaderwriter : public FileReaderWriter{
private:
    char* _fileName;
public:
    txtfilereaderwriter(char*);
    virtual ~txtfilereaderwriter();
    virtual void setReadFile(std::fstream* o);
    virtual void setWriteFile(std::fstream* o);
    virtual void process();
};
