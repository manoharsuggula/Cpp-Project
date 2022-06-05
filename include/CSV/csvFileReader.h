#include "../FileReader.h"
class csvFileReader: public FileReader{
    public:
        csvFileReader();
        csvFileReader(std::fstream* o);
        void* read();
};