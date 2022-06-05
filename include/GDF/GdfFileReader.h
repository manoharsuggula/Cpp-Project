//
// Created by SRI RAM on 21-11-2020.
//

#ifndef PROJECT_GDFFILEREADER_H
#define PROJECT_GDFFILEREADER_H
#include "../FileReader.h"

class GdfFileReader: public FileReader {
public:
    GdfFileReader(std::fstream *o);

    virtual void *read();
};


#endif //PROJECT_GDFFILEREADER_H
