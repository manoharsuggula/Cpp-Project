//
// Created by SRI RAM on 21-11-2020.
//

#ifndef PROJECT_GDFFILEWRITER_H
#define PROJECT_GDFFILEWRITER_H

#include "../FileWriter.h"

class GdfFileWriter: public FileWriter {
public:
    GdfFileWriter(std::fstream *o);

    virtual void write(void *pVoid);

};


#endif //PROJECT_GDFFILEWRITER_H
