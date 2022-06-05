#include <iostream>
#include "../FileWriter.h"
// #include "variables.h"

class txtfilewriter : public FileWriter {
private:
    char* _inpFileName;
public:
    void write(void*);
    txtfilewriter(std::fstream* o);
    
    void setInpFileName(char*);
};
