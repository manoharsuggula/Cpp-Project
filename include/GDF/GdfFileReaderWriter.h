//
// Created by SRI RAM on 21-11-2020.
//

#ifndef PROJECT_GDFFILEREADERWRITER_H
#define PROJECT_GDFFILEREADERWRITER_H

#include "../FileReaderWriter.h"

class GdfFileReaderWriter: public FileReaderWriter {

public:
    virtual void setReadFile(std::fstream *o);

    virtual void setWriteFile(std::fstream *o);

    virtual void process();
};


#endif //PROJECT_GDFFILEREADERWRITER_H
